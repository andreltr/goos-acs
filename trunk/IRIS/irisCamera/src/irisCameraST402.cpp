/*
 * "@(#) $Id: irisCameraST402.cpp,v 1.31 2010/01/08 01:34:28  mparra Exp $"
 *
 * $Log: irisCameraST402.cpp,v $
 * Revision 1.31 2010/01/08 01:34:28  mparra
 * - Adapted from irisCameraSBIG to ST402
 *
 * Revision 1.30 2009/01/20 pbugueno
 * - Adapted from irisCameraSBIG to ST402
 *
 * Revision 1.29  2005/01/24 15:18:33  tjuerges
 * - Added CVS Log.
 *
 */

#include <irisCameraST402.h>
#include <OS.h>
#include <Time_Value.h>
#include <logging.h>

//Init of static class members
irisCameraST402* irisCameraST402::myself = 0;
int irisCameraST402::reference_counter = 0;

/* Singleton mechanism which is the only
 * possibility the get an instance of this class.
 */
irisCameraST402* irisCameraST402::get_camera(void)
{
  if (irisCameraST402::myself == 0)
  {
    irisCameraST402::myself = new irisCameraST402;
  }

  //Increase the usage counter by one.
  irisCameraST402::reference_counter++;

  //Return the only instance of this class.
  return irisCameraST402::myself;
}

// Hidden constructor, not to be used from outside.
irisCameraST402::irisCameraST402(void)
{
  cam = 0;
  wheel_position = 0;
  camera_dimensions = image_dimensions = start = end = min_start = max_start = min_end = max_end
      = std::pair<long, long>(-9999L, -9999L);
  gain = -9999.9;
  number_of_flushes = 0L;
  camera_running = exposure_running = stop_exposure = false;
  introot_path = ACE_OS::getenv("INTROOT");
  frame_type = 0;
  exposure_time = 0.0;
}

irisCameraST402::~irisCameraST402(void)
{
  //Decrease usage counter by one.
  irisCameraST402::reference_counter--;

  if (irisCameraST402::reference_counter == 0)
  {
    close_camera();
    irisCameraST402::myself = 0;
  }
}

void irisCameraST402::delete_camera(void)
{
  if (cam)
  {
    delete cam;
    cam = 0;
  }
}

bool irisCameraST402::get_camera_temperature(double& temperature) const
{
  bool ret_value(false);
  temperature = -9999.9;

  if (camera_running && (!exposure_running))
  {
    int ret = cam->GetCCDTemperature(temperature);
    if (ret == CE_NO_ERROR)
    {
      ret_value = true;
    }
    else
    {
      temperature = -9999.9;
    }
  }
  else
  {
    temperature = -9999.9;
  }
  return ret_value;
}

bool irisCameraST402::get_air_temperature(double& temperature) const
{
  bool ret_value(false);
  temperature = -9999.9;

  if (camera_running && (!exposure_running))
  {
    if (cam->GetAirTemperature(temperature) == CE_NO_ERROR)
    {
      ret_value = true;
    }
    else
    {
      temperature = -9999.9;
    }
  }
  return ret_value;
}

bool irisCameraST402::set_camera_temperature(const double& temperature)
{
  bool ret_value(false);

  if (camera_running)
  {
    if (exposure_running)
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraST402::set_camera_temperature: Waiting until the current exposure has ended..."));

      timespec wait_time =
      { static_cast<time_t> (0), ACE_ONE_SECOND_IN_NSECS / 1000L };
      while (exposure_running == true)
      {
        ACE_OS::nanosleep(&wait_time);
      };

      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraST402::set_camera_temperature: Current exposure ended. Trying to set wanted temperature..."));
    }

    if (cam->SetTemperatureRegulation(REGULATION_ON, temperature) == CE_NO_ERROR)
    {
      ret_value = true;
    }
  }
  return ret_value;
}

bool irisCameraST402::set_camera_frame_type(const long& _frame_type)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    frame_type = _frame_type;
    ret_value = true;
  }
  return ret_value;
}

bool irisCameraST402::set_camera_exposure_time(const double& exp_time)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    cam->SetExposureTime(exp_time);
    exposure_time = exp_time;
    ret_value = true;
  }
  return ret_value;
}

bool irisCameraST402::start_exposure(void)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    exposure_running = true;

    SHUTTER_COMMAND shutter;
    switch (frame_type)
    {
    case 1L:
      shutter = SC_CLOSE_SHUTTER;
      break;
    default:
      shutter = SC_OPEN_SHUTTER;
      break;
    }

    flush_camera();
    if (cam->StartExposure(shutter) != CE_NO_ERROR)
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraST402::start_exposure: Error while starting. Error message is: %s.", cam->GetErrorString().c_str()));
      abort_exposure();
    }
    else
    {
      stop_exposure = false;
      ret_value = true;
    }
  }
  return ret_value;
}

bool irisCameraST402::wait_for_exposure_done(int& ret) const
{
  bool ret_value(false);

  if (camera_running && exposure_running)
  {
    ret = -1;
    timespec wait_for_exposure_end_time =
    { static_cast<time_t> (0), ACE_ONE_SECOND_IN_NSECS / 1000L };
    MY_LOGICAL complete = false;

    do
    {
      ret = cam->IsExposureComplete(complete);
      ACE_OS::nanosleep(&wait_for_exposure_end_time);
    }
    while ((ret == CE_NO_ERROR) && (!complete) && (stop_exposure == false));

    cam->EndExposure();

    //No error, no abort:
    if ((ret == CE_NO_ERROR) && (stop_exposure == false))
    {
      ret_value = true;
      ret = irisCamera::OK;
    }
    //No error, abort:
    else if ((ret == CE_NO_ERROR) && (stop_exposure == true))
    {
      ret_value = true;
      ret = irisCamera::EXPOSURE_ABORTED;
    }
    //Camera call returned an error:
    else
    {
      ret = irisCamera::EXPOSURE_ERROR;
    }
  }
  else
  {
    ret = irisCamera::EXPOSURE_ERROR;
  }
  return ret_value;
}

void irisCameraST402::abort_exposure(void)
{
  if (camera_running)
  {
    stop_exposure = true;
    cam->EndExposure();
    //Close shutter for security reasons.
    cam->SetShutter(SC_CLOSE_SHUTTER);
    dump_image_data();
    exposure_running = false;
    ACS_SHORT_LOG((LM_INFO, "irisCameraST402::abort_exposure: Exposure aborted."));
  }
}

void irisCameraST402::dump_image_data(void) const
{
  if (camera_running)
  {
    flush_camera();
  }
}

bool irisCameraST402::download_image_from_camera(std::vector<unsigned short int>* myArray)
{
  bool ret_value(false);

  if (camera_running && exposure_running)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraST402::download_image_from_camera: Start image download from camera."));
    long size(0L);

    if ((get_image_size(size) == true) && (myArray->size() == static_cast<std::size_t> (size)))
    {
      // Make the temp regulation really quiet.
      cam->SetTemperatureRegulation(REGULATION_ENABLE_AUTOFREEZE, 0.0);

      ReadoutLineParams rop;
      rop.ccd = cam->GetActiveCCD();
      rop.pixelStart = static_cast<unsigned short> (start.first);
      rop.pixelLength = static_cast<unsigned short> (end.first);
      rop.readoutMode = cam->GetReadoutMode();

      long row;
      int ret(CE_NO_ERROR);

      /*
       * StartReaout discards startY lines (o based). So
       * no DumpLines call is needed.
       *
       */
      ret = cam->StartReadout(static_cast<unsigned short> (start.first),
          static_cast<unsigned short> (start.second),
          static_cast<unsigned short> (image_dimensions.first),
          static_cast<unsigned short> (image_dimensions.second));

      for (row = 0; (row < image_dimensions.second) && (ret == CE_NO_ERROR); row++)
      {
        ret = cam->FastReadoutLine(&rop, &((*myArray)[row * image_dimensions.first]));
      }

      cam->EndReadout();

      if (ret != CE_NO_ERROR)
      {
        ACS_SHORT_LOG(
            (LM_ERROR, "irisCameraST402::download_image_from_camera: The camera returned an error while downloading row %d. Download aborted!", row));
      }
      else
      {
        ACS_SHORT_LOG((LM_INFO, "irisCameraST402::download_image_from_camera: Download complete."));
        ret_value = true;
      }
      // Let the temp regulation rant around the clock.
      cam->SetTemperatureRegulation(REGULATION_DISABLE_AUTOFREEZE, 0.0);
    }
    else
    {
      dump_image_data();
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraST402::download_image_from_camera: Not enough memory for temporary image data. Download aborted!"));
    }
  }

  exposure_running = false;
  return ret_value;
}

bool irisCameraST402::set_image_dimensions(std::pair<long, long>& new_start,
    std::pair<long, long>& new_end)
{
  bool ret_value(false);

  if (camera_running && !(exposure_running))
  {
    if (check_image_dimensions(new_start, new_end) == false)
    {
      start = new_start;
      end = new_end;
      image_dimensions.first = end.first - start.first + 1L;
      image_dimensions.second = end.second - start.second + 1L;
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraST402::set_image_dimensions: Setting new image dimensions successful. New image dimensions: (x0,y0)=%d,%d (x1,y1)=%d,%d.", start.first, start.second, end.first, end.second));
    }
    ret_value = true;
  }
  return ret_value;
}

bool irisCameraST402::load_sbig_kernel_modules(void)
{
  /* Hack for loading firmware up into SBIG-USB cameras
   * and for loading the SBIG kernel modules.
   */
  std::string command;
  command = "chmod a+x " + introot_path;
  command += "/bin/fxload";
  if (ACE_OS::system(command.c_str()) < 0)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraST402::load_sbig_kernel_modules: Cannot chmod a+x $INTROOT/bin/fxload. Aborting!"));
    return false;
  }

  command = "/bin/sh " + introot_path;
  command += "/bin/sbig_load_firmware.sh";
  if (ACE_OS::system(command.c_str()) < 0)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraST402::load_sbig_kernel_modules: Cannot execute sbig_load_firmware.sh. Aborting!"));
    return false;
  }

  command = "/bin/sh " + introot_path;
  command += "/bin/load_lpt.sh";
  if (ACE_OS::system(command.c_str()) < 0)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraST402::load_sbig_kernel_modules: Cannot execute load_lpt.sh for the parallel port SBIG kernel modules. Aborting!"));
    return false;
  }

  command = "/bin/sh " + introot_path;
  command += "/bin/load_usb.sh";
  if (ACE_OS::system(command.c_str()) < 0)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraST402::load_sbig_kernel_modules: Cannot execute load_usb.sh for the USB SBIG kernel modules. Unloading kernel modules and aborting!"));
    return false;
  }

  //Chmod a+rw /dev/rtc for setting and reading the hardware clock.
  command = "chmod a+rw /dev/rtc";
  if (ACE_OS::system(command.c_str()) < 0)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraST402::load_sbig_kernel_modules: Cannot chmod /dev/rtc. Aborting!"));
    return false;
  }

  return true;
}

void irisCameraST402::unload_sbig_kernel_modules(void)
{
  /* Hack for unloading the SBIG kernel modules.
   */
  std::string command("/bin/sh ");

  command += introot_path;
  command += "/bin/unload_usb.sh";
  if (ACE_OS::system(command.c_str()) < 0)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraST402::unload_sbig_kernel_modules: Cannot execute unload_usb.sh for the USB SBIG kernel modules. Aborting!"));
  }

  command = "/bin/sh " + introot_path;
  command += "/bin/unload_lpt.sh";
  if (ACE_OS::system(command.c_str()) < 0)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraST402::unload_sbig_kernel_modules: Cannot execute load_lpt.sh for the parallel port SBIG kernel modules. Aborting!"));
  }
}

int irisCameraST402::find_camera(void)
{
  int ret(irisCamera::NO_CAMERA_FOUND);

  if (introot_path.size() == 0)
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCameraST402::find_camera: This client needs to know the environment variable $INTROOT, but received nothing. Aborting!"));
    return ret;
  }

  if (load_sbig_kernel_modules() != true)
  {
    return ret;
  }

  // Try USB cam.
  cam = new CSBIGCam(DEV_USB);

  if (cam->GetError() != CE_NO_ERROR)
  {
    ACS_SHORT_LOG((LM_ERROR, "irisCameraST402::find_camera: Cannot open SBIG camera on USB."));
    delete_camera();
  }
  else // O.k.: camera detected on USB, connect with it.
  {
    cam->EstablishLink();
    if (cam->GetError() == CE_NO_ERROR)
    {
      ACS_SHORT_LOG((LM_INFO, "irisCameraST402::find_camera: Camera on USB found and connected."));
      ret = irisCamera::OK;
    }
    else
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraST402::find_camera: Cannot connet to SBIG camera on USB."));
      delete_camera();
    }
  }
  return ret;
}

int irisCameraST402::open_camera(void)
{
  int ret(irisCamera::OK);

  if (!camera_running)
  {
    ret = find_camera();

    if (ret != irisCamera::OK)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraST402::open_camera: No SBIG camera found."));
      unload_sbig_kernel_modules();
      return ret;
    }

    cam->SetActiveCCD(CCD_IMAGING); // Use imaging CCD.
    cam->SetABGState(ABG_LOW7); // Anti blooming is off. ST9[E]: No ABG!
    cam->SetReadoutMode(0); // ST9[E]: No binning, 512*512.

    // Check driver info.
    GetDriverInfoResults0 info0;

    if (cam->GetDriverInfo(DRIVER_STD, info0) == CE_NO_ERROR)
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraST402::open_camera: Library version: %d, library name: %s, number of maximum requests at a time=%d.", info0.version, info0.name, info0.maxRequest));
    }
    else
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraST402::open_camera: GetDriverInfo failed."));
      delete_camera();
      return irisCamera::HARDWARE_ERROR;
    }

    // Check CCD info.
    GetCCDInfoParams getccd_parms;
    getccd_parms.request = CCD_INFO_IMAGING; // Check info only for imaging CCD.
    GetCCDInfoResults0 info1;

    if (cam->SBIGUnivDrvCommand(static_cast<short> (CC_GET_CCD_INFO),
        static_cast<void*> (&getccd_parms), static_cast<void*> (&info1)) != CE_NO_ERROR)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraST402::open_camera: Cannot get camera driver info."));
      delete_camera();
      return irisCamera::HARDWARE_ERROR;
    }
    else
    {
      pixelSize = std::pair<double, double>(cam->hex2double(info1.readoutInfo[0].pixelWidth),
          cam->hex2double(info1.readoutInfo[0].pixelHeight));
      pixelSize.first /= 1E6;
      pixelSize.second /= 1E6;
      gain = cam->hex2double(info1.readoutInfo[0].gain);

      start = min_start = std::pair<long, long>(0L, 0L);
      end.first = max_end.first = static_cast<long> (info1.readoutInfo[0].width) - 1L;
      end.second = max_end.second = static_cast<long> (info1.readoutInfo[0].height) - 1L;
      max_start.first = max_end.first - 1L;
      max_start.second = max_end.second - 1L;
      min_end.first = min_start.first + 1L;
      min_end.second = min_start.second + 1L;

      camera_dimensions = image_dimensions = std::pair<long, long>(info1.readoutInfo[0].width,
          info1.readoutInfo[0].height);
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraST402::open_camera: Imaging width=%d, height=%d, gain=%g.", image_dimensions.first, image_dimensions.second, gain));
    }

    if (cam->SetTemperatureRegulation(REGULATION_ON, 0.0) != CE_NO_ERROR)
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraST402::open_camera: Cannot enable temperature regulation. Keep an eye on the image quality! Continuing anyway."));
    }
    else
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraST402::open_camera: Temperature regulation is enabled and set to 0.0�C."));
    }

    ret = irisCamera::OK;
    camera_running = true;
    // Everything initialized.
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCameraST402::open_camera: Check hardware, camera already active."));
    return HARDWARE_ERROR;
  }
  return ret;
}

int irisCameraST402::close_camera(void)
{
  stop_exposure = true;
  if (exposure_running)
  {
    abort_exposure();
  }

  if (cam != 0)
  {
    cam->SetTemperatureRegulation(REGULATION_OFF, 20.0);
  }

  delete_camera();
  camera_running = false;

  unload_sbig_kernel_modules();

  return (irisCamera::OK | irisCamera::CAMERA_OFF);
}

bool irisCameraST402::set_number_of_flushes(const long& _number_of_flushes)
{
  if (camera_running && (!exposure_running))
  {
    number_of_flushes = _number_of_flushes;
    return true;
  }
  return false;
}

void irisCameraST402::flush_camera(void) const
{
  for (long i = number_of_flushes; i > 0; --i)
  {
    discard_ccd_lines(image_dimensions.second);
  }
}

void irisCameraST402::discard_ccd_lines(const long& number_of_lines) const
{
  if (cam->DumpLines(static_cast<unsigned short int> (number_of_lines)) != CE_NO_ERROR)
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCameraST402::discard_ccd_lines: %s. Occured while discarding unused CCD lines.", cam->GetErrorString().c_str()));
  }
}

CORBA::Long irisCameraST402::init_wheel(void)
{
  CORBA::Long ret(-1L);

  if (camera_running)
  {
    CFWParams cfw_in;
    CFWResults cfw_out;

    cfw_in.cfwModel = CFWSEL_AUTO;
    cfw_in.cfwCommand = CFWC_GOTO;
    cfw_in.cfwParam1 = CFWP_1;

    if (cam->CFWCommand(cfw_in, cfw_out) != CE_NO_ERROR)
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraST402::init_wheel: Cannot get filter wheel info. Error is: %s.\n Trying CFW-8...", cam->GetErrorString().c_str()));

      cfw_in.cfwModel = CFWSEL_CFW8;
      cfw_in.cfwCommand = CFWC_GOTO;
      cfw_in.cfwParam1 = CFWP_1;

      if (cam->CFWCommand(cfw_in, cfw_out) != CE_NO_ERROR)
      {
        wheel_type = CFWSEL_UNKNOWN;
        wheel_position = CFWP_UNKNOWN;
        ACS_SHORT_LOG(
            (LM_ERROR, "irisCameraST402::init_wheel: Cannot get filter wheel info for CFW-8. Error is: %s.", cam->GetErrorString().c_str()));
        return ret;
      }
    }

    wheel_type = cfw_out.cfwModel;
    wheel_position = cfw_in.cfwParam1;
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraST402::init_wheel: Filter wheel initialized and on position %d.", wheel_position));
    ret = static_cast<CORBA::Long> (wheel_position);
  }
  return ret;
}

CORBA::Long irisCameraST402::exit_wheel(void)
{
  CORBA::Long ret(-1L);

  if (camera_running)
  {
    CFWParams cfw_in;
    CFWResults cfw_out;

    cfw_in.cfwModel = wheel_type;
    cfw_in.cfwCommand = CFWC_GOTO;
    cfw_in.cfwParam1 = CFWP_1;

    if (cam->CFWCommand(cfw_in, cfw_out) != CE_NO_ERROR)
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraST402::exit_wheel: Cannot move filter wheel to position 1. Error is: %s", cam->GetErrorString().c_str()));
    }
    else
    {
      wheel_position = cfw_in.cfwParam1;
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraST402::exit_wheel: Filter wheel moved to position %d, exit.", wheel_position));
      ret = static_cast<CORBA::Long> (wheel_position);
    }
  }
  return ret;
}

CORBA::Long irisCameraST402::move_wheel_up(void)
{
  CORBA::Long ret(-1L);

  if (camera_running)
  {
    CFWParams cfw_in;
    CFWResults cfw_out;

    cfw_in.cfwModel = wheel_type;
    cfw_in.cfwCommand = CFWC_GOTO;
    //STL & CFW8 models have 5 positions
    cfw_in.cfwParam1 = (wheel_position >= CFWP_5 ? CFWP_1 : wheel_position + 1);

    if (cam->CFWCommand(cfw_in, cfw_out) != CE_NO_ERROR)
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraST402::move_wheel_up: Cannot move filter wheel to position %d. Error is: %s", cfw_in.cfwParam1, cam->GetErrorString().c_str()));
    }
    else
    {
      wheel_position = cfw_in.cfwParam1;
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraST402::move_wheel_up: Filter wheel moved to position %d.", wheel_position));
      ret = static_cast<CORBA::Long> (wheel_position);
    }
  }
  return ret;
}

CORBA::Long irisCameraST402::move_wheel_down(void)
{
  CORBA::Long ret(-1L);

  if (camera_running)
  {
    CFWParams cfw_in;
    CFWResults cfw_out;

    cfw_in.cfwModel = wheel_type;
    cfw_in.cfwCommand = CFWC_GOTO;
    //STL & CFW8 models have 5 positions
    cfw_in.cfwParam1 = (wheel_position > CFWP_1 ? wheel_position - 1 : CFWP_5);

    if (cam->CFWCommand(cfw_in, cfw_out) != CE_NO_ERROR)
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraST402::move_wheel_down: Cannot move filter wheel to position %d. Error is: %s", cfw_in.cfwParam1, cam->GetErrorString().c_str()));
    }
    else
    {
      wheel_position = cfw_in.cfwParam1;
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraST402::move_wheel_down: Filter wheel moved to position %d.", wheel_position));
      ret = static_cast<CORBA::Long> (wheel_position);
    }
  }
  return ret;
}

CORBA::Long irisCameraST402::move_wheel_to(CORBA::Long _position)
{
  CORBA::Long ret(-1L);

  if (camera_running)
  {
    unsigned short int position(static_cast<unsigned short int> (_position) + 1);
    //STL & CFW8 models have 5 positions
    if ((position >= CFWP_1) && (position <= CFWP_5))
    {
      CFWParams cfw_in;
      CFWResults cfw_out;

      cfw_in.cfwModel = wheel_type;
      cfw_in.cfwCommand = CFWC_GOTO;
      cfw_in.cfwParam1 = static_cast<unsigned short int> (position);

      if (cam->CFWCommand(cfw_in, cfw_out) != CE_NO_ERROR)
      {
        ACS_SHORT_LOG(
            (LM_ERROR, "irisCameraST402::move_wheel_to: Cannot move filter wheel to position %d. Error is: %s", cfw_in.cfwParam1, cam->GetErrorString().c_str()));
      }
      else
      {
        wheel_position = cfw_in.cfwParam1;
        ACS_SHORT_LOG(
            (LM_INFO, "irisCameraST402::move_wheel_to: Filter wheel moved to position %d.", wheel_position));
        ret = static_cast<CORBA::Long> (wheel_position);
      }
    }
    else
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraST402::move_wheel_to: Cannot move filter wheel to position %d. Position has to be (0<=position<=4)!", position));
    }
  }
  return ret;
}

CORBA::Long irisCameraST402::get_wheel_position(void) const
{
  if (camera_running)
  {
    return static_cast<CORBA::Long> (wheel_position);
  }
  return static_cast<CORBA::Long> (-1L);
}
