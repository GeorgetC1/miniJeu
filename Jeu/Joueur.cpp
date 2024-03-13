#include "Joueur.h"

Joueur::Joueur(std::string pseudo, bool estOrdinateur) : m_pseudo(pseudo), m_personnage(nullptr), m_estOrdinateur(estOrdinateur)
{
}

Joueur::~Joueur()
{
    delete m_personnage;
}

void Joueur::choisirPersonnage()
{
    int choixPersonnage = 0;
    if (m_estOrdinateur == true)
    {
        std::cout << std::endl << "Qui souhaitez-vous affronter ?\n1.Orc\n2.Chevalier" << std::endl;
    }
    else
    {
        std::cout << std::endl << m_pseudo << ", choisissez votre personnage :\n1. Orc\n2. Chevalier" << std::endl;        
    }

    std::cin >> choixPersonnage;

    switch (choixPersonnage)
    {
        case 1 :
            m_personnage = new Orc(m_pseudo);
            std::cout << std::endl << m_personnage->getNom() << " choisi." << std::endl;
            break;
        case 2 :
            m_personnage = new Chevalier(m_pseudo);
            std::cout << std::endl << m_personnage->getNom() << " choisi." << std::endl;
            break;
        default :
            std::cout << std::endl << "Choix non disponible!" << std::endl;
            this->choisirPersonnage();
    }   
}

const std::string Joueur::getPseudo()
{
    return m_pseudo;
}

void Joueur::jouerTour(Joueur& adversaire)
{
    std::cout << std::endl;
    if (m_personnage != nullptr) {

        if (this->peutJouer())
        {
            int choixUtiliserCapacite;
            if (m_estOrdinateur) // l'ordinateur choisi de façon aléatoire
            {
                choixUtiliserCapacite = (rand() % 2) + 1;
                if(choixUtiliserCapacite == 1)
                    std::cout << m_pseudo << " a choisi d'utiliser sa capacite speciale." << std::endl;
                else
                    std::cout << m_pseudo << " a choisi de ne pas utiliser sa capacite speciale." << std::endl;
            }
            else
            {
                std::cout << m_pseudo << ", voulez-vous utiliser votre capacite speciale ? (1. Oui / 2. Non)" << std::endl;

                std::cin >> choixUtiliserCapacite;
            }

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