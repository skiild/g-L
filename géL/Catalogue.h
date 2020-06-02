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
	list<Capteur> rechercherCapteursSimilaires(Capteur c, time_t debut, time_t fin);
	int rechercherQualiteTerritoire(float r, float lon, float lat);
	int rechercherQualiteMoyenne(float r = NULL, float lon = NULL, float lat = NULL);
	list<Capteur> chercherCapteursDefectueux();
	list<Mesure> afficherMesures(Capteur c);
	list<Capteur>afficherCapteurs();
	void ajouterCapteur(Capteur c);
private:
	list<Capteur> capteur;
	struct CalculMoy { int compteur = 0; float valeur = 0; vector<float> palier; int indice = 10; };
	int pireIndice(vector<CalculMoy> stats);
};

#endif // !CATALOGUE
