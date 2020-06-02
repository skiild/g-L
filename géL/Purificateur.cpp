#include "Purificateur.h"


Purificateur::Purificateur(int latitude, int longitude, long id, time_t dateInstallation, time_t dateDesinstallation)
{
	this->latitude = latitude;
	this->longitude = longitude;
	this->id = id;
	this->dateInstallation =  dateInstallation;
	this->dateDesinstallation = dateDesinstallation;
}

Purificateur::~Purificateur()
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

long Purificateur::getId()
{
	return id;
}

time_t Purificateur::getdateInstallation()
{
	return dateInstallation;
}

time_t Purificateur::getdateDesinstallation()
{
	return dateDesinstallation;
}

void Purificateur::setCoordinates(int latitude, int longitude)
{

	this->latitude = latitude;
	this->longitude = longitude;
}