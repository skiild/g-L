#include "Capteur.h"


//true si erreur
bool Capteur::ChercherErreur()
{
	for (Mesure m : mesure) {
		if (m.getValeur() < 0)
			return true;
	}
	return false;
}

long Capteur::getId()
{
	return id;
}

float Capteur::getLattitude()
{
	return lattitude;
}

float Capteur::getLongitude()
{
	return longitude;
}

string Capteur::getDescription()
{
	return description;
}

vector<Mesure> Capteur::getMesures()
{
	return mesure;
}

void Capteur::addMesure(Mesure &m)
{
	mesure.push_back(m);
}

string Capteur::afficher()
{

	return "Capteur " + std::to_string(this->id) + " : lat=" 
	+ std::to_string(this->lattitude) + ", long=" + std::to_string(this->longitude);
	
}


Capteur::Capteur(long id, float lattitude, float longitude, string description)
{
	this->id = id;
	this->lattitude = lattitude;
	this->longitude = longitude;
	this->description = description;
}

Capteur::~Capteur()
{
}