#ifndef CCDSTATE_CONNECTED_OFF_H_
#define CCDSTATE_CONNECTED_OFF_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "CCDState.h"

/**
 * State: Connected with cooler off
 * Implements CCDState
 */
class CCDStateConnectedOff: public CCDState {

public:
	/**
	 * Constructor
	 * @param ccd CCDComponent reference
	 */
	CCDStateConnectedOff(CCDComponent * ccd);

	/**
	 * Destructor
	 */
	~CCDStateConnectedOff();

	/**
	 * Gets the state CONNECTED
	 */
	int getState() {
		return STATE_CONNECTED_COOLER_OFF;
	}
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
	 * @param width Image width
	 * @param height Image height
	 * @param acquisitionMode Camera acquisition mode
	 * @param numberOfAcquisitions Number of acquisitions
	 * @param exposureTime Camera exposure time
	 * @return a list of the images file names
	 */
	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime);

	/**
	 * Implementation of "stopExposure" function for this state
	 * It should change do nothing
	 */
	void stopExposure();

	void startCooler(float commandedCCDTemp);
	void stopCooler();
};

#endif