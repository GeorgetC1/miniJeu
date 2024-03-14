#include "Orc.h"

Orc::Orc(std::string nom, const ConfigParser& cfgPerso, const ConfigParser& cfgArmes)
    : Personnage(nom, "ORC", cfgPerso, cfgArmes)
{
}

void Orc::appliquerCapacite(Personnage& cible)
{
    std::cout << "La capacite " << this->getNomCapacite() << " a touche son adversaire." << std::endl;
    cible.changerEtat(Etat::ETOURDI);
    std::cout << cible.getNom() << " est etourdi et ne plus attaquer pendant ce tour." << std::endl;
}