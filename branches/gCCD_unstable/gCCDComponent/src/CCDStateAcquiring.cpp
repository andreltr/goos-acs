#include "CCDStatesHeaders/CCDStateAcquiring.h"
#include <iostream>
#include "CCD.h"

/*
 *
 * Implementation of ACQUIRING state for the State Pattern
 *
 */

CCDStateAcquiring::CCDStateAcquiring(CCDComponent * ccd, STRContext* strContext) :
	CCDState(ccd, strContext) {
}

CCDStateAcquiring::~CCDStateAcquiring() {

}

int CCDStateAcquiring::getState() {
	return STATE_ACQUIRING;
}

void CCDStateAcquiring::on() {
	std::cout << "CCDStateAcquiring::on() nothing to do" << std::endl;
	return;
}

void CCDStateAcquiring::off() {
	std::cout << "CCDStateAcquiring::off() nothing to do" << std::endl;
	return;
}

void CCDStateAcquiring::resetCamera() {
	std::cout << "CCDStateAcquiring::resetCamera() nothing to do" << std::endl;
	return;
}

std::string* CCDStateAcquiring::startExposure() {
	std::cout << "CCDStateAcquiring::startExposure() nothing to do"
			<< std::endl;
	return 0;
}

void CCDStateAcquiring::stopExposure() {
	std::cout << "CCDStateAcquiring::stopExposure()" << std::endl;
	strContext_p->stopExposure();
	ccd_p->getContext()->setState(ccd_p->getContext()->getLastState());
	return;
}

void CCDStateAcquiring::startCooler() {
	std::cout << "CCDStateAcquiring::startCooler() nothing to do" << std::endl;
	return;
}

void CCDStateAcquiring::stopCooler() {
	std::cout << "CCDStateAcquiring::stopCooler() nothing to do" << std::endl;
	return;
}
