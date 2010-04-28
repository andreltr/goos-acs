#ifndef CCDSTATE_DISCONNECTED_H_
#define CCDSTATE_DISCONNECTED_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "luckyCameraCCDState.h"
#include "luckyCameraCCDStatesC.h"

class CCDComponent;
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
	CCDStates::CCDSTATE getState() {
		return CCDStates::STATE_DISCONNECTED;
	}

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
	 * Implementation of "getImage" function for this state.
	 * The camera is off, so it should not do nothing.
	 * @param width Image width
	 * @param height Image height
	 * @param acquisitionMode Camera acquisition mode
	 * @param numberOfAcquisitions Number of acquisitions
	 * @param exposureTime Camera exposure time
	 * @return a list of the images file names
	 */
	std::string* getImage(int width, int height, int acquisitionMode,
			int numberOfAcquisitions, float exposureTime);
};

#endif
