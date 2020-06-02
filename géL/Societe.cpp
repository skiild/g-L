#include "societe.h"
#include "Purificateur.h"
Societe::Societe(long id)
{
	this->id = id;
}

Societe::~Societe()
{
}


int Societe::rechercher(int option, float r, float lon, float lat)
{
    switch(option)
    {

        case 1 :

            return rechercherQualiteTerritoire(float r, float lon, float lat);

        case 2 :
            
            return rechercherQualiteMoyenne(float r = NULL, float lon = NULL, float lat = NULL);
            
        default :
            return 0;



    }
}

int Societe::analyserImpactPurificateur(float r, long id, time_t dateDesiree)
{
    for (Purificateur p : Purificateur) {
        if (p.getId() == id) //On cherche le purificateur qui nous interesse
        {
        
            
            
        }
    }
}

void Societe::addPurificateur(float latitude, float longitude, long id, time_t dateInstallation, time_t dateDesinstallation )
{
    Purificateurs.push_back(Purificateur(latitude, longitude, id, dateInstallation, dateDesinstallation))
}
