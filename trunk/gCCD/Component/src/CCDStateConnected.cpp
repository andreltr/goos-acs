#include "CCDStateConnected.h"
#include "ACSErrTypeCommon.h"
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
	ccd_p->getContext()->setState(CCDStates::STATE_DISCONNECTED);
	return;
}

std::string* CCDStateConnected::getImage(int width, int height,
		int acquisitionMode, int numberOfAcquisitions, float exposureTime) {
	std::cout << "CCDStateConnected::getImage()" << std::endl;
	ccd_p->getContext()->setState(CCDStates::STATE_ACQUIRING);
	return strContext_p->getImage(width, height, acquisitionMode,
			numberOfAcquisitions, exposureTime);
}
