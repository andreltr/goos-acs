#ifndef NCSUPPLIER_H_
#define NCSUPPLIER_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <acscomponentImpl.h>
#include <ACSErrTypeCommon.h>
#include <acsncSimpleSupplier.h>
#include <luckyCameraCCDS.h>

class NCSupplier: public virtual acscomponent::ACSComponentImpl, 
		    public POA_CCDmodule::NotificationSupplier
{    
  public:

    NCSupplier(const ACE_CString& name,
	       maci::ContainerServices * containerServices);
    virtual ~NCSupplier();
    
    /* --------------------- [ CORBA interface ] ----------------------*/    
  
    void sendNotification(const CCDmodule::ncCCDFilename &fileEvent);
};

#endif
