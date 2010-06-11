#ifndef CCDCONTEXT_H_
#define CCDCONTEXT_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "CCDState.h"
#include "CCDModels.h"
#include "CCDStateDisconnected.h"
#include "CCDStateConnected.h"
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
	CCDState * currentState;
	CCDStateDisconnected * disconnected;
	CCDStateConnected * connected;
	CCDStateAcquiring * acquiring;
public:
	/**
	 * @param ccd CCDComponent reference
	 * @param state initial camera state
	 */
	CCDContext(CCDComponent * ccd, int state) {
		disconnected = new CCDStateDisconnected(ccd);
		connected = new CCDStateConnected(ccd);
		acquiring = new CCDStateAcquiring(ccd);
		setState(state);
	}
	/**
	 * Destructor
	 */
	~CCDContext() {
		delete disconnected;
		delete connected;
		delete acquiring;
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
		case STATE_CONNECTED:
			currentState = connected;
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
	 * gets the currentState
	 * @return current state
	 */
	int getState() {
		return currState;
	}

};

#endif
