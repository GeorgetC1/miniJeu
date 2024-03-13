#include "Orc.h"

Orc::Orc(std::string nom) : Personnage(nom + " ( Orc )", 60, 0, 0, Arme("Hache", 8), "stun")
{
}

void Orc::capaciteSpeciale(Personnage& cible)
{
    std::cout << "La capacite STUN a touche son adversaire." << std::endl;
    cible.changerEtat(Etat::ETOURDI);
    std::cout << cible.getNom() << " est etourdi et ne plus attaquer pendant ce tour." << std::endl;
}