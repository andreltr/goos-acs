#include <baciDB.h>
#include "CCD.h"
#include "CCDStates.h"

using namespace baci;

/*
 *
 * Implementation of CCDComponent.
 *  This is the ACS component to which the GUI client of the software connects to.
 *
 */

CCDComponent::CCDComponent(const ACE_CString& name,
		maci::ContainerServices * containerServices) :
	CharacteristicComponentImpl(name, containerServices),
			m_actualAirTemperature_p(this), m_actualCCDTemperature_p(this),
			m_commandedCCDTemperature_p(this), m_cameraName_p(this),
			m_cameraModel_p(this), m_filterName_p(this), m_objectName_p(this),
			m_observerName_p(this), m_exposureTime_p(this), m_focalLength_p(
					this), m_gain_p(this), m_xPixelSize_p(this),
			m_yPixelSize_p(this), m_xStart_p(this), m_xEnd_p(this), m_yStart_p(
					this), m_yEnd_p(this)
{

	ACS_TRACE("CCDComponent::CCDComponent(): created");

	m_actualAirTemperature_p = new ROdouble(name + ":actualAirTemperature",
			getComponent());
	m_actualCCDTemperature_p = new ROdouble(name + ":actualCCDTemperature",
			getComponent());
	m_commandedCCDTemperature_p = new RWdouble(name
			+ ":commandedCCDTemperature", getComponent());
	m_cameraName_p = new ROstring(name + ":cameraName", getComponent());
	m_cameraModel_p = new ROlong(name + ":cameraModel", getComponent());
	m_filterName_p = new RWstring(name + ":filterName", getComponent());
	m_objectName_p = new RWstring(name + ":objectName", getComponent());
	m_observerName_p = new RWstring(name + ":observerName", getComponent());
	m_exposureTime_p = new RWdouble(name + ":exposureTime", getComponent());
	m_focalLength_p = new RWdouble(name + ":focalLength", getComponent());
	m_gain_p = new ROdouble(name + ":gain", getComponent());
	m_xPixelSize_p = new ROdouble(name + ":xPixelSize", getComponent());
	m_yPixelSize_p = new ROdouble(name + ":yPixelSize", getComponent());
	m_xStart_p = new RWlong(name + ":xStart", getComponent());
	m_xEnd_p = new RWlong(name + ":xEnd", getComponent());
	m_yStart_p = new RWlong(name + ":yStart", getComponent());
	m_yEnd_p = new RWlong(name + ":yEnd", getComponent());

	ncSupplier = 0;
	receiver = 0;
	sender = 0;
	m_bdtThread_p = 0;
	bdStatus = false;
	context = new CCDContext(this, STATE_DISCONNECTED);

}

CCDComponent::~CCDComponent() {

	ACS_TRACE("CCDComponent::~CCDComponent(): destroyed");
	if (m_bdtThread_p != 0) {
		getContainerServices()->getThreadManager()->destroy(m_bdtThread_p);
	}

	delete context;
}

/*********************** [ CORBA interface ] ***********************/

void CCDComponent::on() {
	ACS_TRACE("CCDComponent::on()");
	context->on();
}

void CCDComponent::off() {
	ACS_TRACE("CCDComponent::off()");
	context->off();
}

void CCDComponent::getImage(CORBA::Long width, CORBA::Long height,
		CORBA::Long acquisitionMode, CORBA::Long numberOfAcquisitions,
		CORBA::Float exposureTime) {
	ACS_TRACE("CCDComponent::getImage()");

	filesQueue = context->getImage((int) width, (int) height,
			(int) acquisitionMode, (int) numberOfAcquisitions,
			(float) exposureTime);
	if (filesQueue != 0) {
		startBulkData();
		sendBulkData();
	}
}

CORBA::Long CCDComponent::getState() {
	ACS_TRACE("CCDComponent::getState()");
	return context->getState();
}

long CCDComponent::getCCDModel() {
	ACS_TRACE("CCDComponent::getCCDModel()");
	ACSErr::Completion_var completion;
	return cameraModel()->get_sync(completion.out());
}

ACS::ROdouble_ptr CCDComponent::actualAirTemperature()
		throw (CORBA::SystemException) {
	if (!m_actualAirTemperature_p) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_actualAirTemperature_p->getCORBAReference());
	return prop._retn();
}

ACS::ROdouble_ptr CCDComponent::actualCCDTemperature()
		throw (CORBA::SystemException) {
	if (!m_actualCCDTemperature_p) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_actualCCDTemperature_p->getCORBAReference());
	return prop._retn();
}

ACS::RWdouble_ptr CCDComponent::commandedCCDTemperature()
		throw (CORBA::SystemException) {
	if (!m_commandedCCDTemperature_p) {
		return ACS::RWdouble::_nil();
	}
	ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
			m_commandedCCDTemperature_p->getCORBAReference());
	return prop._retn();
}

ACS::ROstring_ptr CCDComponent::cameraName() throw (CORBA::SystemException) {
	if (!m_cameraName_p) {
		return ACS::ROstring::_nil();
	}
	ACS::ROstring_var prop = ACS::ROstring::_narrow(
			m_cameraName_p->getCORBAReference());
	return prop._retn();
}

ACS::ROlong_ptr CCDComponent::cameraModel() throw (CORBA::SystemException) {
	if (!m_cameraModel_p) {
		return ACS::ROlong::_nil();
	}
	ACS::ROlong_var prop = ACS::ROlong::_narrow(
			m_cameraModel_p->getCORBAReference());
	return prop._retn();
}

ACS::RWstring_ptr CCDComponent::filterName() throw (CORBA::SystemException) {
	if (!m_filterName_p) {
		return ACS::RWstring::_nil();
	}
	ACS::RWstring_var prop = ACS::RWstring::_narrow(
			m_filterName_p->getCORBAReference());
	return prop._retn();
}

ACS::RWstring_ptr CCDComponent::objectName() throw (CORBA::SystemException) {
	if (!m_objectName_p) {
		return ACS::RWstring::_nil();
	}
	ACS::RWstring_var prop = ACS::RWstring::_narrow(
			m_objectName_p->getCORBAReference());
	return prop._retn();
}

ACS::RWstring_ptr CCDComponent::observerName() throw (CORBA::SystemException) {
	if (!m_observerName_p) {
		return ACS::RWstring::_nil();
	}
	ACS::RWstring_var prop = ACS::RWstring::_narrow(
			m_observerName_p->getCORBAReference());
	return prop._retn();
}

ACS::RWdouble_ptr CCDComponent::exposureTime() throw (CORBA::SystemException) {
	if (!m_exposureTime_p) {
		return ACS::RWdouble::_nil();
	}
	ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
			m_exposureTime_p->getCORBAReference());
	return prop._retn();
}

ACS::RWdouble_ptr CCDComponent::focalLength() throw (CORBA::SystemException) {
	if (!m_focalLength_p) {
		return ACS::RWdouble::_nil();
	}
	ACS::RWdouble_var prop = ACS::RWdouble::_narrow(
			m_focalLength_p->getCORBAReference());
	return prop._retn();
}

ACS::ROdouble_ptr CCDComponent::gain() throw (CORBA::SystemException) {
	if (!m_gain_p) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_gain_p->getCORBAReference());
	return prop._retn();
}

ACS::ROdouble_ptr CCDComponent::xPixelSize() throw (CORBA::SystemException) {
	if (!m_xPixelSize_p) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_xPixelSize_p->getCORBAReference());
	return prop._retn();
}

ACS::ROdouble_ptr CCDComponent::yPixelSize() throw (CORBA::SystemException) {
	if (!m_yPixelSize_p) {
		return ACS::ROdouble::_nil();
	}
	ACS::ROdouble_var prop = ACS::ROdouble::_narrow(
			m_yPixelSize_p->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::xStart() throw (CORBA::SystemException) {
	if (!m_xStart_p) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop =
			ACS::RWlong::_narrow(m_xStart_p->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::xEnd() throw (CORBA::SystemException) {
	if (!m_xEnd_p) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop = ACS::RWlong::_narrow(m_xEnd_p->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::yStart() throw (CORBA::SystemException) {
	if (!m_yStart_p) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop =
			ACS::RWlong::_narrow(m_yStart_p->getCORBAReference());
	return prop._retn();
}

ACS::RWlong_ptr CCDComponent::yEnd() throw (CORBA::SystemException) {
	if (!m_yEnd_p) {
		return ACS::RWlong::_nil();
	}
	ACS::RWlong_var prop = ACS::RWlong::_narrow(m_yEnd_p->getCORBAReference());
	return prop._retn();
}

/*********************** [ internal ] ***********************/

CCDContext* CCDComponent::getContext() {
	ACS_TRACE("CCDComponent::getContext()");
	return context;
}

void CCDComponent::startBulkData() {
	ACS_TRACE("CCDComponent::startBulkData()");
	if (sender == 0) {
		sender
				= getContainerServices()->getComponent<bulkdata::BulkDataSender> (
						"BulkDataSenderEx1");
	}
	if (receiver == 0) {
		receiver = getContainerServices()->getComponent<
				bulkdata::BulkDataReceiver> ("BulkDataReceiver");
	}
	if (ncSupplier == 0) {
		ncSupplier = getContainerServices()->getComponent<
				CCDmodule::NotificationSupplier> ("NCSupplier");
	}

	if (CORBA::is_nil(receiver.in())) {
		ACS_SHORT_LOG(
				(LM_INFO, "Could not retrieve BulkDataReceiver Component."));
	}

	if (CORBA::is_nil(sender.in())) {
		ACS_SHORT_LOG((LM_INFO, "Could not retrieve BulkDataSender Component."));
	}
	if (CORBA::is_nil(ncSupplier.in())) {
		ACS_SHORT_LOG((LM_INFO, "Could not retrieve NCSupplier Component."));
	}
	/**Bulk Data and notification channel components are activated*/
	bdStatus = true;
}
void CCDComponent::sendBulkData() {
	ACS_TRACE("CCDComponent::sendBulkData()");
	/** Initialize control loop thread*/
	if (m_bdtThread_p == 0) {
		CCDComponent * selfPtr = this;
		m_bdtThread_p = getContainerServices()->getThreadManager()->create<
				BDTThread, CCDComponent*> ("bdtThread", /** Name of the thread*/
		selfPtr); /** pass a ptr to this as parameter to thread so it can call back to us*/

		//Pass the filesQueue
		m_bdtThread_p->setQueue(filesQueue, queueSize);

		ACS_SHORT_LOG((LM_INFO, "BDT thread spawned."));
		m_bdtThread_p->resume();
	} else if (m_bdtThread_p->isStopped()) {
		//Pass the filesQueue
		m_bdtThread_p->setQueue(filesQueue, queueSize);

		m_bdtThread_p->restart();
		ACS_SHORT_LOG((LM_INFO, "BDT thread restarted."));
	}
}

#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS( CCDComponent)
