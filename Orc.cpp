#include "Orc.h"

Orc::Orc(std::string nom) : Personnage(nom, 60, 0, 0, Arme("Hache", 8), "stun")
{
}

void Orc::capaciteSpeciale()
{
    // Vérifier si la capacité spéciale peut être utilisée
    if (m_tpsRecuperation > 0) {
        std::cout << "La capacité spéciale est en attente. Attendez encore " << m_tpsRecuperation << " tours." << std::endl;
    }
    else {
        // Générer un nombre aléatoire entre 0 et 99 (pourcentage)
        int chanceReussite = rand() % 100;

        if (chanceReussite < 20) {  // La capacité réussit avec 20% de chance
            
        }
        else {
            m_tpsRecuperation = 3;
        }
    }

}