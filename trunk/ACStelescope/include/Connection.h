#include <SerialRS232.h>

using namespace std;

class Connection {

	private:
	SerialRS232 *serial;

	public:
	Connection(char *deviceName);
	~Connection();
	void startTelescope();
	void slewTelescopeNorth();
	void slewTelescopeSouth();
	void slewTelescopeWest();
	void slewTelescopeEast();
	char *getAltitude();
	char *getAzimuth();
	void stopSlewing();
};
