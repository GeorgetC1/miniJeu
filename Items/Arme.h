#pragma once
/* CLASSE ARME
* 
* Classe permettant de créer les armes du jeu
* l'arme est défini par un nom et des dégats 
*(qui seront ajoutés aux dégats de base des personnages)
*
*/

#include <string>

class Arme
{
public :
	Arme(std::string nom, int degats);
	Arme(const Arme &armeCopie);
	int getDegats();

private :
	std::string m_nom;
	int m_degats;
};

