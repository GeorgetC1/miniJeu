#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

class ConfigParser
{
public:
	ConfigParser(const string nomFichier);
	~ConfigParser() {}

	//getteur
	const unordered_map<string, unordered_map<string, string>> getMap();

	string getValeur(const string& categorie, const string& cle, string defaut="0") const;

	// fonction lecture et parsing fichier
	bool parseFichier();

private:
	string m_nomFichier;
	unordered_map<string, unordered_map<string, string>> m_configMap;
};

