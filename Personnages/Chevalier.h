#pragma once
#include "Personnage.h"

class Chevalier : public Personnage
{
public : 
	Chevalier(std::string nom, const ConfigParser& cfgPerso, const ConfigParser& cfgArmes);

	void appliquerCapacite(Personnage& cible);

};

