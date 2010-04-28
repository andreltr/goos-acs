#ifndef domeServerImpl_h
#define domeServerImpl_h
#include <acscomponentImpl.h>
#include <domeServerS.h>
#include <maciContainerServices.h>

class domeServerImpl: public virtual acscomponent::ACSComponentImpl,
public virtual POA_sampleModule::sampleInterface
{
	public:
		domeServerImpl(const ACE_CString &name, maci::ContainerServices * containerServices);
		virtual CORBA::Boolean getStatus();

	private:
		boolean status;
};
#endif
