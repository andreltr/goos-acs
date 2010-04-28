/*
 * "@(#) $Id: irisCCDTestClient.cpp,v 2.0  2009/12/03 16:34:29  mparra Exp $"
 *
 * $Log: irisCCDTestClient.cpp,v $
 * Revision 2.0  2009/12/03 16:34:29  mparra
 * - Adapted to iris telescope name.
 *
 * Revision 1.9  2005/02/11 14:48:07  tjuerges
 * - Added possibility to pass centre of simulated field rotation.
 *
 *
 */

#include <vltPort.h>
#include <acsutil.h>
#include <maciSimpleClient.h>
#include "irisCCDC.h"
#include <baciS.h>

#include <logging.h>

using namespace maci;

int main(int argc, char* argv[])
{
  /* Checks command line arguments.
   * We need the name of the device to get in touch with.
   */
  if (argc < 2)
  {
    ACS_SHORT_LOG((LM_INFO, "Usage: %s <Component name> <options>", argv[0]));
    return -1;
  }

  // Creates and initializes the SimpleClient object
  SimpleClient client;

  if (client.init(argc, argv) == 0)
  {
    ACS_SHORT_LOG((LM_ERROR, "Cannot init client"));
    return -1;
  }

  ACS_SHORT_LOG((LM_INFO, "Welcome to CCDTestClient!"));
  ACS_SHORT_LOG((LM_INFO, "Login in maciManager..."));
  client.login();

  try
  {
    // List all components the Manager knows of our type.
    ACS_SHORT_LOG((LM_INFO, "Listing all componentes of type *CCD*"));
    maci::HandleSeq seq;
    maci::ComponentInfoSeq_var components = client.manager()->get_component_info(client.handle(),
        seq, "*", "*CCD*", false);

    for (CORBA::ULong i = 0; i < components->length(); i++)
    {
      ACS_SHORT_LOG((LM_INFO, "%s (%s)", components[i].name.in(), components[i].type.in()));
    }

    // Now get the specific component we have requested on the command line.
    ACS_SHORT_LOG((LM_INFO, "Getting component %s...", argv[1]));
    irisCCD::CCD_var component = client.get_object<irisCCD::CCD> (argv[1], 0, true);

    if (!CORBA::is_nil(component.in()))
    {
      // Prints the descriptor of the requested component.
      ACS_SHORT_LOG((LM_INFO, "Requesting descriptor()... "));
      ACS::CharacteristicComponentDesc_var descriptor = component->descriptor();

      ACS_SHORT_LOG((LM_INFO, "Descriptor:"));
      ACS_SHORT_LOG((LM_INFO, "\tname: %s", descriptor->name.in()));

      ACSErr::Completion_var completion;

      ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:actualAirTemperature", argv[1]));
      if (!CORBA::is_nil(component->actualAirTemperature()))
      {
        CORBA::Double value = component->actualAirTemperature()->get_sync(completion.out());
ACS_SHORT_LOG      ((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:actualCCDTemperature", argv[1]));
    if(!CORBA::is_nil(component->actualCCDTemperature()))
    {
      CORBA::Double value = component->actualCCDTemperature()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:cameraName", argv[1]));
    if(!CORBA::is_nil(component->cameraName()))
    {
      char* value = component->cameraName()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %s", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:commandedCCDTemperature", argv[1]));
    if(!CORBA::is_nil(component->commandedCCDTemperature()))
    {
      CORBA::Double value = component->commandedCCDTemperature()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:darkFrame", argv[1]));
    if(!CORBA::is_nil(component->darkFrame()))
    {
      CORBA::Long value = component->darkFrame()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:exposureSequence", argv[1]));
    if(!CORBA::is_nil(component->exposureSequence()))
    {
      CORBA::Long value = component->exposureSequence()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:exposureTime", argv[1]));
    if(!CORBA::is_nil(component->exposureTime()))
    {
      CORBA::Double value = component->exposureTime()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:filterName", argv[1]));
    if(!CORBA::is_nil(component->filterName()))
    {
      char* value = component->filterName()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %s", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:focalLength", argv[1]));
    if(!CORBA::is_nil(component->focalLength()))
    {
      CORBA::Double value = component->focalLength()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:gain", argv[1]));
    if(!CORBA::is_nil(component->gain()))
    {
      CORBA::Double value = component->gain()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:imageData", argv[1]));
    if(!CORBA::is_nil(component->imageData()))
    {
      ACS::longSeq_var value = component->imageData()->get_sync(completion.out());
      if( value->length() > 0 )
      {
        ACS_SHORT_LOG((LM_INFO, "Value: %d", value[0]))
      }
      else
      {
        ACS_SHORT_LOG((LM_INFO, "Length of sequence is 0! No values!"))
      }
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:imageReady", argv[1]));
    if(!CORBA::is_nil(component->imageReady()))
    {
      CORBA::Long value = component->imageReady()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:numberOfExposuresInSequence", argv[1]));
    if(!CORBA::is_nil(component->numberOfExposuresInSequence()))
    {
      CORBA::Long value = component->numberOfExposuresInSequence()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:numberOfFlushes", argv[1]));
    if(!CORBA::is_nil(component->numberOfFlushes()))
    {
      CORBA::Long value = component->numberOfFlushes()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:objectName", argv[1]));
    if(!CORBA::is_nil(component->objectName()))
    {
      char* value = component->objectName()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %s", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:observerName", argv[1]));
    if(!CORBA::is_nil(component->observerName()))
    {
      char* value = component->observerName()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %s", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationAmplitude", argv[1]));
    if(!CORBA::is_nil(component->simulationAmplitude()))
    {
      ACS::doubleSeq_var value = component->simulationAmplitude()->get_sync(completion.out());
      if( value->length() > 0 )
      {
        ACS_SHORT_LOG((LM_INFO, "Value: %f", value[0]))
      }
      else
      {
        ACS_SHORT_LOG((LM_INFO, "Length of sequence is 0! No values!"))
      }
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationBackgroundNoise", argv[1]));
    if(!CORBA::is_nil(component->simulationBackgroundNoise()))
    {
      CORBA::Double value = component->simulationBackgroundNoise()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationFieldRotation", argv[1]));
    if(!CORBA::is_nil(component->simulationFieldRotation()))
    {
      CORBA::Double value = component->simulationFieldRotation()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationFwhmX", argv[1]));
    if(!CORBA::is_nil(component->simulationFwhmX()))
    {
      CORBA::Double value = component->simulationFwhmX()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationFwhmY", argv[1]));
    if(!CORBA::is_nil(component->simulationFwhmY()))
    {
      CORBA::Double value = component->simulationFwhmY()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationNoise", argv[1]));
    if(!CORBA::is_nil(component->simulationNoise()))
    {
      CORBA::Long value = component->simulationNoise()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationReadoutNoise", argv[1]));
    if(!CORBA::is_nil(component->simulationReadoutNoise()))
    {
      CORBA::Double value = component->simulationReadoutNoise()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationRotationCentreX", argv[1]));
    if(!CORBA::is_nil(component->simulationRotationCentreX()))
    {
      CORBA::Double value = component->simulationRotationCentreX()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationRotationCentreY", argv[1]));
    if(!CORBA::is_nil(component->simulationRotationCentreY()))
    {
      CORBA::Double value = component->simulationRotationCentreY()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationX", argv[1]));
    if(!CORBA::is_nil(component->simulationX()))
    {
      ACS::doubleSeq_var value = component->simulationX()->get_sync(completion.out());
      if( value->length() > 0 )
      {
        ACS_SHORT_LOG((LM_INFO, "Value: %f", value[0]))
      }
      else
      {
        ACS_SHORT_LOG((LM_INFO, "Length of sequence is 0! No values!"))
      }
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:simulationY", argv[1]));
    if(!CORBA::is_nil(component->simulationY()))
    {
      ACS::doubleSeq_var value = component->simulationY()->get_sync(completion.out());
      if( value->length() > 0 )
      {
        ACS_SHORT_LOG((LM_INFO, "Value: %f", value[0]))
      }
      else
      {
        ACS_SHORT_LOG((LM_INFO, "Length of sequence is 0! No values!"))
      }
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:status", argv[1]));
    if(!CORBA::is_nil(component->status()))
    {
      ACS::pattern value = component->status()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:telescopeName", argv[1]));
    if(!CORBA::is_nil(component->telescopeName()))
    {
      char* value = component->telescopeName()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %s", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:timeExposureEnd", argv[1]));
    if(!CORBA::is_nil(component->timeExposureEnd()))
    {
      char* value = component->timeExposureEnd()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %s", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:timeExposureStart", argv[1]));
    if(!CORBA::is_nil(component->timeExposureStart()))
    {
      char* value = component->timeExposureStart()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %s", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:waitTimeBetweenExposuresInSequence", argv[1]));
    if(!CORBA::is_nil(component->waitTimeBetweenExposuresInSequence()))
    {
      CORBA::Double value = component->waitTimeBetweenExposuresInSequence()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:xEnd", argv[1]));
    if(!CORBA::is_nil(component->xEnd()))
    {
      CORBA::Long value = component->xEnd()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:xPixelSize", argv[1]));
    if(!CORBA::is_nil(component->xPixelSize()))
    {
      CORBA::Double value = component->xPixelSize()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:xStart", argv[1]));
    if(!CORBA::is_nil(component->xStart()))
    {
      CORBA::Long value = component->xStart()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:yEnd", argv[1]));
    if(!CORBA::is_nil(component->yEnd()))
    {
      CORBA::Long value = component->yEnd()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:yPixelSize", argv[1]));
    if(!CORBA::is_nil(component->yPixelSize()))
    {
      CORBA::Double value = component->yPixelSize()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %f", value))
    }
    ACS_SHORT_LOG((LM_INFO, "Getting component property: %s:yStart", argv[1]));
    if(!CORBA::is_nil(component->yStart()))
    {
      CORBA::Long value = component->yStart()->get_sync(completion.out());
      ACS_SHORT_LOG((LM_INFO, "Value: %d", value))
    }
  } /* end if component reference OK */
} /* end main try */
catch(...)
{
  ACS_SHORT_LOG((LM_ERROR, "Error in TestClient::main!"));
}

/* Another try section where we release our component
 * and logout from the Manager.
 */
try
{
  ACS_SHORT_LOG((LM_INFO,"Releasing..."));
  client.manager()->release_component(client.handle(), argv[1]);
  client.logout();
}
catch(...)
{
  ACS_SHORT_LOG((LM_ERROR, "Error in TestClient::main!"));
}

/*
 * sleep for 3 sec to allow everytihng to cleanup and stabilize
 * so that the tests can be determinitstic.
 */
ACE_OS::sleep(3);
return 0;
}
