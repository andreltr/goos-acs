#include <baciDB.h>
#include <acstelescopeServerImpl.h>
#include <ACSErrTypeCommon.h>
#include <iostream>

ACE_RCSID(acsexmpl, acstelescopeServerImpl, "$Id: acstelescopeServerImpl.cpp,v 1.0 Exp $")

using namespace baci;

TelescopeServer::TelescopeServer(
		       const ACE_CString &name,
		       maci::ContainerServices * containerServices) :
    CharacteristicComponentImpl(name, containerServices),
    m_currentPositionAlpha_sp(new RWdouble(name+":currentPositionAlpha", getComponent()),this),
    m_currentPositionDelta_sp(new RWdouble(name+":currentPositionDelta", getComponent()),this)
{
    ACS_TRACE("::TelescopeServer::TelescopeServer");
}

TelescopeServer::~TelescopeServer()
{
    ACS_TRACE("::TelescopeServer::~TelescopeServer");
    ACS_DEBUG_PARAM("::TelescopeServer::~TelescopeServer", "Destroying %s...", name());
}

void
TelescopeServer::displayMessage ()
{
    std::cout << "Telescope Server Ready" << std::endl;
}

void
TelescopeServer::badMethod()
{
    throw (ACSErrTypeCommon::UnknownExImpl(__FILE__, __LINE__, "TelescopeServer::badMethod").getUnknownEx());
}

/*CORBA::Double TelescopeServer::getCurrentPosition() throw (CORBA::SystemException)
{
	return domeCurrentPosition;
}*/


ACS::RWdouble_ptr
TelescopeServer::currentPositionAlpha ()
{
    if (m_currentPositionAlpha_sp == 0)
	{
	return ACS::RWdouble::_nil();
	}

    ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_currentPositionAlpha_sp->getCORBAReference());
    return prop._retn();
}

ACS::RWdouble_ptr
TelescopeServer::currentPositionDelta ()
{
    if (m_currentPositionDelta_sp == 0)
	{
	return ACS::RWdouble::_nil();
	}

    ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_currentPositionDelta_sp->getCORBAReference());
    return prop._retn();
}



#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(TelescopeServer)
