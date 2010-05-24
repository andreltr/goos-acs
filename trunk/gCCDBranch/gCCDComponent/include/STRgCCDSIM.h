#ifndef STR_GCCD_SIM_H_
#define STR_GCCD_SIM_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "STRBase.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <CCfits/CCfits>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace CCfits;

class STRgCCDSIM: public STRBase {

public:
	STRgCCDSIM();
	~STRgCCDSIM();

	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime);

	int writeImage(int frames, int fileCorrelation);

private:
	int iMAGES_WIDTH;
	int iMAGES_HEIGHT;
};

#endif
