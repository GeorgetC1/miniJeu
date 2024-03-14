#pragma once

/* CLASSE PERSONNAGE
*
* Classe permettant de créer les personnages du jeu.
* Chaque personnage possède: des PV , un bouclier, une capacité spéciale,
* un etat (étourdi / normal / empoisonné par exemple).
* Le personnage prendra le nom défini par l'utilisateur ("ordinateur" par défaut)
*
*/

#include <string>
#include <iostream>
#include "..\Items\Arme.h"
#include "..\Parser\ConfigParser.h"

using namespace std;

// Enum pour représenter les états possibles du personnage
enum class Etat {
	NORMAL,
	ETOURDI,
	EMPOISONNE,
	// Ajoutez d'autres états au besoin
};

class Personnage
{

public : 
	Personnage(string nom, string typePerso, const ConfigParser& cfgPerso, const ConfigParser& cfgArmes);
	Personnage(	string nom, 
				int pv, 
				int bouclier, 
				int degats,
				Arme arme,
				string capaciteSpe, 
				int pourcentageReussite, 
				int paramTpsRecup);
	~Personnage() {}

	// etat et stats
	void changerEtat(Etat newEtat);

	// getteur
	const string getNom();
	const int getTpsRecup();
	const int getPV();
	const int getBouclier();
	const Etat getEtat();
	const string getNomCapacite();

	// fonction qui gère ce qui doit être fait à chaque tour (compteur ...)
	void passeUnTour();

	// Combat
	void attaquer(Personnage& cible); 
	void recevoirDegats(int degats);

	// capacite speciale
	virtual void capaciteSpeciale(Personnage& cible);
	virtual void appliquerCapacite(Personnage& cible) = 0;// à définir dans chaque classe enfant

private :

	string m_nom; // désignation du personnage
	int m_pv; // points de vie
	int m_bouclier; 
	int m_degats; 
	Arme m_arme;
	Etat m_etat;
	string m_capaciteSpeciale; // nom de la capacité spéciale
	int m_pourcentageReussite; // chance de reussite fixe lié au personnage , défini par paramétrage
	int m_paramTpsRecup; // nbr tour de récupération fixe défini par paramétrage
	int m_tpsRecuperation; // tour de récupération de la capacité spéciale dynamique

protected :	
	int m_multiplicateur; // multiplicateur de dégats: sert de buff temporaire pour les personnages

};

