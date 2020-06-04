
#include "Lecteur.h"
#include "Catalogue.h"



int main(){

    
    //initialisation des données du Catalogue
    Lecteur *lecteur;
    lecteur = new Lecteur();

    Catalogue cat;

    vector<Capteur> capteurs;

    while( lecteur->flux_capIsGood() ){
        capteurs.push_back(lecteur->lireCapteur());
    }


    while( lecteur->flux_mesIsGood()  ){

        Mesure mes = lecteur->lireMesure();

        for (Capteur c : capteurs){
            if(mes.getId() ==  c.getId()){
                c.addMesure(mes);
            }
        }         
    }

    for (Capteur c : capteurs){
        cat.ajouterCapteur(c);
    }    


    Societe s1 = lecteur->lireSociete();
    Societe s2 = lecteur->lireSociete();
    Purificateur pur1 = lecteur->lirePurificateur();
    Purificateur pur2 = lecteur->lirePurificateur();
    s1.addPurificateur( pur1 );
    s2.addPurificateur( pur2 );
    

    Particulier p1 = lecteur->lireParticulier();
    Particulier p2 = lecteur->lireParticulier();

    delete lecteur;


    int choix;
    cout << endl << endl;


    while(1){

        printf("Menu:\n");
        printf("------------------------\n");
        printf("\t1: afficher liste des capteurs\n");
        printf("\t2: afficher les mesures d'un capteur\n");
        printf("\t3: rechercher qualité d'un territoire\n");
        printf("------------------------\n");
        printf("\t4: \n");
        printf("\t5: \n");
        printf("\t0: quitter\n");

        cout << endl;
        cout << "Faites votre choix -> ";
        cin >> choix;



        if(choix == 0)
        {
            goto fin;
        }

        else if(choix == 1)
        {
 
            vector<Capteur> liste(cat.afficherCapteurs()) ;

            for (Capteur c : liste){
                cout << c.afficher() << endl;
            }

        }

        else if(choix == 2)
        {
            long id;

            cout << endl << "id du capteur (entre 0 et 99)-> ";
            cin >> id;

            if(id >= 0 && id < 100){

                vector<Mesure> liste(cat.afficherMesures(id)) ;

                for (Mesure m : liste){
                    cout << m.afficher() << endl;
                }

        
            }

            cout << endl;
            

        }
        else if(choix == 3)
        {
            float rayon, lat, longit;
 
            cout << "rayon (km)-> ";
            cin >> rayon;
            cout << endl << "latitude (entre 44 et 47.6)-> ";
            cin >> lat;
            cout << endl << "longitude (entre -1 et 5.3)-> ";
            cin >> longit;

            if(rayon > 0 && lat >= 44 && lat < 47.7 && longit >= -1 && longit < 5.4){
                cout << endl << "Indice ATMO sur une échelle de 0 à 10 : " <<
                cat.rechercherQualiteTerritoire(rayon, longit, lat);
            }

            
        }

        else
        {
            printf("choix incorrect\n");
        }
        
    }

    fin:
    printf("fin\n");
    

    
    return 0;
}