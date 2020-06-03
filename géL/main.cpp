
#include "Lecteur.h"
#include "Catalogue.h"




int main(){

    
    //initialisation des données du Catalogue
    Lecteur *lecteur;
    lecteur = new Lecteur();

    Catalogue cat;

    while( lecteur->flux_capIsGood() ){
        cat.ajouterCapteur(lecteur->lireCapteur() );
    }


    while( lecteur->flux_mesIsGood()  ){
        Mesure mes = lecteur->lireMesure();
        cat.ajouterMesure(mes.getId(), mes);
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
        printf("\t2: \n");
        printf("\t3: \n");
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
 
            list<Capteur> liste(cat.afficherCapteurs()) ;

            for (Capteur c : liste){
                cout << c.afficher() << endl;
            }

        }

        else if(choix == 2)
        {
 
            

        }
        else if(choix == 3)
        {
 
            
        }

        else
        {
            printf("choix incorrect\n");
        }
        
    }

    fin:
    printf("fin\n");

    
    return 0;
    

    
    return 0;
}