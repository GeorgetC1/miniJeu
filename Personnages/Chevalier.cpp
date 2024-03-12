#include "Chevalier.h"

Chevalier::Chevalier(std::string nom) : Personnage(nom, 20, 50, 0, Arme("Épée", 5), "CHARGE")
{
}

void Chevalier::capaciteSpeciale(Personnage& cible)
{
    // Vérifier si la capacité spéciale peut être utilisée
    if (m_tpsRecuperation > 0) {
        std::cout << "La capacite CHARGE est en attente. Attendez encore " << m_tpsRecuperation << " tours." << std::endl;
    }
    else {
        // Générer un nombre aléatoire entre 0 et 99 (pourcentage)
        int chanceReussite = rand() % 100;

        if (chanceReussite < 60) {  // La capacité réussit avec 60% de chance
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