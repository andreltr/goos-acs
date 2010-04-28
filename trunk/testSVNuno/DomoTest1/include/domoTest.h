#ifndef domoTestImpl_h
#define domoTestImpl_h
#include <acscomponentImpl.h>
#include <domoTestS.h>
#include <maciContainerServices.h>

class domoTestImpl: public virtual acscomponent::ACSComponentImpl,
public virtual POA_sampleModule::sampleInterface
{
	public:
		domoTestImpl(const ACE_CString &name, maci::ContainerServices * containerServices);
		virtual CORBA::Long getNumber();

	private:
		long number;
};
#endif
