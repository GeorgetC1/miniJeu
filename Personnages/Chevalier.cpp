#include "Chevalier.h"

Chevalier::Chevalier(std::string nom) : Personnage(nom + " ( Chevalier )", 20, 50, 0, Arme("Épée", 5), "CHARGE")
{
}

void Chevalier::appliquerCapacite(Personnage& cible)
{
    std::cout << "La capacite " << this->getNomCapacite() << " a reussi." << std::endl;
    m_multiplicateur = 2;
    std::cout << this->getNom() << " infligera 2 fois ses degats a " << cible.getNom() << " ." << std::endl;
}