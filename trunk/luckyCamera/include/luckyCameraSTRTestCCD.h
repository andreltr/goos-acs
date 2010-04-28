#ifndef STR_TEST_H_
#define STR_TEST_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "luckyCameraSTRBase.h"

class STRTestCCD: public STRBase {

public:
	STRTestCCD();
	~STRTestCCD();
	/*CAMERA FUNCTIONS*/
	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime);
};

#endif
