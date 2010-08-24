#include "CCDStatesHeaders/CCDStateConnectedOff.h"
#include <iostream>
#include "CCD.h"

/*
 *
 * Implementation of CONNECTED state for the State Pattern
 *
 */

CCDStateConnectedOff::CCDStateConnectedOff(CCDComponent * ccd,
		STRContext* strContext) :
	CCDState(ccd, strContext) {
}

CCDStateConnectedOff::~CCDStateConnectedOff() {

}

int CCDStateConnectedOff::getState() {
	return STATE_CONNECTED_COOLER_OFF;
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

std::string* CCDStateConnectedOff::startExposure() {
	std::cout << "CCDStateConnectedOff::startExposure()" << std::endl;
	ccd_p->getContext()->setLastState(ccd_p->getContext()->getState());
	ccd_p->getContext()->setState(STATE_ACQUIRING);
	try {
		return strContext_p->startExposure();
	} catch (...) {
		throw 1;
	}
}

void CCDStateConnectedOff::stopExposure() {
	std::cout << "CCDStateConnectedOff::stopExposure() nothing to do"
			<< std::endl;
	return;
}

void CCDStateConnectedOff::startCooler() {
	std::cout << "CCDStateAcquiring::startCooler()" << std::endl;
	ccd_p->getContext()->setState(STATE_CONNECTED_COOLER_ON);
	strContext_p->startCooler();
	return;
}

void CCDStateConnectedOff::stopCooler() {
	std::cout << "CCDStateAcquiring::stopCooler() nothing to do" << std::endl;
	return;
}
