#include "Personnage.h"

Personnage::Personnage(std::string nom, int pv, int bouclier, int degats, Arme arme, std::string capaciteSpe)
    : m_nom(nom), m_pv(pv), m_bouclier(bouclier), m_degats(degats), m_arme(arme), m_etat(Etat::NORMAL), m_capaciteSpeciale(capaciteSpe), m_multiplicateur(1), m_tpsRecuperation(0)
{
}

const std::string Personnage::getNom()
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

        std::cout << m_nom << " attaque et inflige " << degats << " degats." << std::endl;
        break;
    case Etat::ETOURDI:
        std::cout << m_nom << " ne pas attaquer car il est étourdi." << std::endl;
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
