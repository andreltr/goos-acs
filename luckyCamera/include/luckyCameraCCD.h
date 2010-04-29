#ifndef CCD_H_
#define CCD_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <iostream>

//#include <baci.h>
#include <baciCharacteristicComponentImpl.h>

#include <acscomponentImpl.h>
#include <ACSErrTypeCommon.h>

#include <luckyCameraCCDS.h>

#include "ace/Get_Opt.h"
#include "orbsvcs/AV/AVStreams_i.h"

#include "bulkDataSenderS.h"
#include "bulkDataReceiverS.h"
#include "ACSBulkDataError.h"

#include "luckyCameraCCDContext.h"
#include "luckyCameraBDTThread.h"

#include <baciRWstring.h>
#include <baciROdouble.h>
#include <baciRWdouble.h>
//#include "CCDStateDisconnected.h"
//#include "CCDStateConnected.h"
//#include "CCDStateAcquiring.h"

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

	bool bdStatus;
	BDTThread * m_bdtThread_p;
	std::string * filesQueue;
	int queueSize;

	/* --------------------- [ Properties START ] ----------------------*/
	  SmartPropertyPointer<ROdouble> m_actualAirTemperature_p;
	  SmartPropertyPointer<ROdouble> m_actualCCDTemperature_p;
	  SmartPropertyPointer<RWstring> m_cameraName_p;
	  SmartPropertyPointer<RWdouble> m_commandedCCDTemperature_p;

	/* --------------------- [ Properties END ] ------------------------*/

protected:

	CCDContext* context;
	friend class BDTThread;
	friend class CCDStateConnected;
	friend class CCDStateDisconnected;
	friend class CCDStateAcquiring;

public:
	/**
	 * ACS component constructor
	 */
	CCDComponent(const ACE_CString& name,
			maci::ContainerServices * containerServices);
	virtual ~CCDComponent();

	/* --------------------- [ CORBA interface ] --------------------- */
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
	 * gets the state
	 */
	CCDStates::CCDSTATE getState();
	void setCCDModel(CCDModels::CCDMODEL model);
	CCDModels::CCDMODEL getCCDModel();

	  virtual ACS::ROdouble_ptr actualAirTemperature() throw(CORBA::SystemException);

	  virtual ACS::ROdouble_ptr actualCCDTemperature() throw(CORBA::SystemException);

	  virtual ACS::RWstring_ptr cameraName() throw(CORBA::SystemException);

	  virtual ACS::RWdouble_ptr commandedCCDTemperature() throw(CORBA::SystemException);

	/* --------------------- [ internal purpose ] -------------------- */
	//! gets context
	/*!
	 * \return Context
	 */
	CCDContext* getContext();
	void startBulkData();
	void sendBulkData();

	/* ------------------------- [ variables ] ----------------------- */

	CCDmodule::NotificationSupplier_var ncSupplier;
	bulkdata::BulkDataReceiver_var receiver;
	bulkdata::BulkDataSender_var sender;

};

#endif
