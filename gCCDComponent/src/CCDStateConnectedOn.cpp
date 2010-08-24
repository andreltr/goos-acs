#include "CCDStatesHeaders/CCDStateConnectedOn.h"
#include <iostream>
#include "CCD.h"

/*
 *
 * Implementation of CONNECTED state for the State Pattern
 *
 */

CCDStateConnectedOn::CCDStateConnectedOn(CCDComponent * ccd,
		STRContext* strContext) :
	CCDState(ccd, strContext) {
}

CCDStateConnectedOn::~CCDStateConnectedOn() {

}

int CCDStateConnectedOn::getState() {
	return STATE_CONNECTED_COOLER_ON;
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

std::string* CCDStateConnectedOn::startExposure() {
	std::cout << "CCDStateConnectedOn::startExposure()" << std::endl;
	ccd_p->getContext()->setLastState(ccd_p->getContext()->getState());
	ccd_p->getContext()->setState(STATE_ACQUIRING);
	try {
		return strContext_p->startExposure();
	} catch (...) {
		throw 1;
	}
}

void CCDStateConnectedOn::stopExposure() {
	std::cout << "CCDStateConnectedOn::stopExposure() nothing to do"
			<< std::endl;
	return;
}

void CCDStateConnectedOn::startCooler() {
	std::cout << "CCDStateAcquiring::startCooler() nothing to do" << std::endl;
	return;
}

void CCDStateConnectedOn::stopCooler() {
	std::cout << "CCDStateAcquiring::stopCooler()" << std::endl;
	ccd_p->getContext()->setState(STATE_CONNECTED_COOLER_OFF);
	strContext_p->stopCooler();
	return;
}
