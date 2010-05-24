#ifndef STR_LUCA_EMCCD_H_
#define STR_LUCA_EMCCD_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "STRBase.h"
#include "atmcdLXd.h"

class STRLucaEMCCD: public STRBase {

public:
	STRLucaEMCCD();
	~STRLucaEMCCD();
	/*CAMERA FUNCTIONS*/
	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime);
	void initialize();
	void shutDown();
};

#endif
