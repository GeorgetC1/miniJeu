#include "Orc.h"

Orc::Orc(std::string nom) : Personnage(nom, 60, 0, 0, Arme("Hache", 8), "stun")
{
}

void Orc::capaciteSpeciale()
{
    // V�rifier si la capacit� sp�ciale peut �tre utilis�e
    if (m_tpsRecuperation > 0) {
        std::cout << "La capacit� sp�ciale est en attente. Attendez encore " << m_tpsRecuperation << " tours." << std::endl;
    }
    else {
        // G�n�rer un nombre al�atoire entre 0 et 99 (pourcentage)
        int chanceReussite = rand() % 100;

        if (chanceReussite < 20) {  // La capacit� r�ussit avec 20% de chance
            
        }
        else {
            m_tpsRecuperation = 3;
        }
    }

}