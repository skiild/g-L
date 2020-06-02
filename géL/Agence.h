#ifndef AGENCE
#define AGENCE
#include <string>
#include <list>
using namespace std;

class Agence {
public:
	list<Capteur> afficherCapteurs();
	list<Capteur> afficherDefectueux();
	int rechercherQualite(int option);
	Agence(int id);
	~Agence();
private:
	int id;
};
int Capteur::uid = 0;
#endif // !AGENCE
