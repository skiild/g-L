/*************************************************************************
						   Particulier  -  description
							 -------------------
	début                : $30/05/2020$
	copyright            : (C) $2020$ par $ESSAYED-MESSAOUDI Sana$
	e-mail               : $sana.essayed-messaoudi@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Particulier> (fichier Particulier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Particulier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
// type Particulier::Methode ( liste des parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode


//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur


Particulier::Particulier(long id, long capteurid)
// Algorithme :
//
{
	this->id = id;
	this->idCapteur = capteurid;
	this->totalPoints = 0;
	this->points = new ArrayList<>();
#ifdef MAP
	cout << "Appel au constructeur de <Particulier>" << endl;
#endif
} //----- Fin de Particulier


Particulier::~Particulier()
// Algorithme :
//
{
	delete consulterPoints;
#ifdef MAP
	cout << "Appel au destructeur de <Particulier>" << endl;
#endif
} //----- Fin de ~Particulier

List <time_t> Particulier::consulterPoints() {
	return points;
}

void Particulier::ajouterPoint() {
	this->points.add(chrono::system_clock::to_time_t(chrono::system_clock::now()));
}

bool Particulier::connexion() {
	this->connecte = true;
}

bool Particulier::deconnexion() {
	this->connecte = false;
}

bool Particulier::estConnecte{
	return connecte;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

