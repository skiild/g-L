#ifndef CAPTEUR
#define CAPTEUR
#include <string>
#include <vector>
#include "Mesure.h"
using namespace std;

class Capteur {
public:
	bool ChercherErreur();
	long getId();
	float getLattitude();
	float getLongitude();
	string getDescription();
	vector<Mesure> getMesures();
	void addMesure(Mesure &m);
	string afficher();
	Capteur(long id, float lattitude, float longitude, string description);
	~Capteur();
private:
	vector<Mesure> mesure;
	long id;
	float lattitude;
	float longitude;
	string description;
	int nbMesure = 0;
};
#endif // !CAPTEUR