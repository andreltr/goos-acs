#include "CCDStateConnectedOff.h"
#include <iostream>
#include "CCD.h"

/*
 *
 * Implementation of CONNECTED state for the State Pattern
 *
 */

CCDStateConnectedOff::CCDStateConnectedOff(CCDComponent * ccd) :
	CCDState(ccd) {
}

CCDStateConnectedOff::~CCDStateConnectedOff() {

}

void CCDStateConnectedOff::on() {
	std::cout << "CCDStateConnectedOff::on() nothing to do" << std::endl;
	return;
}

void CCDStateConnectedOff::off() {
	std::cout << "CCDStateConnectedOff::off() disconnecting..." << std::endl;
	ccd_p->getContext()->setState(STATE_DISCONNECTED);
	return;
}

void CCDStateConnectedOff::resetCamera() {
	std::cout << "CCDStateConnectedOff::resetCamera() reseting..." << std::endl;
	strContext_p->resetCamera();
	return;
}

std::string* CCDStateConnectedOff::getImage(int width, int height,
		int acquisitionMode, int numberOfAcquisitions, float exposureTime) {
	std::cout << "CCDStateConnectedOff::getImage()" << std::endl;
	ccd_p->getContext()->setLastState(ccd_p->getContext()->getState());
	ccd_p->getContext()->setState(STATE_ACQUIRING);
	return strContext_p->getImage(width, height, acquisitionMode,
			numberOfAcquisitions, exposureTime);
}

void CCDStateConnectedOff::stopExposure() {
	std::cout << "CCDStateConnectedOff::stopExposure() nothing to do" << std::endl;
	return;
}

void CCDStateConnectedOff::startCooler(float commandedCCDTemp) {
	std::cout << "CCDStateAcquiring::startCooler(...)" << std::endl;
	ccd_p->getContext()->setState(STATE_CONNECTED_COOLER_ON);
	strContext_p->startCooler(commandedCCDTemp);
	return;
}

void CCDStateConnectedOff::stopCooler(){
	std::cout << "CCDStateAcquiring::stopCooler() nothing to do" << std::endl;
	return;
}
