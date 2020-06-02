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

list<Mesure> Capteur::getMesures()
{
	return mesure;
}

void Capteur::addMesure(float valeur, Mesure::Type type)
{
	mesure.push_back(Mesure(valeur, ++nbMesure, type));
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
