#ifndef STR_LUCA_EMCCD_H_
#define STR_LUCA_EMCCD_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "STRModelsHeaders/STRBase.h"
#include "atmcdLXd.h"

class STRLucaEMCCD: public STRBase {

public:
	STRLucaEMCCD();
	~STRLucaEMCCD();
	/*CAMERA FUNCTIONS*/
	void on();
	void off();
	void resetCamera();
	std::string* startExposure();
	void stopExposure();

	void startCooler();
	void stopCooler();

	void update();
	void setComponentProperties(Observable *observable);

	void initialize();
	void shutDown();
};

#endif
