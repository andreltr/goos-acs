#ifndef STR_OCA_SIMCCD_H_
#define STR_OCA_SIMCCD_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "luckyCameraSTRBase.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <CCfits/CCfits>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace CCfits;

class STROcaSimCCD: public STRBase {

public:
	STROcaSimCCD();
	~STROcaSimCCD();

	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime);

	int writeImage(int frames, int fileCorrelation);

private:
	int iMAGES_WIDTH;
	int iMAGES_HEIGHT;
};

#endif
