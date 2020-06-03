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
	int analyserImpactPurificateur(float r, long id, time_t dateDesiree, Catalogue &cat);
	int rechercher(int recherche, float r, float lon, float lat, Catalogue &cat);
    list<Purificateur> getPurificateurs();
    void addPurificateur(Purificateur &p);

private:
	long id;
    list<Purificateur> purificateurs;

};
#endif //SOCIETE