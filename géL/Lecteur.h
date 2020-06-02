#ifndef LECTEUR
#define LECTEUR

#include <iostream>
#include <fstream>


#include "Mesure.h"
#include "Capteur.h"

/*
#include "Purificataeur.h"
#include "Entreprise.h"
#include "Particulier.h"
*/


enum Type { O3, S02, N02, PM10 };






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
	bool flux_entIsGood();
	bool flux_parIsGood();


	//-------------METHODES DE LECTURE DE FICHIERS

		//type de retour à changer
	void lireCapteur(); 	// retourne un Capteur
	void lireMesure(); 		// retourne un Mesure
	void lirePurificateur();// retourne un Purificateur
	void lireEntreprise();	// retourne une Entreprise
	void lireParticulier();	// retourne un Particulier

	Lecteur();
	~Lecteur();

private:

	//fichiers csv
	ifstream flux_cap;
	ifstream flux_mes;
	ifstream flux_pur;
	ifstream flux_ent;
	ifstream flux_par;


};
#endif // LECTEUR