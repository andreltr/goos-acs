/*
 "@(#) $Id: irisCameraFactory.cpp,v 1.5 2010/01/10 23:01:21 mparra Exp $"
 */

#include <irisCameraFactory.h>
#include <irisCameraFLI.h>
#include <irisCameraSBIG.h>
#include <irisCameraIRIS.h>
#include <irisCameraSimulator.h>
#include <irisCameraST402.h>

irisCamera* irisCameraFactory::getCamera(const std::string& cameraType)
{
  if (cameraType == "irisCCDFLI")
  {
    return irisCameraFLI::get_camera();
  }
  else if (cameraType == "irisCCDST9")
  {
    return irisCameraSBIG::get_camera();
  }
  else if (cameraType == "irisCCDSTL")
  {
    return irisCameraSBIG::get_camera();
  }
  else if (cameraType == "irisCCDIRIS")
  {
    return irisCameraIRIS::get_camera();
  }
  else if (cameraType == "irisCCDST402")
  {
    return irisCameraST402::get_camera();
  }
  else if (cameraType == "irisCCDSimulator")
  {
    return irisCameraSimulator::get_camera();
  }

  return 0;
}
