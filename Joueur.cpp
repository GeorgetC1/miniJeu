#include "Joueur.h"

Joueur::Joueur(std::string pseudo) : m_pseudo(pseudo), m_personnage(nullptr)
{
}

Joueur::~Joueur()
{
    delete m_personnage;
}

void Joueur::choisirPersonnage()
{
    std::cout << std::endl << m_pseudo << ", choisissez votre personnage :\n1. Orc\n2. Chevalier" << std::endl;
    int choixPersonnage;
    std::cin >> choixPersonnage;

    if (choixPersonnage == 1) {
        m_personnage = new Orc(m_pseudo + " ( Orc )");
    }
    else {
        m_personnage = new Chevalier(m_pseudo + " ( Chevalier )");
    }
}

void Joueur::jouerTour(Joueur& adversaire)
{
    std::cout << std::endl;
    if (m_personnage != nullptr) {

        if (this->peutJouer())
        {
            std::cout << m_pseudo << ", voulez-vous utiliser votre capacite speciale ? (1. Oui / 2. Non)" << std::endl;
            int choixUtiliserCapacite;
            std::cin >> choixUtiliserCapacite;

            if (choixUtiliserCapacite == 1) {
                m_personnage->capaciteSpeciale(*adversaire.m_personnage);
            }
        }
        else
        {
            if (this->estVivant())
            {
                std::cout << m_pseudo << " n'est pas en etat de lancer sa capacite speciale." << std::endl;
                std::cout << "Attendre encore " << m_personnage->getTpsRecup() << " tours." << std::endl;
            }
            else
            {
                std::cout << m_pseudo << " est mort." << std::endl;
            }

        }
    }
}

void Joueur::attaque(Joueur& adversaire)
{
    m_personnage->attaquer(*adversaire.m_personnage);
}

void Joueur::afficheEtat()
{
    std::cout << "Etat du Joueur : " << m_personnage->getNom() << " (PV : " << m_personnage->getPV() << " | Bouclier : "<< m_personnage->getBouclier() << ")" << std::endl;
}

void Joueur::majPerso()
{
    m_personnage->changerEtat(Etat::NORMAL);
    m_personnage->passeUnTour();
}

bool Joueur::peutJouer()
{
    return (m_personnage->getEtat() == Etat::NORMAL) && (m_personnage->getTpsRecup() == 0);
}

bool Joueur::estVivant()
{
    return (m_personnage->getPV() > 0);
}