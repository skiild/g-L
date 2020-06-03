#ifndef MESURE
#define MESURE
#include <ctime>
#include <string>
using namespace std;
class Mesure {
public:
	enum Type { O3, S02, N02, PM10 };
	
	Mesure(float valeur, long id, Type type, time_t temps);
	~Mesure();
	int getValeur();
	time_t getTemps();
	Type getType();
	long getId();
	
private:
	long id;
	time_t temps;
	float valeur;
	Type type;
};
#endif //MESURE