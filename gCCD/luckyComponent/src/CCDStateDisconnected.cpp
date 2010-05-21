#include "CCDStateDisconnected.h"
#include "ACSErrTypeCommon.h"
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
	ccd_p->getContext()->setState(STATE_CONNECTED);
	return;
}

void CCDStateDisconnected::off() {
	std::cout << "CCDStateDisconnected::off() nothing to do" << std::endl;
	return;
}

std::string* CCDStateDisconnected::getImage(int width, int height,
		int acquisitionMode, int numberOfAcquisitions, float exposureTime) {
	std::cout << "CCDStateDisconnected::getImage() nothing to do" << std::endl;
	return 0;
}
