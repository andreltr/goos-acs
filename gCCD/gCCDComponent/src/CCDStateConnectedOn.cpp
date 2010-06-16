#include "CCDStateConnectedOn.h"
#include <iostream>
#include "CCD.h"

/*
 *
 * Implementation of CONNECTED state for the State Pattern
 *
 */

CCDStateConnectedOn::CCDStateConnectedOn(CCDComponent * ccd) :
	CCDState(ccd) {
}

CCDStateConnectedOn::~CCDStateConnectedOn() {

}

void CCDStateConnectedOn::on() {
	std::cout << "CCDStateConnectedOn::on() nothing to do" << std::endl;
	return;
}

void CCDStateConnectedOn::off() {
	std::cout << "CCDStateConnectedOn::off() disconnecting..." << std::endl;
	ccd_p->getContext()->setState(STATE_DISCONNECTED);
	return;
}

void CCDStateConnectedOn::resetCamera() {
	std::cout << "CCDStateConnectedOn::resetCamera() reseting..." << std::endl;
	strContext_p->resetCamera();
	return;
}

std::string* CCDStateConnectedOn::getImage(int width, int height,
		int acquisitionMode, int numberOfAcquisitions, float exposureTime) {
	std::cout << "CCDStateConnectedOn::getImage()" << std::endl;
	ccd_p->getContext()->setLastState(ccd_p->getContext()->getState());
	ccd_p->getContext()->setState(STATE_ACQUIRING);
	return strContext_p->getImage(width, height, acquisitionMode,
			numberOfAcquisitions, exposureTime);
}

void CCDStateConnectedOn::stopExposure() {
	std::cout << "CCDStateConnectedOn::stopExposure() nothing to do" << std::endl;
	return;
}

void CCDStateConnectedOn::startCooler(float commandedCCDTemp) {
	std::cout << "CCDStateAcquiring::startCooler(...) nothing to do" << std::endl;
	return;
}

void CCDStateConnectedOn::stopCooler(){
	std::cout << "CCDStateAcquiring::stopCooler()" << std::endl;
	ccd_p->getContext()->setState(STATE_CONNECTED_COOLER_OFF);
	strContext_p->stopCooler();
	return;
}