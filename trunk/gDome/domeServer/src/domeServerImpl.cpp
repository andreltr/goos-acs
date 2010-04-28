#include <domeServerImpl.h>
#include <iostream>

domoTestImpl::domoTestImpl( const ACE_CString &name, maci::ContainerServices * containerServices) : ACSComponentImpl(name, containerServices){
}
CORBA::long domeServerImpl::getStatus() {
	return status;
}

#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(domoTestImpl)
