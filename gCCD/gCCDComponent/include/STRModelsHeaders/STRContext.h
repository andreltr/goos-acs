#ifndef STRCONTEXT_H_
#define STRCONTEXT_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "STRModelsHeaders/STRLucaEMCCD.h"
#include "STRModelsHeaders/STRgCCDSIM.h"
#include "STRModelsHeaders/STRSBIGST7.h"
#include "STRModelsHeaders/CCDModels.h"
#include <iostream>

class STRBase;

/*
 *
 * Context implementation of the Strategy Pattern
 *
 */

class STRContext {
private:
	STRBase * currentCCDModel;
	long currentModel;
	STRLucaEMCCD lucaem_ccd;
	STRgCCDSIM sim_ccd;
	STRSBIGST7 sbigst7_ccd;
public:

	STRContext(long cameraModel, Observable *observable);
	virtual ~STRContext();

	virtual void on();
	virtual void off();
	virtual void resetCamera();

	std::string* startExposure();
	virtual void stopExposure();

	virtual void startCooler();
	virtual void stopCooler();

	void setCCDModel(long cameraModel);

	void setComponentProperties(Observable *observable);

};

#endif
