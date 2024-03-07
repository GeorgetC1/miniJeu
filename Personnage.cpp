#include "Personnage.h"

Personnage::Personnage(std::string nom, int pv, int bouclier, int degats, Arme arme, std::string capaciteSpe)
    : m_nom(nom), m_pv(pv), m_bouclier(bouclier), m_degats(degats), m_arme(arme), m_etat(NORMAL), m_capaciteSpeciale(capaciteSpe)
{
}

void Personnage::changerEtat(Etat nouvelEtat)
{
    m_etat = nouvelEtat;
}

int Personnage::getTpsRecup()
{
    return m_tpsRecuperation;
}

void Personnage::attaquer(Personnage& cible)
{
    int degats = m_arme.getDegats() + m_degats;
    cible.recevoirDegats(degats);

    std::cout << m_nom << " attaque et inflige " << degats << " degats." << std::endl;
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
