#ifndef CCDSTATE_CONNECTED_ON_H_
#define CCDSTATE_CONNECTED_ON_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "CCDStatesHeaders/CCDState.h"

/**
 * State: Connected with cooler on
 * Implements CCDState
 */
class CCDStateConnectedOn: public CCDState {

public:
	/**
	 * Constructor
	 * @param ccd CCDComponent reference
	 */
	CCDStateConnectedOn(CCDComponent* ccd, STRContext* strContext);

	/**
	 * Destructor
	 */
	~CCDStateConnectedOn();

	/**
	 * Gets the state CONNECTED
	 */
	int getState();
	/**
	 * Implementation of "on" function for this state.
	 * The camera is already on, it should do nothing
	 */
	void on();

	/**
	 * Implementation of "off" function for this state
	 * It should change the state to DISCONNECTED
	 */
	void off();

	/**
	 * Implementation of "resetCamera" function for this state
	 * It should change do reset the camera
	 */
	void resetCamera();

	/**
	 * Implementation of "getImage" function for this state.
	 * The camera is on, it should obtain an image.
	 */
	std::string* startExposure();

	/**
	 * Implementation of "stopExposure" function for this state
	 * It should change do nothing
	 */
	void stopExposure();

	void startCooler();
	void stopCooler();
};

#endif
