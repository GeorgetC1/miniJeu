#include "ConfigParser.h"

ConfigParser::ConfigParser(const string nomFichier) : m_nomFichier(nomFichier)
{
}

const unordered_map<string, unordered_map<string, string>> ConfigParser::getMap()
{
    return m_configMap;
}

string ConfigParser::getValeur(const string& categorie, const string& cle, string defaut) const {
    if (m_configMap.count(categorie) && m_configMap.at(categorie).count(cle)) {
        return m_configMap.at(categorie).at(cle);
    }
    return defaut;
}

void ConfigParser::parseFichier()
{
    ifstream fichier(m_nomFichier);
    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier de configuration." << endl;
        return;
    }

    string ligne;
    string categorie;
    while (getline(fichier, ligne)) {
        if (ligne.empty() || ligne[0] == '#') {
            continue; // Ignorer les lignes vides et les commentaires
        }
        else if (ligne[0] == '[' && ligne.back() == ']') {
            categorie = ligne.substr(1, ligne.size() - 2); // Extraire le nom de la catégorie
            m_configMap[categorie] = unordered_map<string, string>();
        }
        else {
            size_t pos = ligne.find('=');
            if (pos != string::npos) {
                string cle = ligne.substr(0, pos);
                string valeur = ligne.substr(pos + 1);
                m_configMap[categorie][cle] = valeur;
            }
        }
    }
}
