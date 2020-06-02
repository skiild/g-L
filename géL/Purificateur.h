#ifndef PURIFICATEUR
#define PURIFICATEUR
#include <ctime>
using namespace std;
class Purificateur {

public:

	Purificateur(float latitude, float longitude, long id, time_t dateInstallation, time_t dateDesinstallation);
	~Purificateur();
	time_t getdateInstallation();
	time_t getdateDesinstallation();
	float getLatititude();
	float getlongitude();
	long getId();
	void setCoordinates(float latitude, float longitude);
private:
	long id;
	time_t dateInstallation;
	time_t dateDesinstallation;
	float latitude;
	float longitude;
};
#endif //PURIFICATEUR