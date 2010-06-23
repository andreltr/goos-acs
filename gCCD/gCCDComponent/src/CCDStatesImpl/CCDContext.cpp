#include "CCDStatesHeaders/CCDContext.h"

CCDContext::CCDContext(CCDComponent * ccd, int state) {
	disconnected = new CCDStateDisconnected(ccd);
	connected_off = new CCDStateConnectedOff(ccd);
	connected_on = new CCDStateConnectedOn(ccd);
	acquiring = new CCDStateAcquiring(ccd);
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
	return currentState->startExposure();
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
