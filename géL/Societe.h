#ifndef SOCIETE
#define SOCIETE
#include <string>
using namespace std;
class Societe {
public:
	Societe(string id);
	~Societe();
	string getId();
	int analyserImpactPurificateur();
	Purificateur rechercher();

private:
	long id;

};
#endif SOCIETE