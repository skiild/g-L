#ifndef SOCIETE
#define SOCIETE
#include "Purificateur.h"
#include "Catalogue.h"
#include <string>
#include <list>
#include <ctime>
#include <list>

using namespace std;
class Societe {
public:
	Societe(long id);
	~Societe();
	string getId();
	int analyserImpactPurificateur(float r, long id, time_t dateDesiree);
	int rechercher(int recherche, float r, float lon, float lat);
    list<Purificateur> getPurificateurs();
    void addPurificateur(float latitude, float longitude, long id, time_t dateInstallation, time_t dateDesinstallation );

private:
	long id;
    list<Purificateur> purificateurs;

};
#endif SOCIETE

