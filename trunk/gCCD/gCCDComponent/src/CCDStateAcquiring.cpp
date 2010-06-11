#include "CCDStateAcquiring.h"
#include <iostream>
#include "CCD.h"

/*
 *
 * Implementation of ACQUIRING state for the State Pattern
 *
 */

CCDStateAcquiring::CCDStateAcquiring(CCDComponent * ccd) :
	CCDState(ccd) {
}

CCDStateAcquiring::~CCDStateAcquiring() {

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

std::string* CCDStateAcquiring::getImage(int width, int height,
		int acquisitionMode, int numberOfAcquisitions, float exposureTime) {
	std::cout << "CCDStateAcquiring::getImage() nothing to do" << std::endl;
	return 0;
}

void CCDStateAcquiring::stopExposure() {
	std::cout << "CCDStateAcquiring::stopExposure()" << std::endl;
	strContext_p->stopExposure();
	ccd_p->getContext()->setState(STATE_CONNECTED);
	return;
}
