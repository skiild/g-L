#include "Catalogue.h"
#include <iostream>
using namespace std;

int main() {
	Catalogue c;
	Capteur x = { 0, 1, 2, "capteur stylé" };
	Mesure m = { 0.5, 1, Mesure::O3, time(0) };
	x.addMesure(m);
	c.ajouterCapteur(x);
	
	cout << c.afficherMesures(c.afficherCapteurs()[0])[0].afficher();
	return 0;
}
