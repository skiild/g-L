#ifndef SOCIETE
#define SOCIETE
#include "Purificateur.h"
#include <string>
using namespace std;
class Societe {
public:
	Societe(long id);
	~Societe();
	string getId();
	int analyserImpactPurificateur();
	Purificateur rechercher();

private:
	long id;

};
#endif SOCIETE