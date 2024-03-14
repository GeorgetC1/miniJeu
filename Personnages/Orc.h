#pragma once
#include "Personnage.h"

class Orc : public Personnage
{
public:
	Orc(std::string nom, const ConfigParser& cfgPerso, const ConfigParser& cfgArmes);

	void appliquerCapacite(Personnage& cible);

private:

};

