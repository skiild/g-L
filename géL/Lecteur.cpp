#include "Lecteur.h"




bool Lecteur::flux_capIsGood(){
    return flux_cap.good();
}

bool Lecteur::flux_mesIsGood(){
    return flux_mes.good();
}

bool Lecteur::flux_purIsGood(){
    return flux_pur.good();
}

bool Lecteur::flux_socIsGood(){
    return flux_soc.good();
}

bool Lecteur::flux_parIsGood(){
    return flux_par.good();
}




Capteur Lecteur::lireCapteur(){
    
    

    //Attributs d'un capteur
    string id_str;
    string la;
    string lo;

    long id;
    float lat;
    float longit;

    string line; // 1 ligne du fichier "sensors.csv"

    getline(flux_cap, line, '\n');

    size_t pre = line.find("r");

    size_t pos = line.find(";");    
    
    size_t taille = pos - pre -1;

    id_str = line.substr(pre+1, taille);
  
    line = line.substr(pos+1, line.length()-1);         
    pos = line.find(";");

    la = line.substr(0, pos);
    
    line = line.substr(pos+1, line.length()-1);

    pos = line.find(";");

    lo = line.substr(0, pos);


    string::size_type sz;   // alias of size_t
    id = stol(id_str,&sz);  // conversion string to long
    lat = stof (la,&sz);    // conversion string to float
    longit = stof (lo,&sz); // conversion string to float



    //affichage test
    //cout  << "id=" << id << "la=" << lat << "lo=" << longit << endl;

    Capteur cp(id, lat, longit, "");
    return cp;
    
    
}

Mesure Lecteur::lireMesure(){

    //Attributs d'une mesure
    string id_str;
    string date_str;
    string type_str;
    string val_str;

    long id;
    time_t temps;
    float valeur;
    Mesure::Type type;

    string line; // 1 ligne du fichier "measurements.csv"

    getline(flux_mes, line, '\n');

    size_t pre;
    size_t pos = line.find(";");    
    size_t taille;

    date_str = line.substr(0, pos);
  
    line = line.substr(pos+1, line.length()-1);   
    


    pre = line.find("r");
    pos = line.find(";");    
    taille = pos - pre -1;
    id_str = line.substr(pre+1, taille);

    line = line.substr(pos+1, line.length()-1);   



    pos = line.find(";");    
    type_str = line.substr(0, pos);
    line = line.substr(pos+1, line.length()-1);


    pos = line.find(";");
    val_str  = line.substr(0, pos);


    string::size_type sz;   // alias of size_t
    id = stol(id_str,&sz);  // conversion string to long
    valeur = stof (val_str,&sz);    // conversion string to float


    struct tm info;

    info.tm_year = stoi(date_str.substr(0, 4)) - 1900;
    info.tm_mon = stoi(date_str.substr(5, 2)) - 1;
    info.tm_mday = stoi(date_str.substr(8, 2));
    info.tm_hour = stoi(date_str.substr(11, 2));
    info.tm_min = stoi(date_str.substr(14, 2));
    info.tm_sec = stoi(date_str.substr(17, 2));
    info.tm_isdst = -1;

    temps = mktime(&info);

    /* affichage test
    struct tm * timeinfo;
    timeinfo = localtime (&temps);
    printf ("%s", asctime(timeinfo));
    cout << "//" << id << "//" << type_str << "//" << valeur << "//" << endl;
    
    */


    if ( type_str.compare("O3")  == 0){
        type = Mesure::Type::O3;
    }


    if ( type_str.compare("S02")  == 0){
        type = Mesure::Type::S02;
    }

    if ( type_str.compare("N02")  == 0){
        type = Mesure::Type::N02;
    }


    if ( type_str.compare("PM10")  == 0){
        type = Mesure::Type::PM10;
    }

    
    Mesure m(valeur, id, type, temps);
    return m;
    
}


Purificateur Lecteur::lirePurificateur(){


    //Attributs d'un purificateur

    long id;
    float lat;
    float longit;
    time_t d1;
    time_t d2;

    string date;

    string::size_type sz;   // alias of size_t
    string line; // 1 ligne du fichier "sensors.csv"

    getline(flux_pur, line, '\n');


    size_t pre = line.find("r");
    size_t pos = line.find(";");    
    size_t taille = pos - pre -1;


    id = stol(line.substr(pre+1, taille) ,&sz);  // conversion string to long
  
    line = line.substr(pos+1, line.length()-1);         
    pos = line.find(";");

    lat = stof (line.substr(0, pos),&sz);   // conversion string to float
    
    line = line.substr(pos+1, line.length()-1);         
    pos = line.find(";");

    longit = stof (line.substr(0, pos),&sz);    // conversion string to float

    line = line.substr(pos+2, line.length()-1);         
    pos = line.find(";");

    date = line.substr(0, pos);

    
    struct tm info;

    info.tm_year = stoi(date.substr(0, 4)) - 1900;
    info.tm_mon = stoi(date.substr(5, 2)) - 1;
    info.tm_mday = stoi(date.substr(8, 2));
    info.tm_hour = stoi(date.substr(11, 2));
    info.tm_min = stoi(date.substr(14, 2));
    info.tm_sec = stoi(date.substr(17, 2));
    info.tm_isdst = -1;

    d1 = mktime(&info);

    line = line.substr(pos+1, line.length()-1);         
    pos = line.find(";");

    date = line.substr(0, pos);

    info.tm_year = stoi(date.substr(0, 4)) - 1900;
    info.tm_mon = stoi(date.substr(5, 2)) - 1;
    info.tm_mday = stoi(date.substr(8, 2));
    info.tm_hour = stoi(date.substr(11, 2));
    info.tm_min = stoi(date.substr(14, 2));
    info.tm_sec = stoi(date.substr(17, 2));
    
    d2 = mktime(&info);


    /* affichage
    cout << "//" << id << "//" << lat << "//" << longit  << endl;
    struct tm * timeinfo;
    timeinfo = localtime (&d1);
    printf ("%s", asctime(timeinfo));
    timeinfo = localtime (&d2);
    printf ("%s", asctime(timeinfo));
    */

    Purificateur p(lat, longit, id, d1, d2);

    return p;

}

Societe Lecteur::lireSociete(){


//Attributs d'une entreprise

    long id_soc;
    long id_pur;


    string::size_type sz;   // alias of size_t
    string line; // 1 ligne du fichier "sensors.csv"

    getline(flux_soc, line, '\n');
    

    size_t pre = 8;
    size_t pos = line.find(";");    
    size_t taille = pos - pre;

    
    id_soc = stol(line.substr(pre, taille) ,&sz);  // conversion string to long
  
    line = line.substr(pos+1, line.length()-1); 

    pre = line.find("r");  
    pos = line.find(";");    
    taille = pos - pre - 1;
    id_pur = stol(line.substr(pre+1, taille) ,&sz);

    


    // affichage
    //cout << "//" << id_sco << "//" << id_pur << "//"  << endl;

    
    Societe s(id_soc);
    return s;
    
}


Particulier Lecteur::lireParticulier(){


//Attributs d'une entreprise

    int id_par;
    long id_pur;


    string::size_type sz;   // alias of size_t
    string line; // 1 ligne du fichier "sensors.csv"

    getline(flux_par, line, '\n');
    

    size_t pre = line.find("r"); 
    size_t pos = line.find(";");    
    size_t taille = pos - pre -1;

    
    id_par = stol(line.substr(pre+1, taille) ,&sz);  // conversion string to long
  
    line = line.substr(pos+1, line.length()-1); 

    pre = line.find("r");  
    pos = line.find(";");    
    taille = pos - pre - 1;
    id_pur = stol(line.substr(pre+1, taille) ,&sz);

    
    // affichage
    //cout << "//" << id_par << "//" << id_pur << "//"  << endl;


    Particulier pr(id_par, id_pur);
    return pr;

    

}


Lecteur::Lecteur(){

    flux_cap.open("dataset/sensors.csv");
    flux_mes.open("dataset/measurements.csv");
    flux_pur.open("dataset/cleaners.csv");
    flux_soc.open("dataset/providers.csv");
    flux_par.open("dataset/users.csv");
    
}

Lecteur::~Lecteur(){

    flux_cap.close();
    flux_mes.close();
    flux_pur.close();
    flux_soc.close();
    flux_par.close();

}