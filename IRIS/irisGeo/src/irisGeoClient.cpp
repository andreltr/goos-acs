/*
 * "@(#) $Id: irisGeoClient.cpp,v 1.3 2010/01/02 12:39:54  mparra Exp $"
 *
 * Revision 1.3 2010/01/02 12:39:54  mparra
 * - Adapted to IRIS telescope name.
 *
 */

#include <vltPort.h>
#include <acsutil.h>
#include <maciSimpleClient.h>
#include "irisGeoC.h"

#include <baciS.h>

NAMESPACE_USE( maci);

int main(int argc, char *argv[])
{

  /*
   * Checks command line arguments.
   * We need the name of the device to get in touch with.
   */
  if (argc < 2)
  {
    ACS_SHORT_LOG((LM_INFO, "Usage: %s <COB name> <options>", argv[0]));
    return -1;
  }

  /*
   * Creates and initialises the SimpleClient object
   */
  SimpleClient client;

  if (client.init(argc, argv) == 0)
  {
    ACE_DEBUG((LM_DEBUG, "Cannot init client"));
    return -1;
  }

  ACS_SHORT_LOG((LM_INFO, "Welcome to $$prefixClient!"));
  ACS_SHORT_LOG((LM_INFO, "Login into maciManager!"));
  client.login();

  try
  {

    /*
     * List all DOs of type "" the Manager knows of.
     */
    ACS_SHORT_LOG((LM_INFO, "Listing all COBs of type *Geo*"));
    maci::HandleSeq seq;
    maci::ComponentInfoSeq_var cobs = client.manager()->get_component_info(client.handle(), seq,
        "*", "*Geo*", false);

    for (CORBA::ULong i = 0; i < cobs->length(); i++)
    {
      ACS_SHORT_LOG((LM_INFO, "%s (%s)", cobs[i].name.in(), cobs[i].type.in()));
    }

    /*
     * Now gets the specific DO we have requested on the command line
     */
    ACS_SHORT_LOG((LM_INFO, "Getting COB: %s", argv[1]));
    irisGeo::Geo_var mount = client.get_object<irisGeo::Geo> (argv[1], 0, true);

    if (!CORBA::is_nil(mount.in()))
    {
      /*
       * Prints the descriptor of the requested DO
       */
      ACS_SHORT_LOG((LM_DEBUG, "Requesting descriptor()... "));
      ACS::CharacteristicComponentDesc_var descriptor = mount->descriptor();

      ACS_SHORT_LOG((LM_DEBUG, "Got descriptor()."));
      ACS_SHORT_LOG((LM_INFO, "Descriptor:"));
      ACS_SHORT_LOG((LM_INFO, "\tname: %s", descriptor->name.in()));

      ACSErr::Completion_var completion;

      ACS_SHORT_LOG((LM_INFO, "Getting COB property: %s:height", argv[1]));
      ACS::RWdouble_var height = mount->height();
      if (height.ptr() != ACS::RWdouble::_nil())
      {
        CORBA::Double val = height->get_sync(completion.out());
        ACS_SHORT_LOG((LM_INFO, "Value: %f", val));
      }
      ACS_SHORT_LOG((LM_INFO, "Getting COB property: %s:latitude", argv[1]));
      ACS::RWdouble_var latitude = mount->latitude();
      if (latitude.ptr() != ACS::RWdouble::_nil())
      {
        CORBA::Double val = latitude->get_sync(completion.out());
        ACS_SHORT_LOG((LM_INFO, "Value: %f", val));
      }
      ACS_SHORT_LOG((LM_INFO, "Getting COB property: %s:longitude", argv[1]));
      ACS::RWdouble_var longitude = mount->longitude();
      if (longitude.ptr() != ACS::RWdouble::_nil())
      {
        CORBA::Double val = longitude->get_sync(completion.out());
        ACS_SHORT_LOG((LM_INFO, "Value: %f", val));
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
/*___oOo___*/
