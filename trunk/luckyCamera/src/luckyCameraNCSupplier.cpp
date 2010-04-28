#include "luckyCameraNCSupplier.h"

/*
 *
 *  Implementation of NCSupplier component 
 *
 */

NCSupplier::NCSupplier(const ACE_CString& name,
		maci::ContainerServices * containerServices) :
	ACSComponentImpl(name, containerServices) {
	ACS_TRACE("NCSupplier::NCSupplier():");
}

NCSupplier::~NCSupplier() {
	ACS_TRACE("NCSupplier::~NCSupplier():");
}

void NCSupplier::sendNotification(const CCDmodule::ncCCDFilename &fileEvent) {
	ACS_TRACE("NCSupplier::sendNotification():");
	nc::SimpleSupplier *m_CCDSupplier_p = 0;
	m_CCDSupplier_p = new nc::SimpleSupplier(CCDmodule::CHANNELNAME_CCDCLIENT, this);

	m_CCDSupplier_p->publishData<CCDmodule::ncCCDFilename> (fileEvent);
	ACS_SHORT_LOG((LM_INFO, "NCSupplier::sendNotification(): notification published"));

	if (m_CCDSupplier_p != 0) {
	        ACS_SHORT_LOG((LM_INFO, "NCSupplier::sendNotification(): disconnecting..."));
		m_CCDSupplier_p->disconnect();
		ACS_SHORT_LOG((LM_INFO, "NCSupplier::sendNotification(): disconnected"));
		m_CCDSupplier_p = 0;
	}
	ACS_SHORT_LOG((LM_INFO, "NCSupplier::sendNotification(): end of function"));
}

#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(NCSupplier)
