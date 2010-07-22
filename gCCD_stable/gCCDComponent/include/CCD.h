#ifndef CCD_H_
#define CCD_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <iostream>

#include <baciCharacteristicComponentImpl.h>

#include <ACSErrTypeCommon.h>
#include <ACSErrTypeOK.h>
#include <CCDS.h>

#include <baciROlong.h>
#include <baciROstring.h>
#include <baciROdouble.h>
#include <baciRWlong.h>
#include <baciRWstring.h>
#include <baciRWdouble.h>
#include <baciSmartPropertyPointer.h>

#include "ace/Get_Opt.h"
#include "orbsvcs/AV/AVStreams_i.h"

#include "CCDStatesHeaders/CCDContext.h"
#include "BDTThread.h"
#include "Observer.h"
#include "ComponentProperties.h"

using namespace ACSBulkDataError;
using namespace baci;

class BDTThread;
class CCDContext;
class CCDStateConnected;

/**
 * ACS component class
 */
class CCDComponent: public virtual CharacteristicComponentImpl,
		public virtual POA_CCDmodule::CCDinterface,
		public Observer {
private:

	/* ------------------------- [ Variables START ] ----------------------- */
	bool bdStatus;
	BDTThread* m_bdtThread_p;
	std::string* filesQueue;
	int queueSize;
	ComponentProperties* componentProperties;

	/* --------------------- [ Properties START ] ----------------------*/
	//Include file for the generated properties smart pointers
#include "GeneratedCode/component_properties.inc"
	/* --------------------- [ Properties END ] ------------------------*/

protected:

	CCDContext* context;
	friend class BDTThread;
	friend class CCDStateConnected;
	friend class CCDStateDisconnected;
	friend class CCDStateAcquiring;

public:

	CCDmodule::NotificationSupplier_var ncSupplier;
	bulkdata::BulkDataReceiver_var receiver;
	bulkdata::BulkDataSender_var sender;
	/* ------------------------- [ Variables END] ----------------------- */

	/**
	 * ACS component constructor
	 */
	CCDComponent(const ACE_CString& name,
			maci::ContainerServices* containerServices);

	/**
	 * ACS component destructor
	 */
	virtual ~CCDComponent();

	/* ----------------- [ ACS component lifecycle START ] ----------------- */

	virtual void initialize()
			throw (acsErrTypeLifeCycle::acsErrTypeLifeCycleExImpl);

	virtual void execute()
			throw (acsErrTypeLifeCycle::acsErrTypeLifeCycleExImpl);

	virtual void cleanUp();

	virtual void aboutToAbort();

	/* --------------------- [ CORBA interface START ] --------------------- */
	/**
	 * Turns on the camera
	 */
	void on();

	/**
	 * Turns off the camera
	 */
	void off();

	/**
	 * Resets the camera to its initial state
	 */
	void resetCamera();

	/**
	 * Obtains an image from the current camera
	 */
	void startExposure();
	/*void getImage(CORBA::Long width, CORBA::Long height,
	 CORBA::Long acquisitionMode, CORBA::Long numberOfAcquisitions,
	 CORBA::Float exposureTime);*/

	/**
	 * Stops the current acquisition operation
	 */
	void stopExposure();

	/**
	 * Starts the cooler from the camera using the commandedCCDTemperature
	 */
	void startCooler();

	/**
	 * Stops the cooler from the camera
	 */
	void stopCooler();

	/**
	 * Gets the current state of the camera
	 */
	CORBA::Long getState();

	/**
	 * Gets the current camera model in use
	 */
	long getCCDModel();

	/**
	 * Functions to access the component's properties
	 */

	//Include file for the generated properties methods prototypes
#include "GeneratedCode/component_prototypes.inc"

	/* --------------------- [ CORBA interface END ] --------------------- */

	/* --------------------- [ internal purpose ] -------------------- */

	/**
	 * Gets CCDContext
	 */
	CCDContext* getContext();

	/**
	 * Starts the bulk data transfer components
	 */
	void startBulkData();

	/**
	 * Sends the files to the client
	 */
	void sendBulkData(int lastState);

	void update();

	void setComponentPropertiesValues();

	Observable* getComponentProperties();

};

#endif
