#include "Chevalier.h"

Chevalier::Chevalier(std::string nom) : Personnage(nom, 20, 50, 0, Arme("�p�e", 5), "CHARGE")
{
}

void Chevalier::capaciteSpeciale(Personnage& cible)
{
    // V�rifier si la capacit� sp�ciale peut �tre utilis�e
    if (m_tpsRecuperation > 0) {
        std::cout << "La capacite CHARGE est en attente. Attendez encore " << m_tpsRecuperation << " tours." << std::endl;
    }
    else {
        // G�n�rer un nombre al�atoire entre 0 et 99 (pourcentage)
        int chanceReussite = rand() % 100;

        if (chanceReussite < 60) {  // La capacit� r�ussit avec 60% de chance
            std::cout << "La capacite CHARGE a reussi." << std::endl;
            m_multiplicateur = 2;
            std::cout << this->getNom() << " infligera 2 fois ses degats a " << cible.getNom() << " ." << std::endl;
        }
        else {
            std::cout << "CATASTROPHE ! La capacite CHARGE a echoue." << std::endl;
            m_tpsRecuperation = 3;
        }
    }

}