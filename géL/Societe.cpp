#include "Societe.h"
Societe::Societe(long id)
{
	this->id = id;
}

Societe::~Societe()
{
}


int Societe::rechercher(int option, float r, float lon, float lat, Catalogue &cat)
{
    switch(option)
    {

        case 1 :

            return cat.rechercherQualiteTerritoire( r, lon, lat);
            break;

        case 2 :
            
            return cat.rechercherQualiteMoyenne( r,  lon, lat);
            break;
            
        default :
            return 0;
    }
}

int Societe::analyserImpactPurificateur(float r, long id, time_t dateDesiree, Catalogue &cat)
{
    for (Purificateur p : purificateurs) {
        if (p.getId() == id) //On cherche le purificateur qui nous interesse
        {
            int result ;
            result=  cat.rechercherQualiteMoyenne(r, p.getlongitude(),p.getLatitude());
            return result;
        }
    }
}

void Societe::addPurificateur(Purificateur &p)
{
    purificateurs.push_back(p);
}