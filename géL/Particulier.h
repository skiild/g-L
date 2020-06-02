/*************************************************************************
						   Particulier  -  description
							 -------------------
	debut                : $30/05/2020$
	copyright            : (C) $2020$ par $ESSAYED-MESSAOUDI Sana$
	e-mail               : $sana.essayed-messaoudi@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Particulier> (fichier Particulier.h) ----------------
#if ! defined ( PARTICULIER_H )
#define PARTICULIER_H
#include<string>
#include <chrono>
#include <list>
#include<iostream>
using namespace std;

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Particulier>
//
//Permet de gerer le compte d'un particulier dont le telephone
//capte des données avant de les transmettre a l'application
//------------------------------------------------------------------------

class Particulier
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Methodes publiques
		// type Methode ( liste des parametres );
		// Mode d'emploi :
		//
		// Contrat :
		//

	//------------------------------------------------- Surcharge d'operateurs

	//-------------------------------------------- Constructeurs - destructeur

	Particulier(long, long); //joue le rôle de creerCompte de notre diagramme
	// Mode d'emploi :
//
	// Contrat :
	//

	virtual ~Particulier();
	// Mode d'emploi :
	//
	// Contrat :
	//
	void connexion();
	void deconnexion();
	bool estConnecte;
	void ajouterPoint();
	list<time_t> consulterPoints();

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Methodes protegees

	//----------------------------------------------------- Attributs proteges
	int id;
	bool connecte;
	list <time_t> points;
	long idCapteur;
};

#endif // PARTICULIER_H

