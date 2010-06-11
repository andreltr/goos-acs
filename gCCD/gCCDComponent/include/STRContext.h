#ifndef STRCONTEXT_H_
#define STRCONTEXT_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "STRLucaEMCCD.h"
#include "STRgCCDSIM.h"
#include "STRSBIGST7.h"
#include "CCDModels.h"
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

	STRContext(long cameraModel) {
		std::cout << "STRContext::STRContext(...) cameraModel: " << cameraModel << std::endl;
		setCCDModel(cameraModel);
	}
	virtual ~STRContext() {
	}

	virtual void on(){
		std::cout << "STRContext::on()" << std::endl;
		return currentCCDModel->on();
	}
	virtual void off(){
		std::cout << "STRContext::off()" << std::endl;
		return currentCCDModel->off();
	}
	virtual void resetCamera() {
		std::cout << "STRContext::resetCamera()" << std::endl;
		return currentCCDModel->resetCamera();
	}

	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime) {
		std::cout << "STRContext::getImage(...)" << std::endl;
		return currentCCDModel->getImage(width, height, acquisitionMode,
				numberOfAcquisitions, exposureTime);
	}
	virtual void stopExposure() {
		std::cout << "STRContext::stopExposure()" << std::endl;
		return currentCCDModel->stopExposure();
	}
	void setCCDModel(long cameraModel) {
		currentModel = cameraModel;
		switch (cameraModel) {
		case LUCA_EMCCD:
			std::cout << "STRContext::setCCDModel(...) LUCA_EMCCD" << std::endl;
			currentCCDModel = &lucaem_ccd;
			break;
		case GCCD_SIM:
			std::cout << "STRContext::setCCDModel(...) GCCD_SIM" << std::endl;
			currentCCDModel = &sim_ccd;
			break;
		case SBIG_ST7:
			std::cout << "STRContext::setCCDModel(...) SBIG_ST7" << std::endl;
			currentCCDModel = &sbigst7_ccd;
			break;
		default:
			std::cout << "STRContext::setCCDModel(...) ERROR" << std::endl;
			//error
		}
	}

};

#endif
