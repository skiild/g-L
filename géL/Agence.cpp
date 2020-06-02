#include "Agence.h"

list<Capteur> Agence::afficherCapteurs()
{
	return List<Capteur>();
}

list<Capteur> Agence::afficherDefectueux()
{
	return List<Capteur>();
}

int Agence::rechercherQualite(int option)
{
	return 0;
}

Agence::Agence(int id)
{
	this->id = id;
}

Agence::~Agence()
{
}
