#include <baciDB.h>
#include "CCD.h"
#include "CCDStatesHeaders/CCDStates.h"

using namespace baci;

/*
 *
 * Implementation of CCDComponent.
 *  This is the ACS component to which the GUI client of the software connects to.
 *
 */

//Include for the generated constructor
#include "GeneratedCode/component_constructor.inc"

CCDComponent::~CCDComponent() {
	ACS_TRACE("CCDComponent::~CCDComponent(): destroyed");
}

/* ----------------- [ ACS component lifecycle START ] ----------------- */

void CCDComponent::initialize()
		throw (acsErrTypeLifeCycle::acsErrTypeLifeCycleExImpl) {
	ACS_TRACE("CCDComponent::initialize()");

	ncSupplier = 0;
	receiver = 0;
	sender = 0;
	m_bdtThread_p = 0;
	bdStatus = false;
	componentProperties = new ComponentProperties();
	setObservable(componentProperties);
	setComponentPropertiesValues();
	context = new CCDContext(this, STATE_DISCONNECTED);
}

void CCDComponent::execute()
		throw (acsErrTypeLifeCycle::acsErrTypeLifeCycleExImpl) {
	ACS_TRACE("CCDComponent::execute()");

}

void CCDComponent::cleanUp() {
	ACS_TRACE("CCDComponent::cleanUp()");

	if (m_bdtThread_p != 0) {
		ACS_TRACE("CCDComponent::cleanUp(): cleaning BDT components...");
		getContainerServices()->getThreadManager()->destroy(m_bdtThread_p);
	}

	if (context != 0) {
		ACS_TRACE("CCDComponent::cleanUp(): cleaning states...");
		delete context;
	}

	if (componentProperties != 0) {
		ACS_TRACE("CCDComponent::cleanUp(): cleaning observer properties...");
		delete componentProperties;
	}
	ACS_TRACE("CCDComponent::cleanUp(): done");
}

void CCDComponent::aboutToAbort() {
	ACS_TRACE("CCDComponent::aboutToAbort()");
	if (m_bdtThread_p != 0) {
		getContainerServices()->getThreadManager()->destroy(m_bdtThread_p);
	}

	if (context != 0) {
		ACS_TRACE("CCDComponent::cleanUp(): cleaning states...");
		delete context;
	}

	if (componentProperties != 0) {
		ACS_TRACE("CCDComponent::cleanUp(): cleaning observer properties...");
		delete componentProperties;
	}
}

/*********************** [ CORBA interface ] ***********************/

void CCDComponent::on() {
	setComponentPropertiesValues();
	ACS_TRACE("CCDComponent::on()");
	context->on();
}

void CCDComponent::off() {
	ACS_TRACE("CCDComponent::off()");
	context->off();
}

void CCDComponent::resetCamera() {
	ACS_TRACE("CCDComponent::resetCamera()");
	context->resetCamera();
}

void CCDComponent::startExposure() {
	ACS_TRACE("CCDComponent::startExposure()");

	int lastState = getState();
	setComponentPropertiesValues();
	try {
		filesQueue = context->startExposure();
	} catch (...) {
		ACSErrTypeCommon::UnexpectedExceptionExImpl ex2(__FILE__, __LINE__,
				"ErrorComponent::badMethod");
		throw ex2.getUnexpectedExceptionEx();
	}
	if (filesQueue != 0) {
		startBulkData();
		sendBulkData(lastState);
	}
}

void CCDComponent::stopExposure() {
	ACS_TRACE("CCDComponent::stopExposure()");
	context->stopExposure();
}

void CCDComponent::startCooler() {
	ACS_TRACE("CCDComponent::startCooler()");
	setComponentPropertiesValues();
	context->startCooler();
}
void CCDComponent::stopCooler() {
	ACS_TRACE("CCDComponent::stopCooler()");
	context->stopCooler();
}

CORBA::Long CCDComponent::getState() {
	ACS_TRACE("CCDComponent::getState()");
	return context->getState();
}

long CCDComponent::getCCDModel() {
	ACS_TRACE("CCDComponent::getCCDModel()");
	ACSErr::Completion_var completion;
	long ccdModel = (long) cameraModel()->get_sync(completion.out());
	return ccdModel;
}

//Include file for the generated properties methods
#include "GeneratedCode/component_methods.inc"

/*********************** [ internal ] ***********************/

CCDContext* CCDComponent::getContext() {
	ACS_TRACE("CCDComponent::getContext()");
	return context;
}

void CCDComponent::startBulkData() {
	ACS_TRACE("CCDComponent::startBulkData()");

	if (sender == 0) {
		char senderName[256];
		ACE_OS::strcpy(senderName, name());
		ACE_OS::strcat(senderName, "_Sender");

		sender
				= getContainerServices()->getComponent<bulkdata::BulkDataSender> (
						senderName);
	}
	if (receiver == 0) {
		char receiverName[256];
		ACE_OS::strcpy(receiverName, name());
		ACE_OS::strcat(receiverName, "_Receiver");

		receiver = getContainerServices()->getComponent<
				bulkdata::BulkDataReceiver> (receiverName);
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
	//set current state of the CCD

}
void CCDComponent::sendBulkData(int lastState) {
	ACS_TRACE("CCDComponent::sendBulkData()");
	/** Initialize control loop thread*/
	if (m_bdtThread_p == 0) {
		CCDComponent * selfPtr = this;
		m_bdtThread_p = getContainerServices()->getThreadManager()->create<
				BDTThread, CCDComponent*> ("bdtThread", /** Name of the thread*/
		selfPtr); /** pass a ptr to this as parameter to thread so it can call back to us*/

		//Pass the filesQueue
		m_bdtThread_p->setLastState(lastState);
		m_bdtThread_p->setQueue(filesQueue, queueSize);

		ACS_SHORT_LOG((LM_INFO, "BDT thread spawned."));
		m_bdtThread_p->resume();
	} else if (m_bdtThread_p->isStopped()) {
		//Pass the filesQueue
		m_bdtThread_p->setLastState(lastState);
		m_bdtThread_p->setQueue(filesQueue, queueSize);

		m_bdtThread_p->restart();
		ACS_SHORT_LOG((LM_INFO, "BDT thread restarted."));
	}
}

void CCDComponent::update() {
	ACS_TRACE("CCDComponent::update()");

	ACS::Time timestamp;
#include "GeneratedCode/component_update.inc"
}

void CCDComponent::setComponentPropertiesValues() {
	ACS_TRACE("CCDComponent::setComponentPropertiesValues()");
	ACSErr::Completion_var completion;

#include "GeneratedCode/component_setter.inc"
}

Observable* CCDComponent::getComponentProperties() {
	return componentProperties;
}

#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS( CCDComponent)
