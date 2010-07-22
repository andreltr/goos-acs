#ifndef CCDSTATE_H_
#define CCDSTATE_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <iostream>
#include "STRModelsHeaders/CCDModels.h"
#include "CCDStatesHeaders/CCDStates.h"
#include "STRModelsHeaders/STRContext.h"
#include "atmcdLXd.h"

class STRContext;
class CCDComponent;

/**
 * Abstract base class for the State Pattern
 */
class CCDState {
protected:
	CCDComponent* ccd_p;
	STRContext* strContext_p;
public:
	CCDState(CCDComponent * ccd, STRContext* strContext);
	virtual ~CCDState();

	virtual void on() = 0;
	virtual void off() = 0;
	virtual void resetCamera() = 0;
	virtual std::string* startExposure() = 0;
	virtual void stopExposure() = 0;
	virtual void startCooler() = 0;
	virtual void stopCooler() = 0;
	virtual int getState() = 0;

};
#endif
