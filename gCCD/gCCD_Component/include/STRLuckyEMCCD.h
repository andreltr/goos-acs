#ifndef STR_LUCKY_EMCCD_H_
#define STR_LUCKY_EMCCD_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "STRBase.h"
#include "atmcdLXd.h"

class STRLuckyEMCCD: public STRBase {

public:
	STRLuckyEMCCD();
	~STRLuckyEMCCD();
	/*CAMERA FUNCTIONS*/
	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime);
	void initialize();
	void shutDown();
};

#endif
