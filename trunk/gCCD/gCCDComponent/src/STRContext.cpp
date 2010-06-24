#include "STRModelsHeaders/STRContext.h"

STRContext::STRContext(long cameraModel, Observable *observable) {
	std::cout << "STRContext::STRContext(...) cameraModel: " << cameraModel
			<< std::endl;
	currentCCDModel = 0;
	setCCDModel(cameraModel);
	setComponentProperties(observable);
}

STRContext::~STRContext() {
}

void STRContext::on() {
	std::cout << "STRContext::on()" << std::endl;
	return currentCCDModel->on();
}

void STRContext::off() {
	std::cout << "STRContext::off()" << std::endl;
	return currentCCDModel->off();
}

void STRContext::resetCamera() {
	std::cout << "STRContext::resetCamera()" << std::endl;
	return currentCCDModel->resetCamera();
}

std::string* STRContext::startExposure() {
	std::cout << "STRContext::startExposure()" << std::endl;
	return currentCCDModel->startExposure();
}

void STRContext::stopExposure() {
	std::cout << "STRContext::stopExposure()" << std::endl;
	return currentCCDModel->stopExposure();
}

void STRContext::startCooler() {
	std::cout << "STRContext::startCooler()" << std::endl;
	return currentCCDModel->startCooler();
}

void STRContext::stopCooler() {
	std::cout << "STRContext::stopCooler()" << std::endl;
	return currentCCDModel->stopCooler();
}

void STRContext::setCCDModel(long cameraModel) {
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

void STRContext::setComponentProperties(Observable *observable) {
	currentCCDModel->setComponentProperties(observable);
}
