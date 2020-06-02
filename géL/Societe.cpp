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

            return rechercherQualiteTerritoire( r, lon, lat);
            break;

        case 2 :
            
            return rechercherQualiteMoyenne( r,  lon, lat);
            break;
            
        default :
            return 0;
    }
}

int Societe::analyserImpactPurificateur(float r, long id, time_t dateDesiree)
{
    for (Purificateur p : purificateurs) {
        if (p.getId() == id) //On cherche le purificateur qui nous interesse
        {
            int result ;
            result=  rechercherQualiteMoyenne(r, p.getlongitude(),p.getLatitude());
            return result;
        }
    }
}

void Societe::addPurificateur(float latitude, float longitude, long id, time_t dateInstallation, time_t dateDesinstallation )
{
    purificateurs.push_back(Purificateur(latitude, longitude, id, dateInstallation, dateDesinstallation));
}
