#include <maciSimpleClient.h>
#include <acsdomeServerC.h>
#include <ACSErrTypeCommon.h>
#include <acsutilTimeStamp.h>
#include <vltPort.h>
#include <acsutil.h>
#include <baciS.h>

ACE_RCSID(acsexmpl, acsdomeClient, "$Id: acsdomeClient.cpp,v 1.0 Exp $")
using namespace maci;

int main(int argc, char *argv[])
{
    SimpleClient client;
    acsdomeServer::DomeServer_var foo;

    if (client.init(argc,argv) == 0)
	{
	return -1;
	}
    else
	{
		//Must log into manager before we can really do anything
		ACS_SHORT_LOG((LM_INFO, "Welcome to Dome Server~Client"));
		ACS_SHORT_LOG((LM_INFO, "Login into maciManager!"));
		client.login();
	}

    //sleep(10);
    //exit;

    try
	{
    	ACS_SHORT_LOG((LM_INFO, "Listing all COBs of type *Geo*"));
    	    maci::HandleSeq seq;
    	    maci::ComponentInfoSeq_var cobs = client.manager()->get_component_info(client.handle(), seq,
    	        "*", "*DomeServer*", false);

    	    for (CORBA::ULong i = 0; i < cobs->length(); i++)
    	    {
    	      ACS_SHORT_LOG((LM_INFO, "%s (%s)", cobs[i].name.in(), cobs[i].type.in()));
    	    }

    	    ACS_SHORT_LOG((LM_INFO, "Getting COB: %s", argv[1]));
    	    acsdomeServer::DomeServer_var foo = client.get_object<acsdomeServer::DomeServer> (argv[1], 0, true);

   	        if (!CORBA::is_nil(foo.in()))
   	        {
   	        	long radians = 3;
   	        	std::cout << "Dome Client ~ radians to server: " << radians << std::endl;
   	        	foo->displayMessage();
   	        	long new_radians = foo->rotate_dome(radians);
   	        	std::cout << "Dome Client ~ radians from server: " << new_radians << std::endl;
    	    }
	}
    catch(maciErrType::CannotGetComponentExImpl &_ex)
	{
	_ex.log();
	return -1;
	}

    //We release our component and logout from manager
    try
	{
	client.releaseComponent(argv[1]);
	}
    catch(maciErrType::CannotReleaseComponentExImpl &_ex)
	{
	_ex.log();
	return -1;
	}

    client.logout();

    //Sleep for 3 sec to allow everything to cleanup and stablize
    ACE_OS::sleep(3);
    return 0;
}
