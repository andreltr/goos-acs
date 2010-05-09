#include <maciSimpleClient.h>
#include <acsdomeServerC.h>
#include <ACSErrTypeCommon.h>
#include <acsutilTimeStamp.h>
#include <vltPort.h>
#include <acsutil.h>
#include <baciS.h>

#include <iostream>

ACE_RCSID(acsexmpl, acsdomeClient, "$Id: acsdomeClient.cpp,v 1.0 Exp $")
using namespace maci;

const double Pi = 3.14159265358979323846;


bool check(int, int);

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
   	        	// Initiating program
   	        	foo->displayMessage();
   	        	// main loop
   	        	system("clear");
   	        	bool goOff = false;
   	        	std::cout << ">>>>>>>>>>>>>>>>>>> Dome Server Client >>>>>>>>>>>>>>>>>>>" << endl;
   	        	while (!goOff) {
					std::cout << "\nChoose the desired operation:"
							  << "\n(0) Exit"
							  << "\n(1) Get current position of the dome"
							  << "\n(2) Rotate dome"
							  << "\n(3) Get current state of the dome slit"
							  << "\n(4) Open dome slit"
							  << "\n(5) Close dome slit"
							  << "\n?"
							  << std::endl;
					int op;
					std::cin >> op;
					while (!check(op, 5)) {
						std::cout << "...out of range!\n" << std::endl;
						std::cin >> op;
					}
					switch(op) {
					case 0:
						goOff = true;
						std::cout << "\ngoodbye!" << std::endl;
						break;
					case 1:
						//double new_radians = foo->getCurrentPosition();
						std::cout << "\n> The current position of the dome is: " << foo->getCurrentPosition() << std::endl;
						break;
					case 2:
						std::cout << "\nEnter the number of radians to rotate:" << std::endl;
						double radians;
						std::cin >> radians;
						if (radians > -2*Pi && radians < 2*Pi) {
							std::cout << "> Dome Client ~ radians to server: " << radians << std::endl;
							bool rotate = foo->rotateDome(radians);
							if (rotate) {
								double current_position = foo->getCurrentPosition();
								std::cout << "> Dome Client ~ new position of the dome: " << current_position << std::endl;
							} else {
								std::cout << "> Error by rotating the dome" << std::endl;
							}
						} else {
							std::cout << "...out of range!\n" << std::endl;
						}
						break;
					case 3:
						std::cout << "\n> Current state of the dome slit: " << foo->domeSlitIsOpen() << std::endl;
						break;
					case 4:
						std::cout << "\n...opening the slit\n" << std::endl;
						if (foo->openDomeSlit()) {
							std::cout << "> Now, the current state of the dome slit is: " << foo->domeSlitIsOpen() << std::endl;
						} else {
							std::cout << "> Error when opening the slit" << std::endl;
						}
						break;
					case 5:
						std::cout << "\n...closing the slit\n" << std::endl;
						if (foo->closeDomeSlit()) {
							std::cout << "> Now, the current state of the dome slit is: " << foo->domeSlitIsOpen() << std::endl;
						} else {
							std::cout << "> Error when closing the slit" << std::endl;
						}
						break;
					default:
						break;
					}
   	        	}
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

bool check(int op, int range) {
	if (op >= 0 && op <= range) return true;
	else {
		std::cout << "...option out of range, re-enter\n";
		return false;
	}
}
