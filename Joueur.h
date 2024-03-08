#pragma once

#include <iostream>
#include "Orc.h"
#include "Chevalier.h"

class Joueur
{
public:
    Joueur(std::string pseudo);
    ~Joueur();

    // init
    void choisirPersonnage();

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
};

