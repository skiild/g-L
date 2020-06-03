#ifndef CATALOGUE
#define CATALOGUE
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>
#include "Capteur.h"
using namespace std;
class Catalogue {
public:
	static list<Capteur> rechercherCapteursSimilaires(Capteur c, time_t debut, time_t fin);
	static int rechercherQualiteTerritoire(float r, float lon, float lat);
	static int rechercherQualiteMoyenne(float r = NULL, float lon = NULL, float lat = NULL);
	static list<Capteur> chercherCapteursDefectueux();
	static list<Mesure> afficherMesures(Capteur c);
	static list<Capteur>afficherCapteurs();
	static void ajouterCapteur(Capteur c);
	static void ajouterMesure(Capteur c, Mesure m);
private:
	static list<Capteur> capteur;
	static struct CalculMoy { int compteur = 0; float valeur = 0; vector<float> palier; int indice = 10; };
	static int pireIndice(vector<CalculMoy> stats);
};

#endif // !CATALOGUE
