#include <acsdomeServerImpl.h>
#include <ACSErrTypeCommon.h>
#include <iostream>

ACE_RCSID(acsexmpl, acsdomeServerImpl, "$Id: acsdomeServerImpl.cpp,v 1.0 Exp $")

DomeServer::DomeServer(
		       const ACE_CString &name,
		       maci::ContainerServices * containerServices) :
    ACSComponentImpl(name, containerServices)
{
    ACS_TRACE("::DomeServer::DomeServer");
}

DomeServer::~DomeServer()
{
    ACS_TRACE("::DomeServer::~DomeServer");
    ACS_DEBUG_PARAM("::DomeServer::~DomeServer", "Destroying %s...", name());
}

void
DomeServer::displayMessage ()
{
    std::cout << "Dome Server Ready" << std::endl;
}

void
DomeServer::badMethod()
{
    throw (ACSErrTypeCommon::UnknownExImpl(__FILE__, __LINE__, "DomeServer::badMethod").getUnknownEx());
}

#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(DomeServer)
