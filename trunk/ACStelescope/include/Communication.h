#include <SerialRS232.h>

using namespace std;

class Communication{

	private:
	SerialRS232 *sp;

	public:
	Communication(char *deviceName);
	~Communication();
	void startTelescopeAutomaticSequenceAlignment();
	void startTelescopeSlew();
};
