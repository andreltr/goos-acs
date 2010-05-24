#ifndef STR_SBIGST7_H_
#define STR_SBIGST7_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "STRBase.h"

class STRSBIGST7: public STRBase {

public:
	STRSBIGST7();
	~STRSBIGST7();
	/*CAMERA FUNCTIONS*/
	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime);
};

#endif
