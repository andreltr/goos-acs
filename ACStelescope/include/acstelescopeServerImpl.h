#ifndef _TELESCOPE_SERVER_H
#define _TELESCOPE_SERVER_H

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <ACSErrTypeCommon.h>
#include <acstelescopeServerS.h>

#include <baciCharacteristicComponentImpl.h>
#include <baciRWdouble.h>
#include <baciRWlong.h>

#include <baciSmartPropertyPointer.h>

class TelescopeServer: public baci::CharacteristicComponentImpl,
			  public virtual POA_acstelescopeServer::TelescopeServer
{
  public:
	TelescopeServer(
	       const ACE_CString& name,
	       maci::ContainerServices * containerServices);
		   
    virtual ~TelescopeServer();

    virtual void displayMessage();
    virtual void badMethod();
    //virtual CORBA::Double getCurrentPosition() throw(CORBA::SystemException);
    virtual CORBA::Double startTelescope() throw(CORBA::SystemException);
    virtual CORBA::Double slewTelescope() throw(CORBA::SystemException);
    virtual CORBA::Double getAzimuth() throw(CORBA::SystemException);

    // ATRIBUTOS
    virtual ACS::RWdouble_ptr
    currentPositionAlpha ();

    virtual ACS::RWdouble_ptr
    currentPositionDelta ();

    private:
        baci::SmartPropertyPointer<baci::RWdouble> m_currentPositionAlpha_sp;
        baci::SmartPropertyPointer<baci::RWdouble> m_currentPositionDelta_sp;
	
};

#endif
