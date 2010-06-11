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
#include <baciRWlong.h>
#include <baciRWstring.h>
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
	SmartPropertyPointer<RWstring> m_filterName_p;
	SmartPropertyPointer<RWstring> m_objectName_p;
	SmartPropertyPointer<RWstring> m_observerName_p;
	SmartPropertyPointer<RWdouble> m_exposureTime_p;
	SmartPropertyPointer<RWlong> m_acquisitionMode_p;
	SmartPropertyPointer<RWlong> m_numberOfAcquisitions_p;
	SmartPropertyPointer<RWdouble> m_focalLength_p;
	SmartPropertyPointer<ROdouble> m_gain_p;
	SmartPropertyPointer<ROdouble> m_xPixelSize_p;
	SmartPropertyPointer<ROdouble> m_yPixelSize_p;
	SmartPropertyPointer<RWlong> m_xStart_p;
	SmartPropertyPointer<RWlong> m_xEnd_p;
	SmartPropertyPointer<RWlong> m_yStart_p;
	SmartPropertyPointer<RWlong> m_yEnd_p;

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

	virtual ACS::RWstring_ptr filterName() throw (CORBA::SystemException);

	virtual ACS::RWstring_ptr objectName() throw (CORBA::SystemException);

	virtual ACS::RWstring_ptr observerName() throw (CORBA::SystemException);

	virtual ACS::RWdouble_ptr exposureTime() throw (CORBA::SystemException);

	virtual ACS::RWlong_ptr acquisitionMode() throw (CORBA::SystemException);

	virtual ACS::RWlong_ptr numberOfAcquisitions()
			throw (CORBA::SystemException);

	virtual ACS::RWdouble_ptr focalLength() throw (CORBA::SystemException);

	virtual ACS::ROdouble_ptr gain() throw (CORBA::SystemException);

	virtual ACS::ROdouble_ptr xPixelSize() throw (CORBA::SystemException);

	virtual ACS::ROdouble_ptr yPixelSize() throw (CORBA::SystemException);

	virtual ACS::RWlong_ptr xStart() throw (CORBA::SystemException);

	virtual ACS::RWlong_ptr xEnd() throw (CORBA::SystemException);

	virtual ACS::RWlong_ptr yStart() throw (CORBA::SystemException);

	virtual ACS::RWlong_ptr yEnd() throw (CORBA::SystemException);

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
