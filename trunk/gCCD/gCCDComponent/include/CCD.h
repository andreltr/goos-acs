#ifndef CCD_H_
#define CCD_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <iostream>

#include <baciCharacteristicComponentImpl.h>

#include <ACSErrTypeCommon.h>

#include <CCDS.h>

#include <baciROlong.h>
#include <baciROstring.h>
#include <baciROdouble.h>
#include <baciRWdouble.h>
#include <baciSmartPropertyPointer.h>

#include "ace/Get_Opt.h"
#include "orbsvcs/AV/AVStreams_i.h"

#include "bulkDataSenderS.h"
#include "bulkDataReceiverS.h"
#include "ACSBulkDataError.h"

#include "CCDContext.h"
#include "BDTThread.h"

using namespace ACSBulkDataError;
using namespace baci;

class BDTThread;
class CCDContext;
class CCDStateConnected;

/**
 * ACS component class
 */
class CCDComponent: public virtual CharacteristicComponentImpl,
		public virtual POA_CCDmodule::CCDinterface {
private:

	/* ------------------------- [ Variables START ] ----------------------- */
	bool bdStatus;
	BDTThread * m_bdtThread_p;
	std::string * filesQueue;
	int queueSize;

	/* --------------------- [ Properties START ] ----------------------*/
	SmartPropertyPointer<ROdouble> m_actualAirTemperature_p;
	SmartPropertyPointer<ROdouble> m_actualCCDTemperature_p;
	SmartPropertyPointer<RWdouble> m_commandedCCDTemperature_p;
	SmartPropertyPointer<ROstring> m_cameraName_p;
	SmartPropertyPointer<ROlong> m_cameraModel_p;
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
			maci::ContainerServices * containerServices);

	/**
	 * ACS component destructor
	 */
	virtual ~CCDComponent();

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
	 * Obtains an image from the current camera
	 */
	void getImage(CORBA::Long width, CORBA::Long height,
			CORBA::Long acquisitionMode, CORBA::Long numberOfAcquisitions,
			CORBA::Float exposureTime);

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

	virtual ACS::ROdouble_ptr actualAirTemperature()
			throw (CORBA::SystemException);

	virtual ACS::ROdouble_ptr actualCCDTemperature()
			throw (CORBA::SystemException);

	virtual ACS::RWdouble_ptr commandedCCDTemperature()
			throw (CORBA::SystemException);

	virtual ACS::ROstring_ptr cameraName() throw (CORBA::SystemException);

	virtual ACS::ROlong_ptr cameraModel() throw (CORBA::SystemException);
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
	void sendBulkData();

};

#endif
