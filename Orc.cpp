#include "Orc.h"

Orc::Orc(std::string nom) : Personnage(nom, 60, 0, 0, Arme("Hache", 8), "stun")
{
}

void Orc::capaciteSpeciale(Personnage& cible)
{
    // V�rifier si la capacit� sp�ciale peut �tre utilis�e
    if (m_tpsRecuperation > 0) {
        std::cout << "La capacite STUN est en attente. Attendez encore " << m_tpsRecuperation << " tours." << std::endl;
    }
    else {
        // G�n�rer un nombre al�atoire entre 0 et 99 (pourcentage)
        int chanceReussite = rand() % 100;

        if (chanceReussite < 20) {  // La capacit� r�ussit avec 20% de chance
            std::cout << "La capacite STUN a touche son adversaire." << std::endl;
            cible.changerEtat(Etat::ETOURDI);
            std::cout << cible.getNom() << " est etourdi et ne plus attaquer pendant ce tour." << std::endl;
        }
        else {
            std::cout << "Oh non ! La capacite STUN a rate." << std::endl;
            m_tpsRecuperation = 5;
        }
    }

}