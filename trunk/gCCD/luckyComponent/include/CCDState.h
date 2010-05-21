#ifndef CCDSTATE_H_
#define CCDSTATE_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <iostream>
#include "CCDModelsC.h"
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
	CCDState(CCDComponent * ccd) {
		ccd_p = ccd;
		strContext_p = new STRContext(CCDModels::OCA_SIMCCD);
	}
	virtual ~CCDState() {
		delete strContext_p;
	}

	virtual void on() = 0;
	virtual void off() = 0;
	virtual std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime) = 0;
	virtual int getState() = 0;
	void setCCDModel(CCDModels::CCDMODEL model) {
		strContext_p->setCCDModel(model);
	}
	;
	CCDModels::CCDMODEL getCCDModel() {
		return strContext_p->getCCDModel();
	}

};
#endif
