#include <vltPort.h>
#include <acsutil.h>
#include <maciSimpleClient.h>
#include <acstelescopeServerC.h>

#include <baciS.h>

NAMESPACE_USE( maci);

bool check(int, int);
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

  ACS_SHORT_LOG((LM_INFO, "Welcome to TelescopeServerClient!"));
  ACS_SHORT_LOG((LM_INFO, "Login into maciManager!"));
  client.login();

  try
  {

    /*
     * List all DOs of type "" the Manager knows of.
     */
    ACS_SHORT_LOG((LM_INFO, "Listing all COBs of type *TelescopeServer*"));
    maci::HandleSeq seq;
    maci::ComponentInfoSeq_var cobs = client.manager()->get_component_info(client.handle(), seq,
        "*", "*TelescopeServer*", false);

    for (CORBA::ULong i = 0; i < cobs->length(); i++)
    {
      ACS_SHORT_LOG((LM_INFO, "%s (%s)", cobs[i].name.in(), cobs[i].type.in()));
    }

    /*
     * Now gets the specific DO we have requested on the command line
     */
    ACS_SHORT_LOG((LM_INFO, "Getting COB: %s", argv[1]));
    acstelescopeServer::TelescopeServer_var mount = client.get_object<acstelescopeServer::TelescopeServer> (argv[1], 0, true);

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

        //ACS::RWdouble_var currentPositionAlpha;
        //ACS::RWdouble_var currentPositionDelta;

    	// main loop
    	bool goOff = false;
    	std::cout << ">>>>>>>>>>>>>>>>>>> Telescope Server Client >>>>>>>>>>>>>>>>>>>" << endl;
    	while (!goOff) {
    		std::cout << "\nChoose the desired operation:"
    		<< "\n(0) Exit"
    		<< "\n(1) GET ALTITUDE"
    		<< "\n(2) ...GET AZIMUTH"
    		<< "\n(3) GET RA"
    		<< "\n(4) SLEW"
    		<< "\n(5) ...NO USAR"
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
    			/*ACS_SHORT_LOG((LM_INFO, "Getting COB property: %s:currentPositionAlpha", argv[1]));
    			currentPositionAlpha = mount->currentPositionAlpha();
    			if (currentPositionAlpha.ptr() != ACS::RWdouble::_nil())
    			{
    				CORBA::Double val = currentPositionAlpha->get_sync(completion.out());
    				ACS_SHORT_LOG((LM_INFO, "Value: %f", val));
    			}*/
    			mount->getAltitude();
    			break;
    		case 2:
    			mount->getAzimuth();
    			break;
    		case 3:
    			mount->startTelescope();
    			break;
    		case 4:
    			mount->slewTelescope();
    			break;
    		case 5:
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
