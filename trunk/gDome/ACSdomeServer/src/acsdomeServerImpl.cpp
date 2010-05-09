#include <acsdomeServerImpl.h>
#include <ACSErrTypeCommon.h>
#include <iostream>

double domeCurrentPosition = 0.0;
bool slitCurrentState = false;

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

CORBA::Double DomeServer::getCurrentPosition() throw (CORBA::SystemException)
{
	return domeCurrentPosition;
}

CORBA::Boolean DomeServer::rotateDome(CORBA::Double radians) throw (CORBA::SystemException)
{
   std::cout << "Dome Server ~ radians received: " << radians << std::endl;
   domeCurrentPosition += radians;
   return true;
}

CORBA::Boolean DomeServer::domeSlitIsOpen() throw (CORBA::SystemException) {
	std::cout << "Dome Server ~ returning slit current state " << std::endl;
	return slitCurrentState;
}

CORBA::Boolean DomeServer::openDomeSlit() throw (CORBA::SystemException) {
	std::cout << "Dome Server ~ opening the slit " << std::endl;
	slitCurrentState = true;
	return true;
}

CORBA::Boolean DomeServer::closeDomeSlit() throw (CORBA::SystemException) {
	std::cout << "Dome Server ~ closing the slit " << std::endl;
	slitCurrentState = false;
	return true;
}

void
DomeServer::badMethod()
{
    throw (ACSErrTypeCommon::UnknownExImpl(__FILE__, __LINE__, "DomeServer::badMethod").getUnknownEx());
}

#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(DomeServer)
