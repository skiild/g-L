#include "Purificateur.h"


Purificateur::Purificateur(float latitude, float longitude, long id, time_t dateInstallation, time_t dateDesinstallation)
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

float Purificateur::getLatitude()
{
	return latitude;
}

float Purificateur::getlongitude()
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

void Purificateur::setCoordinates(float latitude, float longitude)
{

	this->latitude = latitude;
	this->longitude = longitude;
}
