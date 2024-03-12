#pragma once
/* CLASSE ARME
* 
* Classe permettant de cr�er les armes du jeu
* l'arme est d�fini par un nom et des d�gats 
*(qui seront ajout�s aux d�gats de base des personnages)
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

