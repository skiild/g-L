#include "Mesure.h"

Mesure::Mesure(float valeur, long id, Type type)
{
	this->valeur = valeur;
	this->id = id;
	this->temps = time(0);
	this->type = type;
}

Mesure::~Mesure()
{
}

Mesure::Type Mesure::getType()
{
	return type;
}

int Mesure::getValeur()
{
	return valeur;
}

time_t Mesure::getTemps()
{
	return temps;
}
