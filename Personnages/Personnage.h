#pragma once

/* CLASSE PERSONNAGE
*
* Classe permettant de cr�er les personnages du jeu.
* Chaque personnage poss�de: des PV , un bouclier, une capacit� sp�ciale,
* un etat (�tourdi / normal / empoisonn� par exemple).
* Le personnage prendra le nom d�fini par l'utilisateur ("ordinateur" par d�faut)
*
*/

#include <string>
#include <iostream>
#include "..\Items\Arme.h"

// Enum pour repr�senter les �tats possibles du personnage
enum class Etat {
	NORMAL,
	ETOURDI,
	EMPOISONNE,
	// Ajoutez d'autres �tats au besoin
};

class Personnage
{

public : 
	Personnage(	std::string nom, 
				int pv, 
				int bouclier, 
				int degats,
				Arme arme,
				std::string capaciteSpe);
	~Personnage() {}

	// etat et stats
	void changerEtat(Etat newEtat);

	// getteur
	const std::string getNom();
	const int getTpsRecup();
	const int getPV();
	const int getBouclier();
	const Etat getEtat();
	const std::string getNomCapacite();

	// fonction qui g�re ce qui doit �tre fait � chaque tour (compteur ...)
	void passeUnTour();

	// Combat
	void attaquer(Personnage& cible); 
	void recevoirDegats(int degats);

	// capacite speciale
	virtual void capaciteSpeciale(Personnage& cible);
	virtual void appliquerCapacite(Personnage& cible) = 0;// � d�finir dans chaque classe enfant

private :

	std::string m_nom; // d�signation du personnage
	int m_pv; // points de vie
	int m_bouclier; 
	int m_degats; 
	Arme m_arme;
	Etat m_etat;
	std::string m_capaciteSpeciale; // nom de la capacit� sp�ciale
	int m_pourcentageReussite;
	int m_paramTpsRecup;

protected :
	int m_tpsRecuperation; // tour de r�cup�ration de la capacit� sp�ciale
	int m_multiplicateur;

};

