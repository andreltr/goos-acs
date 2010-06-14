#include "CCDStateConnected.h"
#include <iostream>
#include "CCD.h"

/*
 *
 * Implementation of CONNECTED state for the State Pattern
 *
 */

CCDStateConnected::CCDStateConnected(CCDComponent * ccd) :
	CCDState(ccd) {
}

CCDStateConnected::~CCDStateConnected() {

}

void CCDStateConnected::on() {
	std::cout << "CCDStateConnected::on() nothing to do" << std::endl;
	return;
}

void CCDStateConnected::off() {
	std::cout << "CCDStateConnected::off() disconnecting..." << std::endl;
	ccd_p->getContext()->setState(STATE_DISCONNECTED);
	return;
}

void CCDStateConnected::resetCamera() {
	std::cout << "CCDStateConnected::resetCamera() reseting..." << std::endl;
	strContext_p->resetCamera();
	return;
}

std::string* CCDStateConnected::getImage(int width, int height,
		int acquisitionMode, int numberOfAcquisitions, float exposureTime) {
	std::cout << "CCDStateConnected::getImage()" << std::endl;
	ccd_p->getContext()->setLastState(ccd_p->getContext()->getState());
	ccd_p->getContext()->setState(STATE_ACQUIRING);
	return strContext_p->getImage(width, height, acquisitionMode,
			numberOfAcquisitions, exposureTime);
}

void CCDStateConnected::stopExposure() {
	std::cout << "CCDStateConnected::stopExposure() nothing to do" << std::endl;
	return;
}

void CCDStateConnected::startCooler(float commandedCCDTemp) {
	std::cout << "CCDStateAcquiring::startCooler(...)" << std::endl;
	strContext_p->startCooler(commandedCCDTemp);
	return;
}

void CCDStateConnected::stopCooler(){
	std::cout << "CCDStateAcquiring::stopCooler() nothing to do" << std::endl;
	return;
}
