#include "Purificateur.h"


Purificateur::Purificateur(int latitude, int longitude, long id)
{
	this->latitude = latitude;
	this->longitude = longitude;
	this->id = id;
}

Purificateur::~Purificateur
{
}

int Purificateur::getLatititude()
{
	return latitude;
}

int Purificateur::getlongitude()
{
	return longitude;
}

long getId()
{
	return id;
}

time_t Purificateur::getdateInstallation()
{
	return dateInstallation()
}

void setCoordinates(int latitude, int longitude);
{

}