#ifndef STRCONTEXT_H_
#define STRCONTEXT_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "luckyCameraSTRLuckyEMCCD.h"
#include "luckyCameraSTROcaSimCCD.h"
#include "luckyCameraSTRTestCCD.h"
#include "luckyCameraCCDModelsC.h"
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
	CCDModels::CCDMODEL currentModel;
	STRLuckyEMCCD lucky_ccd;
	STROcaSimCCD ocasim_ccd;
	STRTestCCD test_ccd;
public:

	STRContext(CCDModels::CCDMODEL model) {
		setCCDModel(model);
	}
	~STRContext() {
	}
	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime) {
		std::cout << "STRContext::getImage(...)" << std::endl;
		return currentCCDModel->getImage(width, height, acquisitionMode,
				numberOfAcquisitions, exposureTime);
	}
	void setCCDModel(CCDModels::CCDMODEL model) {
		currentModel = model;
		switch (model) {
		case CCDModels::LUCKY_EMCCD:
			std::cout << "STRContext::setCCDModel(...) LUCKYEMCCD" << std::endl;
			currentCCDModel = &lucky_ccd;
			break;
		case CCDModels::OCA_SIMCCD:
			std::cout << "STRContext::setCCDModel(...) OCASIMCCD" << std::endl;
			currentCCDModel = &ocasim_ccd;
			break;
		case CCDModels::TEST_CCD:
			std::cout << "STRContext::setCCDModel(...) TESTCCD" << std::endl;
			currentCCDModel = &test_ccd;
			break;
		default:
			std::cout << "STRContext::setCCDModel(...) DEFAULT" << std::endl;
			//error
		}
	}
	CCDModels::CCDMODEL getCCDModel() {
		return currentModel;
	}
};

#endif
