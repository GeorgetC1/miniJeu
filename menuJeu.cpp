#include "menuJeu.h"
using namespace std;

void menuJeu(int nbrJoueur)
{
	string pseudoJoueur1, pseudoJoueur2;
	int choixJ1 = 0, choixJ2 = 0;

	system("CLS");
	cout << "Joueur 1 entrez votre pseudo : ";
	cin >> pseudoJoueur1;
	cout << endl;

	if (nbrJoueur == 2)
	{
		cout << "Joueur 2 entrez votre pseudo : ";
		cin >> pseudoJoueur2;
		cout << endl;

		system("CLS");
		cout << "####################################" << endl;
		cout << "#       MODE DE JEU 2 JOUEURS      #" << endl;
		cout << "####################################" << endl;
	}
	else
	{
		pseudoJoueur2 = "Ordinateur";

		system("CLS");
		cout << "####################################" << endl;
		cout << "#       MODE DE JEU 1 JOUEUR       #" << endl;
		cout << "####################################" << endl;
	}

	cout << "Les personnages disponibles :" << endl;
	cout << "STATS       |  PV   | BOUCLIER | DEGATS | CAPACITE  " << endl;
	cout << "ORC  >------|  60   |     0    |    8   |   STUN    " << endl;
	cout << "CHEVALIER >-|  20   |    50    |    5   |   CHARGE  " << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "CapaciteSpe.|                         Description                              | COOLDOWN (si Echec)" << endl;
	cout << "STUN   >----| etourdi l'ennemi pour 1 tour (chance reussite: 20%)              |  5 tours" << endl;
	cout << "CHARGE >----| inflique le double des dégats pour 1 tour (chance reussite: 60%) |  3 tours" << endl << endl;

	Joueur joueur1 = Joueur(pseudoJoueur1);
	Joueur joueur2 = Joueur(pseudoJoueur2);

	joueur1.choisirPersonnage();
	joueur2.choisirPersonnage();

	while (joueur1.estVivant() && joueur2.estVivant())
	{
		system("CLS");
		cout << "####################################" << endl;
		cout << "#              COMBAT              #" << endl;
		cout << "####################################" << endl << endl;
	
		// début tour / capacité spécial
		joueur1.jouerTour(joueur2);
		joueur2.jouerTour(joueur1);

		cout << endl;

		// combat
		joueur1.attaque(joueur2);
		joueur2.attaque(joueur1);

		cout << endl;

		// combat
		joueur1.afficheEtat();
		joueur2.afficheEtat();

		cout << endl;

		// fin de tour 
		joueur1.majPerso();
		joueur2.majPerso();
		system("PAUSE");
	}


	system("CLS");
	cout << endl << (joueur1.estVivant() ? pseudoJoueur1 : pseudoJoueur2) << " a gagne cette partie." << endl << endl;
	system("PAUSE");

}