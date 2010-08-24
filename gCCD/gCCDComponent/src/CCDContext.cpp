#include "CCDStatesHeaders/CCDContext.h"
#include "CCD.h"

CCDContext::CCDContext(CCDComponent * ccd, int state) {
	strContext_p = new STRContext(ccd->getCCDModel(),
			ccd->getComponentProperties());
	disconnected = new CCDStateDisconnected(ccd, strContext_p);
	connected_off = new CCDStateConnectedOff(ccd, strContext_p);
	connected_on = new CCDStateConnectedOn(ccd, strContext_p);
	acquiring = new CCDStateAcquiring(ccd, strContext_p);
	setState(state);
}

CCDContext::~CCDContext() {
	if (disconnected != 0) {
		delete disconnected;
	}
	if (connected_off != 0) {
		delete connected_off;
	}
	if (connected_on != 0) {
		delete connected_on;
	}
	if (acquiring != 0) {
		delete acquiring;
	}
	if (strContext_p != 0) {
		delete strContext_p;
	}
}

void CCDContext::setState(int state) {
	currState = state;
	switch (state) {
	case STATE_DISCONNECTED:
		currentState = disconnected;
		break;
	case STATE_CONNECTED_COOLER_OFF:
		currentState = connected_off;
		break;
	case STATE_CONNECTED_COOLER_ON:
		currentState = connected_on;
		break;
	case STATE_ACQUIRING:
		currentState = acquiring;
		break;
	}
}

void CCDContext::on() {
	currentState->on();
}

/**
 * depending of the current state, turns the camera off
 */
void CCDContext::off() {
	currentState->off();
}

/**
 * depending of the current state, resets the camera
 */
void CCDContext::resetCamera() {
	currentState->resetCamera();
}

/**
 * depending of the current state, it gets an image
 */
std::string* CCDContext::startExposure() {
	try {
		return currentState->startExposure();
	} catch (...) {
		throw 1;
	}
}

/**
 * depending of the current state, stops the image acquisition
 */
void CCDContext::stopExposure() {
	currentState->stopExposure();
}

/**
 * depending of the current state, starts the cooler with commandCCDTemperature
 */
void CCDContext::startCooler() {
	currentState->startCooler();
}

/**
 * depending of the current state, stops the cooler
 */
void CCDContext::stopCooler() {
	currentState->stopCooler();
}

/**
 * gets the currentState
 * @return current state
 */
int CCDContext::getState() {
	return currState;
}

void CCDContext::setLastState(int state) {
	lastState = currState;
}

int CCDContext::getLastState() {
	return lastState;
}
