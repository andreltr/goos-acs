#ifndef _DOME_SERVER_H
#define _DOME_SERVER_H

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <acscomponentImpl.h>
#include <ACSErrTypeCommon.h>
#include <acsdomeServerS.h>

class DomeServer: public virtual acscomponent::ACSComponentImpl,   	//Component superclass
		  public POA_acsdomeServer::DomeServer    					//CORBA servant stub
{
  public:
	DomeServer(
	       const ACE_CString& name,
	       maci::ContainerServices * containerServices);

    virtual ~DomeServer();

    virtual void
    displayMessage ();

    virtual CORBA::Long rotate_dome(CORBA::Long radians) throw(CORBA::SystemException);

    virtual void
    badMethod();
};

#endif
