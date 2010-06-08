#include <baciDB.h>
#include <acsdomeServerImpl.h>
#include <ACSErrTypeCommon.h>
#include <iostream>

ACE_RCSID(acsexmpl, acsdomeServerImpl, "$Id: acsdomeServerImpl.cpp,v 1.0 Exp $")

using namespace baci;

DomeServer::DomeServer(
		       const ACE_CString &name,
		       maci::ContainerServices * containerServices) :
    CharacteristicComponentImpl(name, containerServices),
    m_domeCurrentPosition_sp(new RWdouble(name+":domeCurrentPosition", getComponent()),this),
    m_slitCurrentState_sp(new RWlong(name+":slitCurrentState", getComponent()),this)
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

/*CORBA::Double DomeServer::getCurrentPosition() throw (CORBA::SystemException)
{
	return domeCurrentPosition;
}*/


ACS::RWdouble_ptr
DomeServer::domeCurrentPosition ()
{
    if (m_domeCurrentPosition_sp == 0)
	{
	return ACS::RWdouble::_nil();
	}

    ACS::RWdouble_var prop = ACS::RWdouble::_narrow(m_domeCurrentPosition_sp->getCORBAReference());
    return prop._retn();
}

ACS::RWlong_ptr
DomeServer::slitCurrentState ()
{
    if (m_slitCurrentState_sp == 0)
	{
	return ACS::RWlong::_nil();
	}

    ACS::RWlong_var prop = ACS::RWlong::_narrow(m_slitCurrentState_sp->getCORBAReference());
    return prop._retn();
}



#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(DomeServer)
