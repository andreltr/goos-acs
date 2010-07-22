#ifndef CCDCONTEXT_H_
#define CCDCONTEXT_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "CCDStatesHeaders/CCDState.h"
#include "STRModelsHeaders/CCDModels.h"
#include "CCDStatesHeaders/CCDStateDisconnected.h"
#include "CCDStatesHeaders/CCDStateConnectedOff.h"
#include "CCDStatesHeaders/CCDStateConnectedOn.h"
#include "CCDStatesHeaders/CCDStateAcquiring.h"
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
	CCDState* currentState;
	STRContext* strContext_p;
	CCDStateDisconnected* disconnected;
	CCDStateConnectedOff* connected_off;
	CCDStateConnectedOn* connected_on;
	CCDStateAcquiring* acquiring;
public:
	/**
	 * @param ccd CCDComponent reference
	 * @param state initial camera state
	 */
	CCDContext(CCDComponent * ccd, int state);
	~CCDContext();
	/**
	 * Sets the state
	 * @param state state to be changed
	 */
	void setState(int state);
	/**
	 * depending of the current state, turns the camera on
	 */
	void on();

	/**
	 * depending of the current state, turns the camera off
	 */
	void off();

	/**
	 * depending of the current state, resets the camera
	 */
	void resetCamera();

	/**
	 * depending of the current state, it gets an image
	 */
	std::string* startExposure();

	/**
	 * depending of the current state, stops the image acquisition
	 */
	void stopExposure();

	/**
	 * depending of the current state, starts the cooler with commandCCDTemperature
	 */
	void startCooler();

	/**
	 * depending of the current state, stops the cooler
	 */
	void stopCooler();

	/**
	 * gets the currentState
	 * @return current state
	 */
	int getState();

	void setLastState(int state);

	int getLastState();

};

#endif
