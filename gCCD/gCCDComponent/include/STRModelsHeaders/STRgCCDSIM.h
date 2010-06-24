#ifndef STR_GCCD_SIM_H_
#define STR_GCCD_SIM_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "STRModelsHeaders/STRBase.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <CCfits/CCfits>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <pthread.h>

using namespace CCfits;

class STRgCCDSIM: public STRBase {

public:
	STRgCCDSIM();
	~STRgCCDSIM();

	void on();
	void off();
	void resetCamera();

	std::string* startExposure();

	void stopExposure();

	void startCooler();
	void stopCooler();

	void update();
	void setComponentProperties(Observable *observable);

	//internal functions
	int writeImage(int frames, int fileCorrelation);
	//void *simulateTemperature(void *commandedCCDTemp);

private:
	int IMAGE_WIDTH;
	int IMAGE_HEIGHT;
};

#endif
