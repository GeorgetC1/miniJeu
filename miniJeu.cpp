// miniJeu.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Jeu/Jeu.h"
using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));// démarrage nbr aléatoire

    bool quitter = false; 
    int choix = 0;

    while (!quitter)
    {
        system("CLS");
        cout << "####################################" << endl;
        cout << "#              THE GAME            #" << endl;
        cout << "####################################" << endl;

        cout << "1. 1 Joueur" << endl;
        cout << "2. 2 Joueurs" << endl;
        cout << "3. Quitter" << endl;

        cout << endl << "Votre choix : ";
        cin >> choix;
        switch (choix)
        {
            case 1 :
            case 2 :
                jouer(choix);
                break;
            case 3 :
                quitter = true;
                break;
            default :
                choix = 0;
                break;
        }
    }

    return 0;
}