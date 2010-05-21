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
			m_cameraName_p(this), m_commandedCCDTemperature_p(this) {

	ACS_TRACE("CCDComponent::CCDComponent(): created");
	ncSupplier = 0;
	receiver = 0;
	sender = 0;
	m_bdtThread_p = 0;
	bdStatus = false;
	context = new CCDContext(this, STATE_DISCONNECTED);

	m_actualAirTemperature_p = new ROdouble(name + ":actualAirTemperature",
			getComponent());
	m_actualCCDTemperature_p = new ROdouble(name + ":actualCCDTemperature",
			getComponent());
	m_cameraName_p = new RWstring(name + ":cameraName", getComponent());
	m_commandedCCDTemperature_p = new RWdouble(name
			+ ":commandedCCDTemperature", getComponent());
}

CCDComponent::~CCDComponent() {

	ACS_TRACE("CCDComponent::~CCDComponent(): destroyed");
	if (m_bdtThread_p != 0) {
		getContainerServices()->getThreadManager()->destroy(m_bdtThread_p);
	}

	//delete[] filesQueue;
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

CCDModels::CCDMODEL CCDComponent::getCCDModel() {
	ACS_TRACE("CCDComponent::getCCDModel()");
	return context->getCCDModel();
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

ACS::RWstring_ptr CCDComponent::cameraName() throw (CORBA::SystemException) {
	if (!m_cameraName_p) {
		return ACS::RWstring::_nil();
	}
	ACS::RWstring_var prop = ACS::RWstring::_narrow(
			m_cameraName_p->getCORBAReference());
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

void CCDComponent::setCCDModel(CCDModels::CCDMODEL model) {
	ACS_TRACE("CCDComponent::setCCDModel(...)");
	context->setCCDModel(model);
}

#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS( CCDComponent)
