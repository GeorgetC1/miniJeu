#include "Arme.h"

Arme::Arme(std::string nom, int degats) : m_nom(nom), m_degats(degats)
{
}

Arme::Arme(const Arme& armeCopie) : m_nom(armeCopie.m_nom), m_degats(armeCopie.m_degats)
{
}

int Arme::getDegats()
{
    return m_degats;
}