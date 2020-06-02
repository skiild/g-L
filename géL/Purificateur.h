#ifndef PURIFICATEUR
#define PURIFICATEUR
#include <ctime>
using namespace std;
class Purificateur {

public:

	Purificateur(int latitude, int longitude, long id, time_t dateInstallation, time_t dateDesinstallation);
	~Purificateur();
	time_t getdateInstallation();
	time_t getdateDesinstallation();
	int getLatititude();
	int getlongitude();
	long getId();
	void setCoordinates(int latitude, int longitude);
private:
	long id;
	time_t dateInstallation;
	time_t dateDesinstallation;
	int latitude;
	int longitude;
};
#endif //PURIFICATEUR