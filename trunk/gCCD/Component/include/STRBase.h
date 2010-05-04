#ifndef STRBASE_H_
#define STRBASE_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <iostream>

/**
 * Abstract base class for the Strategy Pattern
 */

class STRBase {
protected:
	std::string* filesQueue;
public:
	STRBase() {
		filesQueue=0;
	}
	;
	virtual ~STRBase() {
		if(filesQueue!=0){
			delete[] filesQueue;
		}
	};

	virtual std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime) = 0;

};
#endif
