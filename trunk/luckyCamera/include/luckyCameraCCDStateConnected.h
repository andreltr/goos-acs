#ifndef CCDSTATE_CONNECTED_H_
#define CCDSTATE_CONNECTED_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "luckyCameraCCDState.h"
#include "luckyCameraCCDStatesC.h"

class CCDComponent;
/**
 * State: Connected
 * Implements CCDState
 */
class CCDStateConnected: public CCDState {

public:
	/**
	 * Constructor
	 * @param ccd CCDComponent reference
	 */
	CCDStateConnected(CCDComponent * ccd);

	/**
	 * Destructor
	 */
	~CCDStateConnected();

	/**
	 * Gets the state CONNECTED
	 */
	CCDStates::CCDSTATE getState() {
		return CCDStates::STATE_CONNECTED;
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
};

#endif
