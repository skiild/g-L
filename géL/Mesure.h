#ifndef MESURE
#define MESURE
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>
using namespace std;
class Mesure {
public:
	enum Type { O3, S02, N02, PM10 };
	
	Mesure(float valeur, long id, Type type, time_t temps);
	~Mesure();
	float getValeur();
	time_t getTemps();
	Type getType();
	long getId();
	string afficher();
	
private:
	long id;
	time_t temps;
	float valeur;
	Type type;
};
#endif //MESURE