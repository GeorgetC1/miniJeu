#pragma once
#include "Personnage.h"

class Chevalier : public Personnage
{
public : 
	Chevalier(std::string nom);

	void appliquerCapacite(Personnage& cible);

};

