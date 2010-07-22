#ifndef CCDSTATE_ACQUIRING_H_
#define CCDSTATE_ACQUIRING_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "CCDStatesHeaders/CCDState.h"

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
	CCDStateAcquiring(CCDComponent* ccd, STRContext* strContext);

	/**
	 * Destructor
	 */
	~CCDStateAcquiring();

	/**
	 * Gets the state ACQUIRING
	 */
	int getState();

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
	 * Implementation of "resetCamera" function for this state.
	 * The camera is acquiring, it should do nothing
	 */
	void resetCamera();

	/**
	 * Implementation of "getImage" function for this state.
	 * The camera is acquiring, it should do nothing
	 */
	std::string* startExposure();

	/**
	 * Implementation of "stopExposure" function for this state.
	 * The camera is acquiring, it should stop the operation
	 */
	void stopExposure();

	void startCooler();
	void stopCooler();
};

#endif
