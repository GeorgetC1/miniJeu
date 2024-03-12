#include "Jeu.h"
using namespace std;

// fonction d'affichage des personnages et de leurs caractéristiques
void afficherDetailPerso()
{
	cout << "Les personnages disponibles :" << endl;
	cout << "STATS       |  PV   | BOUCLIER | DEGATS | CAPACITE  " << endl;
	cout << "ORC  >------|  60   |     0    |    8   |   STUN    " << endl;
	cout << "CHEVALIER >-|  20   |    50    |    5   |   CHARGE  " << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "CapaciteSpe.|                         Description                              | COOLDOWN (si Echec)" << endl;
	cout << "STUN   >----| etourdi l'ennemi pour 1 tour (chance reussite: 20%)              |  5 tours" << endl;
	cout << "CHARGE >----| inflique le double des dégats pour 1 tour (chance reussite: 60%) |  3 tours" << endl << endl;
}

// Fonction du déroulement des combats
void combat(Joueur& joueur1, Joueur& joueur2)
{
	while (joueur1.estVivant() && joueur2.estVivant())
	{
		system("CLS");
		cout << "####################################" << endl;
		cout << "#              COMBAT              #" << endl;
		cout << "####################################" << endl << endl;

		// début tour / capacité spécial
		joueur1.jouerTour(joueur2);
		joueur2.jouerTour(joueur1);

		system("PAUSE");
		cout << endl;

		// combat
		joueur1.attaque(joueur2);
		joueur2.attaque(joueur1);

		cout << endl;
		system("PAUSE");

		// combat
		joueur1.afficheEtat();
		joueur2.afficheEtat();

		cout << endl;
		system("PAUSE");

		// fin de tour 
		joueur1.majPerso();
		joueur2.majPerso();
	}
}

// affiche le gagnant
void afficherVictoire(Joueur& joueur1, Joueur& joueur2)
{
	system("CLS");
	std::string gagnant;
	if (joueur1.estVivant())
		gagnant = joueur1.getPseudo();
	else if (joueur2.estVivant())
		gagnant = joueur2.getPseudo();

	if (gagnant.empty())
		cout << endl << "EGALITE! Les 2 joueurs sont morts." << endl << endl;
	else
		cout << endl << gagnant << " a gagne cette partie." << endl << endl;
	system("PAUSE");
}

// fonction principale contenant le corps du jeu
void jouer(int nbrJoueur)
{
	string pseudoJoueur1, pseudoJoueur2;
	int choixJ1 = 0, choixJ2 = 0;

	// sélection du mode de jeu
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

	// Affichage des détails des personnages
	afficherDetailPerso();

	// choix des joueurs
	Joueur joueur1 = Joueur(pseudoJoueur1);
	Joueur joueur2 = Joueur(pseudoJoueur2, (nbrJoueur == 1));

	joueur1.choisirPersonnage();
	joueur2.choisirPersonnage();

	// combat
	combat(joueur1, joueur2);

	// victoire
	afficherVictoire(joueur1, joueur2);
}

