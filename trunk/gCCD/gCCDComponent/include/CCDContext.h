#ifndef CCDCONTEXT_H_
#define CCDCONTEXT_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "CCDState.h"
#include "CCDModels.h"
#include "CCDStateDisconnected.h"
#include "CCDStateConnectedOff.h"
#include "CCDStateConnectedOn.h"
#include "CCDStateAcquiring.h"
#include <iostream>

class CCDState;
class CCDComponent;

/**
 * Context implementation of the State Pattern
 */

class CCDContext {
private:
	int currState;
	int lastState;
	CCDState * currentState;
	CCDStateDisconnected * disconnected;
	CCDStateConnectedOff * connected_off;
	CCDStateConnectedOn * connected_on;
	CCDStateAcquiring * acquiring;
public:
	/**
	 * @param ccd CCDComponent reference
	 * @param state initial camera state
	 */
	CCDContext(CCDComponent * ccd, int state) {
		disconnected = new CCDStateDisconnected(ccd);
		connected_off = new CCDStateConnectedOff(ccd);
		connected_on = new CCDStateConnectedOn(ccd);
		acquiring = new CCDStateAcquiring(ccd);
		setState(state);
	}
	/**
	 * Destructor
	 */
	~CCDContext() {
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
	/**
	 * Sets the state
	 * @param state state to be changed
	 */
	void setState(int state) {
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
	/**
	 * depending of the current state, turns the camera on
	 */
	void on() {
		currentState->on();
	}

	/**
	 * depending of the current state, turns the camera off
	 */
	void off() {
		currentState->off();
	}

	/**
	 * depending of the current state, resets the camera
	 */
	void resetCamera() {
		currentState->resetCamera();
	}

	/**
	 * depending of the current state, it gets an image
	 * @param width Image width
	 * @param height Image height
	 * @param acquisitionMode Camera acquisition mode
	 * @param numberOfAcquisitions Number of acquisitions
	 * @param exposureTime Camera exposure time
	 * @return a list of the images file names
	 */
	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime) {
		return currentState->getImage(width, height, acquisitionMode,
				numberOfAcquisitions, exposureTime);
	}

	/**
	 * depending of the current state, stops the image acquisition
	 */
	void stopExposure() {
		currentState->stopExposure();
	}

	/**
	 * depending of the current state, starts the cooler with commandCCDTemperature
	 */
	void startCooler(float commandedCCDTemp) {
		currentState->startCooler(commandedCCDTemp);
	}

	/**
	 * depending of the current state, stops the cooler
	 */
	void stopCooler() {
		currentState->stopCooler();
	}

	/**
	 * gets the currentState
	 * @return current state
	 */
	int getState() {
		return currState;
	}

	void setLastState(int state) {
		lastState = currState;
	}

	int getLastState() {
		return lastState;
	}

};

#endif
