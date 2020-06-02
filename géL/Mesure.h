#ifndef MESURE
#define MESURE
#include <ctime>
#include <string>
using namespace std;
class Mesure {
public:
	enum Type { O3, S02, N02, PM10 };
	Type getType();
	Mesure(float valeur, long id, Type type);
	~Mesure();
	int getValeur();
	time_t getTemps();
private:
	long id;
	time_t temps;
	float valeur;
};
#endif MESURE