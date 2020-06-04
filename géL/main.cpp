#include "Catalogue.h"
#include "Lecteur.h"
#include <iostream>

using namespace std;
int main() {

    Lecteur *lecteur;
    lecteur = new Lecteur();

    while (lecteur->flux_capIsGood()) {
        Catalogue::ajouterCapteur(lecteur->lireCapteur());
    }

    while (lecteur->flux_mesIsGood()) {
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

    cout << endl;


    while (1) {

        cout << endl;
        printf("Menu:\n");
        printf("------------------------\n");
        printf("\t1: afficher liste des capteurs\n");
        printf("\t2: afficher les mesures d'un capteur\n");
        printf("\t3: rechercher qualité moyenne totale\n");
        printf("------------------------\n");
        printf("\t4: rechercher qualité d'un territoire\n");
        printf("\t5: rechercher capteurs defectueux\n");
        printf("\t6: rechercher capteurs similaires\n");
        printf("\t0: quitter\n");

        cout << endl;
        cout << "Faites votre choix -> ";
        cin >> choix;

        if (choix == "0")
        {
            break;
        }


        else if(choix == "1")
        {
 
            for (Capteur c : Catalogue::afficherCapteurs()) {
                cout << c.afficher() << endl;       
            }

        }

        else if(choix == "2")
        {

            long id;

            cout << endl << "id du capteur (entre 0 et 99)-> ";
            cin >> id;

            for (Capteur c : Catalogue::afficherCapteurs()) {
                if(c.getId() == id){
                    for (Mesure m : c.getMesures())
                        cout << endl << m.afficher() ;
                }
                
            }

        }

        else if(choix == "3")
        {
            
            cout << endl << "Indice ATMO sur une échelle de 0 à 10 : " <<
            Catalogue::rechercherQualiteMoyenne();
            
        }


        else if(choix == "4")
        {
            float rayon, lat, longit;
 
            cout << "rayon (km)-> ";
            scanf("%f", &rayon);
            cout << endl << "latitude (entre 44 et 47.6)-> ";
            scanf("%f", &lat);
            cout << endl << "longitude (entre -1 et 5.3)-> ";
            scanf("%f", &longit);

            if(rayon > 0 && lat >= 44 && lat < 47.7 && longit >= -1 && longit < 5.4){
                cout << endl << "Indice ATMO sur une échelle de 0 à 10 : " <<
                Catalogue::rechercherQualiteTerritoire(rayon, longit, lat);
            }

        }
        else if(choix == "5")
        {
            
            for (Capteur c : Catalogue::chercherCapteursDefectueux() ) {
                cout << c.afficher() << endl;       
            }
            
        }


        else if(choix == "6"){

            /*for (Capteur c : Catalogue::rechercherCapteursSimilaires() ) {
                cout << c.afficher() << endl;       
            }
            (Capteur c, time_t debut, time_t fin);*/
        }

        else
        {
            printf("choix incorrect\n");
        }
    }

    printf("fin\n");
    
    return 0;
}