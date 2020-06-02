#ifndef CAPTEUR
#define CAPTEUR
#include <string>
#include <list>
#include "Mesure.h"
using namespace std;

class Capteur {
public:
	bool ChercherErreur();
	long getId();
	float getLattitude();
	float getLongitude();
	string getDescription();
	list<Mesure> getMesures();
	void addMesure(float valeur, Mesure::Type type, time_t);
	Capteur(long id, float lattitude, float longitude, string description);
	~Capteur();
private:
	list<Mesure> mesure;
	long id;
	float lattitude;
	float longitude;
	string description;
	int nbMesure = 0;
};
#endif // !CAPTEUR
