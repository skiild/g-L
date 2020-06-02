#ifndef LECTEUR
#define LECTEUR

#include <iostream>
#include <fstream>

#include "Capteur.h"
#include "Purificateur.h"
//#include "Societe.h"
#include "Particulier.h"



using namespace std;

class Lecteur {

public:

//--------------VERIFICATION 

	//indique si on peut lire dans un fichier

	/*
	EXEMPLE

	while( flux_capIsGood() ){
		Capteur c = lireCapteur();
	}	
	*/

	
	bool flux_capIsGood();
	bool flux_mesIsGood();
	bool flux_purIsGood();
	bool flux_socIsGood();
	bool flux_parIsGood();


//-------------METHODES DE LECTURE DE FICHIERS

	//type de retour à changer
	Capteur lireCapteur(); 			
	Mesure lireMesure(); 			
	Purificateur lirePurificateur();// retourne un Purificateur
	void lireSociete();				
	Particulier lireParticulier();			

	Lecteur();	
	virtual ~Lecteur();

private:

	//fichiers csv
	ifstream flux_cap;
	ifstream flux_mes;
	ifstream flux_pur;
	ifstream flux_soc;
	ifstream flux_par;

	
};
#endif // LECTEUR