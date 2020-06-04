#ifndef CATALOGUE
#define CATALOGUE
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <chrono>
#include "Capteur.h"
using namespace std;
class Catalogue {
public:
	static vector<Capteur> rechercherCapteursSimilaires(Capteur c, time_t debut, time_t fin);
	static int rechercherQualiteTerritoire(float r, float lon, float lat);
	static int rechercherQualiteMoyenne(float r = NULL, float lon = NULL, float lat = NULL);
	static vector<Capteur> chercherCapteursDefectueux();
	static vector<Mesure> afficherMesures(long c);
	static vector<Capteur>afficherCapteurs();
	static void ajouterCapteur(Capteur c);
	static void ajouterMesure(long idCapteur, Mesure& m);
private:
	struct CalculMoy { int compteur = 0; float valeur = 0; vector<float> palier; int indice = 10; };
	static int pireIndice(vector<CalculMoy> stats);
	static vector<Capteur> capteur;

};
#endif // !CATALOGUE