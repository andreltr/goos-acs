#include <vltPort.h>
#include <acsutil.h>
#include <maciSimpleClient.h>
#include <acsdomeServerC.h>

#include <baciS.h>

NAMESPACE_USE( maci);

bool check(int, int);

int main(int argc, char *argv[])
{
  system("clear");

  if (argc < 2)
  {
    ACS_SHORT_LOG((LM_INFO, "Usage: %s <COB name> <options>", argv[0]));
    return -1;
  }

  SimpleClient client;

  if (client.init(argc, argv) == 0)
  {
    ACE_DEBUG((LM_DEBUG, "Cannot init client"));
    return -1;
  }

  ACS_SHORT_LOG((LM_INFO, "Welcome to DomeServerClient!"));
  ACS_SHORT_LOG((LM_INFO, "Login into maciManager!"));
  client.login();

  try
  {

    /*
     * List all DOs of type "" the Manager knows of.
     */
    ACS_SHORT_LOG((LM_INFO, "Listing all COBs of type *DomeServer*"));
    maci::HandleSeq seq;
    maci::ComponentInfoSeq_var cobs = client.manager()->get_component_info(client.handle(), seq,
        "*", "*DomeServer*", false);

    for (CORBA::ULong i = 0; i < cobs->length(); i++)
    {
      ACS_SHORT_LOG((LM_INFO, "%s (%s)", cobs[i].name.in(), cobs[i].type.in()));
    }

    /*
     * Now gets the specific DO we have requested on the command line
     */
    ACS_SHORT_LOG((LM_INFO, "Getting COB: %s", argv[1]));
    acsdomeServer::DomeServer_var mount = client.get_object<acsdomeServer::DomeServer> (argv[1], 0, true);

    if (!CORBA::is_nil(mount.in()))
    {
      /*
       * Prints the descriptor of the requested DO
       */

    	// iniciando programa cliente
    	ACS_SHORT_LOG((LM_DEBUG, "Requesting descriptor()... "));
    	ACS::CharacteristicComponentDesc_var descriptor = mount->descriptor();

    	ACS_SHORT_LOG((LM_DEBUG, "Got descriptor()."));
    	ACS_SHORT_LOG((LM_INFO, "Descriptor:"));
    	ACS_SHORT_LOG((LM_INFO, "\tname: %s", descriptor->name.in()));

        ACSErr::Completion_var completion;

        ACS::RWdouble_var domeCurrentPosition;
        ACS::RWlong_var slitCurrentState;

    	// main loop
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
    			ACS_SHORT_LOG((LM_INFO, "Getting COB property: %s:domeCurrentPosition", argv[1]));
    			domeCurrentPosition = mount->domeCurrentPosition();
    			if (domeCurrentPosition.ptr() != ACS::RWdouble::_nil())
    			{
    				CORBA::Double val = domeCurrentPosition->get_sync(completion.out());
    				ACS_SHORT_LOG((LM_INFO, "Value: %f", val));
    			}
    			break;
    		case 2:
    			ACS_SHORT_LOG((LM_INFO, "Getting COB property: %s:domeCurrentPosition", argv[1]));
    			domeCurrentPosition = mount->domeCurrentPosition();
    			if (domeCurrentPosition.ptr() != ACS::RWdouble::_nil())
    			{
    				// Enter the number of position (0:NORTH, 1:SOUTH, 2:EAST, 3:WEST)
    				std::cout << "\nEnter the number of radians to rotate:" << std::endl;
    			    double radians;
    			    std::cin >> radians;
    			    CORBA::Double actual = domeCurrentPosition->get_sync(completion.out());
    			    double move_to = actual + radians;
    			    domeCurrentPosition->set_sync(move_to);
    			    ACS_SHORT_LOG((LM_INFO, "Done!"));
    			}
    			break;
    		case 3:
    			ACS_SHORT_LOG((LM_INFO, "Getting COB property: %s:slitCurrentState", argv[1]));
    			slitCurrentState = mount->slitCurrentState();
    			if (slitCurrentState.ptr() != ACS::RWlong::_nil())
    			{
    				CORBA::Long val = slitCurrentState->get_sync(completion.out());
    			    ACS_SHORT_LOG((LM_INFO, "Value: %i", val));
    			    if (val == 0)
    			    {
    			    	ACS_SHORT_LOG((LM_INFO, "The dome Slit is currently closed: %i", val));
    			    } else {
    			    	ACS_SHORT_LOG((LM_INFO, "The dome Slit is currently opened: %i", val));
    			    }
    			}
    			break;
    		case 4:
    			ACS_SHORT_LOG((LM_INFO, "Open Dome Slit: (actual): %s:slitCurrentState", argv[1]));
    			slitCurrentState = mount->slitCurrentState();
    			if (slitCurrentState.ptr() != ACS::RWlong::_nil())
    			{
    				slitCurrentState->set_sync(1);
    			    ACS_SHORT_LOG((LM_INFO, "The dome Slit is now open"));
    			}
    			break;
    		case 5:
    			ACS_SHORT_LOG((LM_INFO, "Close Dome Slit: (actual): %s:slitCurrentState", argv[1]));
    			slitCurrentState = mount->slitCurrentState();
    			if (slitCurrentState.ptr() != ACS::RWlong::_nil())
    			{
    				slitCurrentState->set_sync(0);
    			    ACS_SHORT_LOG((LM_INFO, "The dome Slit is now closed"));
    			}
    			break;
    		default:
    			break;
    		}
    	}

    } /* end if DO reference OK */
  } /* end main try */
  catch (...)
  {
    ACE_ERROR((LM_ERROR, "main"));
  }

  /*
   * Another try section where we release our COB and logout from the Manager
   */
  try
  {
    ACS_SHORT_LOG((LM_INFO, "Releasing..."));
    client.manager()->release_component(client.handle(), argv[1]);
    client.logout();
  }
  catch (...)
  {
    ACE_ERROR((LM_ERROR, "main"));
  }

  /*
   * sleep for 3 sec to allow everytihng to cleanup and stabilyse
   * so that the tests can be determinitstic.
   */
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
