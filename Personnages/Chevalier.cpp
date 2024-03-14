#include "Chevalier.h"

Chevalier::Chevalier(std::string nom, const ConfigParser& cfgPerso, const ConfigParser& cfgArmes) 
    : Personnage(nom, "CHEVALIER", cfgPerso, cfgArmes)
{
}

void Chevalier::appliquerCapacite(Personnage& cible)
{
    std::cout << "La capacite " << this->getNomCapacite() << " a reussi." << std::endl;
    m_multiplicateur = 2;
    std::cout << this->getNom() << " infligera 2 fois ses degats a " << cible.getNom() << " ." << std::endl;
}