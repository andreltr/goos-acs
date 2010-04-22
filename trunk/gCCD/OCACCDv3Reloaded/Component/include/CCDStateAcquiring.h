#ifndef CCDSTATE_ACQUIRING_H_
#define CCDSTATE_ACQUIRING_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "CCDState.h"
#include "CCDStatesC.h"

class CCDComponent;

/**
 * State: Acquiring
 * Implements CCDState
 */
class CCDStateAcquiring: public CCDState {

public:
	/**
	 * Constructor
	 * @param ccd CCDComponent reference
	 */
	CCDStateAcquiring(CCDComponent * ccd);

	/**
	 * Destructor
	 */
	~CCDStateAcquiring();

	/**
	 * Gets the state ACQUIRING
	 */
	CCDStates::CCDSTATE getState() {
		return CCDStates::STATE_ACQUIRING;
	}

	/**
	 * Implementation of "on" function for this state.
	 * The camera is acquiring, it should do nothing
	 */
	void on();

	/**
	 * Implementation of "off" function for this state.
	 * The camera is acquiring, it should do nothing
	 */
	void off();

	/**
	 * Implementation of "getImage" function for this state.
	 * The camera is acquiring, it should do nothing
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
