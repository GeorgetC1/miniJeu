#include "Personnage.h"

Personnage::Personnage(string nom, string typePerso, const ConfigParser& cfgPerso, const ConfigParser& cfgArmes)
{
    m_nom = nom+" ("+typePerso+")";
    m_pv = stoi(cfgPerso.getValeur(typePerso, "PV"));
    m_bouclier = stoi(cfgPerso.getValeur(typePerso, "BOUCLIER"));
    m_degats = stoi(cfgPerso.getValeur(typePerso, "DEGATS"));

    string armeStr = cfgPerso.getValeur(typePerso, "ARME");
    m_arme = Arme(armeStr, stoi(cfgArmes.getValeur(armeStr, "DEGATS")));

    m_etat = Etat::NORMAL;
    m_capaciteSpeciale = cfgPerso.getValeur(typePerso, "CAPACITE");
    m_multiplicateur = stoi(cfgPerso.getValeur(typePerso, "MULTIPLICATEUR"));
    m_paramTpsRecup= stoi(cfgPerso.getValeur(typePerso, "TPS_RECUPERATION"));
    m_pourcentageReussite = stoi(cfgPerso.getValeur(typePerso, "POURCENTAGE_REUSSITE"));
    m_tpsRecuperation = 0;
}

Personnage::Personnage(string nom, int pv, int bouclier, int degats, Arme arme, string capaciteSpe, int pourcentageReussite, int paramTpsRecup)
    : m_nom(nom), 
    m_pv(pv), 
    m_bouclier(bouclier), 
    m_degats(degats), 
    m_arme(arme), 
    m_etat(Etat::NORMAL), 
    m_capaciteSpeciale(capaciteSpe),
    m_multiplicateur(1), 
    m_tpsRecuperation(0), 
    m_paramTpsRecup(0), 
    m_pourcentageReussite(0)
{
}

const string Personnage::getNom()
{
    return m_nom;
}

void Personnage::changerEtat(Etat nouvelEtat)
{
    m_etat = nouvelEtat;
}

const int Personnage::getTpsRecup()
{
    return m_tpsRecuperation;
}

const int Personnage::getPV()
{
    return m_pv;
}

const int Personnage::getBouclier()
{
    return m_bouclier;
}

const Etat Personnage::getEtat()
{
    return m_etat;
}

const string Personnage::getNomCapacite()
{
    return m_capaciteSpeciale;
}

// fonction qui gère ce qui doit être fait à chaque tour (compteur ...)
void Personnage::passeUnTour()
{
    if(m_tpsRecuperation > 0)
        m_tpsRecuperation--;

    m_multiplicateur = 1;
}

void Personnage::attaquer(Personnage& cible)
{
    int degats = m_arme.getDegats() + m_degats;
    switch (m_etat)
    {
    case Etat::NORMAL:
        
        degats *= m_multiplicateur; // si le personnage est sous un buff

        cible.recevoirDegats(degats);

        cout << m_nom << " attaque et inflige " << degats << " degats." << endl;
        break;
    case Etat::ETOURDI:
        cout << m_nom << " ne pas attaquer car il est etourdi." << endl;
        break;
    case Etat::EMPOISONNE:
        break;
    default:
        break;
    }
}

void Personnage::recevoirDegats(int degats)
{
    if (m_bouclier > 0)
    {
        m_bouclier -= degats;

        if (m_bouclier < 0) // on a infligé plus de dégats que le bouclier
        {
            m_pv += m_bouclier; // on répartit le reste des dégats sur les points de vie
            m_bouclier = 0;
        }
    }
    else // il n'y a plus de bouclier
    {
        m_pv -= degats;

        if (m_pv < 0)
        {
            m_pv = 0;
        }
    }
}

void Personnage::capaciteSpeciale(Personnage& cible)
{
    // Vérifier si la capacité spéciale peut être utilisée
    if (m_tpsRecuperation > 0) {
        cout << "La capacite " << m_capaciteSpeciale << " est en attente. Attendez encore " << m_tpsRecuperation << " tours." << endl;
    }
    else {
        // Générer un nombre aléatoire entre 0 et 99 (pourcentage)
        int chanceReussite = rand() % 100;

        if (chanceReussite < m_pourcentageReussite) {  // La capacité réussit avec 60% de chance
            appliquerCapacite(cible);
        }
        else {
            cout << "CATASTROPHE ! La capacite "<<m_capaciteSpeciale<<" a echoue." << endl;
            m_tpsRecuperation = m_paramTpsRecup;
        }
    }
}
