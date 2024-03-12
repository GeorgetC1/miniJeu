#pragma once

#include <iostream>
#include "..\Personnages\Orc.h"
#include "..\Personnages\Chevalier.h"

class Joueur
{
public:
    Joueur(std::string pseudo, bool estOrdinateur = false);
    ~Joueur();

    // init
    void choisirPersonnage();

    //getteur
    const std::string getPseudo();

    // combat
    void jouerTour(Joueur& adversaire);
    void attaque(Joueur& adversaire);

    // fin tour
    void afficheEtat();
    void majPerso();

    // etat général
    bool peutJouer();
    bool estVivant();

private:
    std::string m_pseudo;
    Personnage* m_personnage;
    bool m_estOrdinateur;
};

