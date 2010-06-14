#include "CCDStateDisconnected.h"
#include <iostream>
#include "CCD.h"

/*
 *
 * Implementation of DISCONNECTED state for the State Pattern
 *
 */

CCDStateDisconnected::CCDStateDisconnected(CCDComponent * ccd) :
	CCDState(ccd) {
}

CCDStateDisconnected::~CCDStateDisconnected() {

}

void CCDStateDisconnected::on() {
	std::cout << "CCDStateDisconnected::on() connecting..." << std::endl;
	ccd_p->getContext()->setState(STATE_CONNECTED_COOLER_OFF);
	return;
}

void CCDStateDisconnected::off() {
	std::cout << "CCDStateDisconnected::off() nothing to do" << std::endl;
	return;
}

void CCDStateDisconnected::resetCamera() {
	std::cout << "CCDStateDisconnected::resetCamera() nothing to do" << std::endl;
	return;
}

std::string* CCDStateDisconnected::getImage(int width, int height,
		int acquisitionMode, int numberOfAcquisitions, float exposureTime) {
	std::cout << "CCDStateDisconnected::getImage(...) nothing to do" << std::endl;
	return 0;
}

void CCDStateDisconnected::stopExposure() {
	std::cout << "CCDStateDisconnected::stopExposure() nothing to do" << std::endl;
	return;
}

void CCDStateDisconnected::startCooler(float commandedCCDTemp) {
	std::cout << "CCDStateAcquiring::startCooler(...) nothing to do" << std::endl;
	return;
}

void CCDStateDisconnected::stopCooler(){
	std::cout << "CCDStateAcquiring::stopCooler() nothing to do" << std::endl;
	return;
}
