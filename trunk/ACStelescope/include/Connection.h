#include <SerialRS232.h>

using namespace std;

class Connection {

	private:
	SerialRS232 *serial;

	public:
	Connection(char *deviceName);
	~Connection();
	void startTelescopeAutomaticSequenceAlignment();
	void startTelescopeSlew();
	char *getAzimuth();
};
