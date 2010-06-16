#ifndef CCDSTATE_H_
#define CCDSTATE_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <iostream>
#include "CCDModels.h"
#include "CCDStates.h"
#include "STRContext.h"
#include "atmcdLXd.h"

class STRContext;
class CCDComponent;

/**
 * Abstract base class for the State Pattern
 */
class CCDState {
protected:
	CCDComponent * ccd_p;
	STRContext * strContext_p;
public:
	CCDState(CCDComponent * ccd);
	virtual ~CCDState() {
		if (strContext_p != 0) {
			delete strContext_p;
		}
	}

	virtual void on() = 0;
	virtual void off() = 0;
	virtual void resetCamera() = 0;
	virtual std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime) = 0;
	virtual void stopExposure() = 0;
	virtual void startCooler(float commandedCCDTemp) = 0;
	virtual void stopCooler() = 0;
	virtual int getState() = 0;

};
#endif
