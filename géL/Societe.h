#ifndef SOCIETE
#define SOCIETE
#include "Purificateur.h"
#include <string>
#include <ctime>

using namespace std;
class Societe {
public:
	Societe(long id);
	~Societe();
	string getId();
	int analyserImpactPurificateur(time_t dateDesiree);
	int rechercher(int recherche, float r, float lon, float lat);


private:
	long id;

};
#endif SOCIETE

