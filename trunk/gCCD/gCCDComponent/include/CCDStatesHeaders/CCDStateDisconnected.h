#ifndef CCDSTATE_DISCONNECTED_H_
#define CCDSTATE_DISCONNECTED_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "CCDStatesHeaders/CCDState.h"

/**
 * State: Disconnected
 * Implements CCDState
 */
class CCDStateDisconnected: public CCDState {

public:

	/**
	 * @param ccd CCDComponent reference
	 */
	CCDStateDisconnected(CCDComponent * ccd);

	~CCDStateDisconnected();

	/**
	 * Gets the state DISCONNECTED
	 */
	int getState();

	/**
	 * Implementation of "on" function for this state.
	 * It should change the state to CONNECTED
	 */
	void on();

	/**
	 * Implementation of "off" function for this state.
	 * The camera is already off, so it should not do nothing
	 */
	void off();

	/**
	 * Implementation of "resetCamera" function for this state.
	 * The camera is off, so it should not do nothing
	 */
	void resetCamera();

	/**
	 * Implementation of "getImage" function for this state.
	 * The camera is off, so it should not do nothing.
	 */
	std::string* startExposure();

	/**
	 * Implementation of "stopExposure" function for this state.
	 * The camera is off, so it should not do nothing
	 */
	void stopExposure();

	void startCooler();
	void stopCooler();
};

#endif
