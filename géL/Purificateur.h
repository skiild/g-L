#ifndef PURIFICATEUR
#define PURIFICATEUR
#include <ctime>
using namespace std;
class Purificateur {
public:
	Purificateur(int latitude, int longitude, long id);
	~Purificateur();
	time_t getdateInstallation();
	int getLatititude();
	int getlongitude();
	long getId();
	void setCoordinates(int latitude, int longitude);
private:
	long id;
	time_t dateInstallation;
	int latitude;
	int longitude;
};
#endif PURIFICATEUR