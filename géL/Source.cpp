#include "Catalogue.h"
#include "Purificateur.h"
#include "Societe.h"
#include "Lecteur.h"
#include <Windows.h>
#include <iostream>
using namespace std;
int main() {
	/*
	Catalogue c;
	Capteur x = { 0, 1, 2, "capteur stylé" };
	Mesure m = { 0.5, 1, Mesure::O3, time(0) };
	x.addMesure(m);
	c.ajouterCapteur(x);
	
	cout << c.afficherMesures(c.afficherCapteurs()[0])[0].afficher();
	return 0;
	*/

	/*
	ifstream file("dataset/sensors.csv");
	string cell;
	while (getline(file, cell, ';'))
		cout << cell;
		*/
	Lecteur *lecteur;
	lecteur = new Lecteur();

	while (lecteur->flux_capIsGood()) {
		Catalogue::ajouterCapteur(lecteur->lireCapteur());
	}

	while (lecteur->flux_mesIsGood()) {
		compteur++;
		Mesure mes = lecteur->lireMesure();
		Catalogue::ajouterMesure(mes.getId(), mes);
	}
	
	Societe s1 = lecteur->lireSociete();
	Societe s2 = lecteur->lireSociete();
	Purificateur pur1 = lecteur->lirePurificateur();
	Purificateur pur2 = lecteur->lirePurificateur();
	s1.addPurificateur(pur1);
	s2.addPurificateur(pur2);

	
	Particulier p1 = lecteur->lireParticulier();
	Particulier p2 = lecteur->lireParticulier();
	
	delete lecteur;

	string choix;

	cout << endl << endl;


	while (1) {

		printf("Menu:\n");
		printf("------------------------\n");
		printf("\t1: afficher liste des capteurs\n");
		printf("\t2: \n");
		printf("\t3: \n");
		printf("------------------------\n");
		printf("\t4: \n");
		printf("\t5: \n");
		printf("\t0: quitter\n");

		cout << endl;
		cout << "Faites votre choix -> ";
		cin >> choix;
		if (choix == "1")
		{
			for (Capteur c : Catalogue::afficherCapteurs()) {
				cout << "capteur no " << c.getId() << endl;
				for (Mesure m : c.getMesures())
					cout << m.afficher() << endl;
			}

		}
		else
		{
			printf("choix incorrect\n");
		}
	}
}
