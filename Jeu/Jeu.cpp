#include "Jeu.h"
using namespace std;

// fonction d'affichage des personnages et de leurs caractéristiques
void afficherDetailPerso(ConfigParser& prPersos, ConfigParser& prArmes)
{

	const unordered_map<string, unordered_map<string, string>> persoMap = prPersos.getMap();
	cout << "Les personnages disponibles :" << endl;
	cout << "STATS" << endl;
	for (const auto& pair : persoMap) {
		const string& categorie = pair.first;
		const unordered_map<string, string>& stats = pair.second;
		cout << "[" << categorie << "]" << endl;
		cout << "PV: " << stats.at("PV")<< endl;
		cout << "BOUCLIER: " << stats.at("BOUCLIER") << endl;
		cout << "DEGATS: " << stats.at("DEGATS") << endl;
		cout << "ARME: " << stats.at("ARME") << endl;
		cout << "DEGAT ARME: " << prArmes.getValeur(stats.at("ARME"),"DEGATS") << endl;
		cout << "CAPACITE: " << stats.at("CAPACITE")<< endl;
		cout << "->DESCR: " << stats.at("DESCRIPTION_CAPACITE") << endl;
		cout << "->CHANCE DE REUSSITE: " << stats.at("POURCENTAGE_REUSSITE") << "%" << endl;
		cout << "->TOUR DE RECUPERATION: " << stats.at("TPS_RECUPERATION") << endl;
		cout << "----------------------------------------------------" << endl;
	}
}

// Fonction du déroulement des combats
void combat(Joueur& joueur1, Joueur& joueur2)
{
	int tour = 1;
	while (joueur1.estVivant() && joueur2.estVivant())
	{
		system("CLS");
		cout << "####################################" << endl;
		cout << "#              COMBAT              #" << endl;
		cout << "####################################" << endl << endl;
		cout << "               TOUR " << tour << endl << endl;
		cout << "####################################" << endl;

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

		tour++;
	}
}

// affiche le gagnant
void afficherVictoire(Joueur& joueur1, Joueur& joueur2)
{
	system("CLS");
	string gagnant;
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
	// lecture des fichiers de paramétrages
	ConfigParser paramArmes("paramArmes.txt");
	bool fichierArmesOk = paramArmes.parseFichier();
	ConfigParser paramPersos("paramPersos.txt");
	bool fichierPersosOk = paramPersos.parseFichier();

	if (!fichierArmesOk || !fichierPersosOk)
	{
		cout << endl << "Merci de verifier que votre fichier "<< (fichierArmesOk? "paramPersos.txt":"paramArmes.txt") << " est present et conforme.\nL'application va s'arreter." << endl << endl;
		system("PAUSE");
		exit(0);
	}

	// initialisation de var
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
	afficherDetailPerso(paramPersos, paramArmes);

	// choix des joueurs
	Joueur joueur1 = Joueur(pseudoJoueur1, paramPersos, paramArmes);
	Joueur joueur2 = Joueur(pseudoJoueur2, paramPersos, paramArmes, (nbrJoueur == 1));

	joueur1.choisirPersonnage();
	joueur2.choisirPersonnage();

	// combat
	combat(joueur1, joueur2);

	// victoire
	afficherVictoire(joueur1, joueur2);
}

