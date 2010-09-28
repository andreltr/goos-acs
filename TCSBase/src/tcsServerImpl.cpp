#include <baciDB.h>
#include <tcsServerImpl.h>
#include <ACSErrTypeCommon.h>
#include <iostream>

ACE_RCSID(acsexmpl, acsdomeServerImpl, "$Id: tcsServerImpl.cpp,v 1.0 Exp $")

using namespace baci;

tcsServer::tcsServer(
		       const ACE_CString &name,
		       maci::ContainerServices * containerServices) :
    CharacteristicComponentImpl(name, containerServices),
    m_currentPositionAlpha_sp(new RWdouble(name+":currentPositionAlpha", getComponent()),this),
    m_currentPositionDelta_sp(new RWdouble(name+":currentPositionAlpha", getComponent()),this)
{
    ACS_TRACE("::tcsServer::tcsServer");
}

tcsServer::~tcsServer()
{
    ACS_TRACE("::tcsServer::~tcsServer");
    ACS_DEBUG_PARAM("::tcsServer::~tcsServer", "Destroying %s...", name());
}

void
tcsServer::displayMessage ()
{
    std::cout << "TCS Server Ready" << std::endl;
}

void
tcsServer::badMethod()
{
    throw (ACSErrTypeCommon::UnknownExImpl(__FILE__, __LINE__, "tcsServer::badMethod").getUnknownEx());
}

/*CORBA::Double DomeServer::getCurrentPosition() throw (CORBA::SystemException)
{
	return domeCurrentPosition;
}*/


ACS::RWdouble_ptr
tcsServer::currentPositionAlpha ()
{
    if (m_currentPositionAlpha_sp == 0)
	{
	return ACS::RWdouble::_nil();
	}

    ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_currentPositionAlpha_sp->getCORBAReference());
    return prop._retn();
}

ACS::RWdouble_ptr
tcsServer::currentPositionDelta ()
{
    if (m_currentPositionDelta_sp == 0)
	{
	return ACS::RWdouble::_nil();
	}

    ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_currentPositionDelta_sp->getCORBAReference());
    return prop._retn();
}



#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(tcsServer)
