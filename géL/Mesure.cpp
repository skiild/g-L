#include "Mesure.h"

Mesure::Mesure(float valeur, long id, Type type, time_t temps)
{
	this->valeur = valeur;
	this->id = id;
	this->temps = temps;
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
