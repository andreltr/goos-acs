#include <domoTestImpl.h>
#include <iostream>

domoTestImpl::domoTestImpl( const ACE_CString &name, maci::ContainerServices * containerServices) : ACSComponentImpl(name, containerServices){
}
CORBA::long domoTestImpl::getNumber() {
	return number;
}

#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(domoTestImpl)
