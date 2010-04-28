/*
 * "@(#) $Id: irisCameraFLI.cpp,v 1.21  2010/01/11 12:31:12  mparra Exp $"
 *
 * $Log: irisCameraFLI.cpp,v $
 * Revision 1.21  2010/01/11 12:31:12  mparra
 * - Adapted to IRIS telescope.
 *
 * Revision 1.20  2005/02/08 20:59:11  hptmgr
 * *** empty log message ***
 *
 * Revision 1.19  2005/01/24 15:18:33  tjuerges
 * - Added CVS Log.
 *
 * Revision 1.18  2005/01/20 18:17:59  tjuerges
 * - Replaced std::make_pair by ctor std::pair<T,T>.
 *
 * Revision 1.17  2005/01/20 15:08:55  tjuerges
 * - Changed to usage of std::pair containers for data which occurs in pairs like pixel size,
 * 	image dimensions, camera dimensions, image widht/height etc.
 * - Moved some error checking from creation of simulated stars to irisCameraSimulator module. This
 * 	made it possible to have a kind of windowing a.k.a. sub frames.
 *
 *
 */

#include <irisCameraFLI.h>
#include <OS.h>
#include <Time_Value.h>
#include <logging.h>
#include <string>
#include <utility>
#include <functional>

//Init of static class members
irisCameraFLI* irisCameraFLI::myself = 0;
int irisCameraFLI::reference_counter = 0;

/* Singleton mechanism which is the only
 * possibility the get an instance of this class.
 */
irisCameraFLI* irisCameraFLI::get_camera(void)
{
  if (irisCameraFLI::myself == 0)
  {
    irisCameraFLI::myself = new irisCameraFLI;
  }

  //Increase the usage counter by one.
  irisCameraFLI::reference_counter++;

  //Return the only instance of this class.
  return irisCameraFLI::myself;
}

// Hidden constructor, not to be used from outside.
irisCameraFLI::irisCameraFLI(void)
{
  cam = 0;
  dev = wheel_device = 0;
  camera_dimensions = image_dimensions = start = end = min_start = max_start = min_end = max_end
      = std::pair<long, long>(-9999L, -9999L);
  gain = -9999.9;
  number_of_flushes = 0L;
  wheel_position = 0L;
  camera_running = exposure_running = stop_exposure = false;
}

irisCameraFLI::~irisCameraFLI(void)
{
  //Decrease usage counter by one.
  irisCameraFLI::reference_counter--;

  if (irisCameraFLI::reference_counter == 0)
  {
    close_camera();
    irisCameraFLI::myself = 0;
  }
}

bool irisCameraFLI::get_camera_temperature(double& temperature) const
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    int ret = FLIGetTemperature(dev, &temperature);
    if (ret == 0)
    {
      ret_value = true;
    }
  }
  else
  {
    temperature = -9999.9;
  }
  return ret_value;
}

bool irisCameraFLI::get_air_temperature(double& temperature) const
{
  temperature = -9999.9;
  return false;
}

bool irisCameraFLI::set_camera_temperature(const double& temperature)
{
  bool ret_value(false);

  if (camera_running)
  {
    if (exposure_running)
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraFLI::set_camera_temperature: Waiting until the current exposure has ended..."));

      timespec wait_time =
      { static_cast<time_t> (0), ACE_ONE_SECOND_IN_NSECS / 1000L };
      while (exposure_running == true)
      {
        ACE_OS::nanosleep(&wait_time);
      };

      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraFLI::set_camera_temperature: Current exposure ended. Trying to set wanted temperature..."));
    }

    int ret(FLISetTemperature(dev, temperature));
    if (ret == 0)
    {
      ret_value = true;
    }
  }

  return ret_value;
}

bool irisCameraFLI::set_camera_frame_type(const long& frame_type)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    switch (frame_type)
    {
    case 1L:
      if (FLISetFrameType(dev, FLI_FRAME_TYPE_DARK) == 0)
      {
        ret_value = true;
      }
      break;
    default:
      if (FLISetFrameType(dev, FLI_FRAME_TYPE_NORMAL) == 0)
      {
        ret_value = true;
      }
      break;
    }
  }
  return ret_value;
}

bool irisCameraFLI::set_camera_exposure_time(const double& exp_time)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    if (FLISetExposureTime(dev, static_cast<long> (exp_time * 1000.0)) == 0)
    {
      ret_value = true;
    }
  }
  return ret_value;
}

bool irisCameraFLI::start_exposure(void)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    exposure_running = true;
    int ret(FLIExposeFrame(dev));

    if (ret != 0)
    {
      abort_exposure();
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraFLI::start_exposure: Error while starting. Exposure aborted!"));
    }
    else
    {
      stop_exposure = false;
      ret_value = true;
    }
  }
  return ret_value;
}

bool irisCameraFLI::wait_for_exposure_done(int& ret) const
{
  bool ret_value(false);

  if (camera_running && exposure_running)
  {
    ret = -1;
    long time_left(-1L);
    timespec wait_for_exposure_end_time =
    { static_cast<time_t> (0), ACE_ONE_SECOND_IN_NSECS / 1000L };

    do
    {
      /* The next call returs as time_left the number of
       milli seconds until exposure is done.
       */
      ret = FLIGetExposureStatus(dev, &time_left);
      ACE_OS::nanosleep(&wait_for_exposure_end_time);
    }
    while ((time_left > 0L) && (stop_exposure == false) && (ret == 0));

    //No error, no abort:
    if ((ret == 0) && (stop_exposure == false))
    {
      ret_value = true;
      ret = irisCamera::OK;
    }
    //No error, abort:
    else if ((ret == 0) && (stop_exposure == true))
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

void irisCameraFLI::abort_exposure(void)
{
  if (camera_running)
  {
    stop_exposure = true;
    FLICancelExposure(dev);
    //Close shutter for security reasons.
    FLIControlShutter(dev, FLI_SHUTTER_CLOSE);
    dump_image_data();
    exposure_running = false;
    ACS_SHORT_LOG((LM_INFO, "irisCameraFLI::abort_exposure: Exposure aborted."));
  }
}

void irisCameraFLI::dump_image_data(void) const
{
  if (camera_running)
  {
    int ret(FLIFlushRow(dev, image_dimensions.second, (number_of_flushes > 0 ? number_of_flushes
        : 1L)));
    if (ret != 0)
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraFLI::dump_image_data: Something went wrong while flushing the CCD."));
    }
  }
}

bool irisCameraFLI::download_image_from_camera(std::vector<unsigned short int>* myArray)
{
  bool ret_value(false);

  if (camera_running && exposure_running)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraFLI::download_image_from_camera: Start image download from camera."));

    long size(0L);
    ret_value = get_image_size(size);

    if ((ret_value == true) && (myArray->size() == static_cast<std::size_t> (size)))
    {
      int ret(0);
      long row(0L);
      /*
       * tmp_height, tmp_width:
       * The FLI driver needs to have the number of
       * rows and columns passed to FLIGrabRow to be one
       * less than they really are. Design or bug?
       */
      const std::pair<long, long>
          tmp_dim(image_dimensions.first - 1L, image_dimensions.second - 2L);
      for (row = 0; (row <= tmp_dim.second) && (ret == 0); row++)
      {
        ret = FLIGrabRow(dev, &((*myArray)[row * image_dimensions.first]), tmp_dim.first);
      }

      if (ret != 0)
      {
        ACS_SHORT_LOG(
            (LM_ERROR, "irisCameraFLI::download_image_from_camera: The camera returned an error while downloading row %d. Download aborted!", row));
      }
      else
      {
        ACS_SHORT_LOG((LM_INFO, "irisCameraFLI::download_image_from_camera: Download complete."));
        ret_value = true;
      }
    }
    else
    {
      dump_image_data();
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraFLI::download_image_from_camera: Not enough memory for temporary image data. Download aborted!"));
    }
  }

  exposure_running = false;
  return ret_value;
}

bool irisCameraFLI::set_image_dimensions(std::pair<long, long>& new_start,
    std::pair<long, long>& new_end)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    if (check_image_dimensions(new_start, new_end) == false)
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraFLI::set_image_dimensions: Trying to set image dimensions to (x0,y0)=%d,%d (x1,y1)=%d,%d.", new_start.first, new_start.second, new_end.first, new_end.second));

      int ret(FLISetImageArea(dev, new_start.first + 14L, new_start.second + 4L, new_end.first
          + 14L, new_end.second + 4L));

      if (ret != 0)
      {
        // Oops, an error! Restore old values.
        ret = FLISetImageArea(dev, start.first + 14L, start.second + 4L, end.first + 14L,
            end.second + 4L);
        new_start = start;
        new_end = end;
        ACS_SHORT_LOG(
            (LM_ERROR, "irisCameraFLI::set_image_dimensions: Setting new image dimensions failed! Using old image dimensions: (x0,y0)=%d,%d (x1,y1)=%d,%d.", start.first, start.second, end.first, end.second));
      }
      else
      {
        start = new_start;
        end = new_end;
        image_dimensions.first = end.first - start.first + 1L;
        image_dimensions.second = end.second - start.second + 1L;
        ACS_SHORT_LOG(
            (LM_INFO, "irisCameraFLI::set_image_dimensions: Setting new image dimensions successful. New image dimensions: (x0,y0)=%d,%d (x1,y1)=%d,%d.", start.first, start.second, end.first, end.second));

        ret_value = true;
      }
    }
    else
    {
      ret_value = true;
    }
  }
  return ret_value;
}

int irisCameraFLI::find_camera(cam_t** cam, int& numcams, char* camera_name)
{
  char **tmplist;
  int ret(irisCamera::NO_CAMERA_FOUND);

  if (FLIList(FLIDOMAIN_USB | FLIDEVICE_CAMERA, &tmplist) != 0)
  {
    FLIFreeList(tmplist);
    return ret;
  }

  if ((tmplist != 0) && (tmplist[0] != 0))
  {
    int cams(0);

    for (int i = 0; tmplist[i] != 0; i++)
    {
      cams++;
    }

    *cam = static_cast<cam_t*> (ACE_OS::realloc(*cam, cams * sizeof(cam_t)));
    if (cam == 0)
    {
      ret = irisCamera::NO_REALLOC;
      FLIFreeList(tmplist);
      return ret;
    }

    for (int i = 0; tmplist[i] != 0; i++)
    {
      for (int j = 0; tmplist[i][j] != '\0'; j++)
      {
        if (tmplist[i][j] == ';')
        {
          tmplist[i][j] = '\0';
          break;
        }
      }

      ACE_OS::strcpy(camera_name, tmplist[i]);
      if (FLIOpen(&dev, camera_name, FLIDEVICE_CAMERA | FLIDOMAIN_USB) != 0)
      {
        dev = 0;
        ret = irisCamera::NO_CAMERA_FOUND;
        continue;
      }
      else
      {
        ret = irisCamera::OK;
      }
    }
  }
  FLIFreeList(tmplist);

  return ret;
}

int irisCameraFLI::open_camera(void)
{
  if (!camera_running)
  {
    cam = 0;
    char camera_name[256];
    int numcams(0);
    char libversion[256];

    if (FLISetDebugLevel(0, FLIDEBUG_NONE) != 0)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraFLI::open_camera: Cannot set FLI library debug level."));
      return irisCamera::CCD_LIBRARY_ERROR;
    }

    if (FLIGetLibVersion(libversion, 256) != 0)
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraFLI::open_camera: FLI library did not return its version."));
      return irisCamera::CCD_LIBRARY_ERROR;
    }

    /* Hack for USB hotplugging.
     * Any newly attached devices are created in:
     * /proc/bus/usb/THRRE_DIGIT_NUMBER_OF_HUB/THREEDIGIT_NUMBER_OF_DEVICE
     * The permissions are rw-r--r-- and root.root.
     * Change to rw-rw-rw.
     */
    std::string* chmod_command = new std::string(
        "find /proc/bus/usb/\?\?\?/* -name '\?\?\?' -not -name '001' -exec chmod a+rw {} \\;\0");
    int ret(ACE_OS::system(chmod_command->c_str()));
    delete chmod_command;

    if (ret < 0)
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraFLI::open_camera: Could not change permissions in /proc/bus/usb/\?\?\?/\?\?\?. Check suid and guid bits of chmod!\nModify permissions on the camera device (dmesg) by hand and run onAction again!\nThis is NOT critical as long as you follow above instructions. The camera is NOT inititlaized and NOT connected to ACS."));
      return irisCamera::NO_CAMERA_FOUND;
    }

    if (find_camera(&cam, numcams, camera_name) != irisCamera::OK)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraFLI::open_camera: No FLI camera on USB bus found."));
      return irisCamera::NO_CAMERA_FOUND;
    }

    ACS_SHORT_LOG((LM_INFO, "irisCameraFLI::open_camera: FLI camera on USB bus found."));

    double size_x(0.0), size_y(0.0);
    if (FLIGetPixelSize(dev, &size_x, &size_y) != 0)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraFLI::open_camera: Cannot get pixel size."));
      close_camera();
      return irisCamera::HARDWARE_ERROR;
    }
    else
    {
      //Thomas: Used if FLI fix their camera library. :-(
      //xPixelSize=size_x;
      //yPixelSize=size_y;
      pixelSize = std::pair<double, double>(9.0E-6, 9.0E-6);
    }

    long x0(0L), y0(0L), x1(0L), y1(0L);
    if (FLIGetArrayArea(dev, &x0, &y0, &x1, &y1) != 0)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraFLI::open_camera: Cannot get array area."));
      close_camera();
      return irisCamera::HARDWARE_ERROR;
    }
    else
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraFLI::open_camera: Array area: (x0,y0)=%d,%d (x1,y1)=%d,%d", x0, y0, x1, y1));
    }

    long X0(0L), Y0(0L), X1(0L), Y1(0L);
    if (FLIGetVisibleArea(dev, &X0, &Y0, &X1, &Y1) != 0)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraFLI::open_camera: Cannot get visible area."));
      close_camera();
      return irisCamera::HARDWARE_ERROR;
    }
    else
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraFLI::open_camera: Visible array area: (x0,y0)=%d,%d (x1,y1)=%d,%d", X0, Y0, X1, Y1));
    }

    if (FLISetImageArea(dev, X0, Y0, X1, Y1) != 0)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraFLI::open_camera: Cannot set imaging area."));
      close_camera();
      return irisCamera::HARDWARE_ERROR;
    }
    else
    {
      start = min_start = std::pair<long, long>(X0 - 14L, Y0 - 4L);
      end = max_end = std::pair<long, long>(X1 - 1L, Y1 - 1L);
      max_start.first = max_end.first - 1L;
      max_start.second = max_end.second - 1L;
      min_end.first = min_start.first + 1L;
      min_end.second = min_start.second + 1L;
      camera_dimensions.first = image_dimensions.first = end.first - start.first + 1L;
      camera_dimensions.second = image_dimensions.second = end.second - start.second + 1L;
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraFLI::open_camera: Imaging width=%d, height=%d.", image_dimensions.first, image_dimensions.second));
    }

    if (FLISetHBin(dev, 1) != 0)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraFLI::open_camera: Cannot set horizontal binning."));
      close_camera();
      return irisCamera::HARDWARE_ERROR;
    }

    if (FLISetVBin(dev, 1) != 0)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraFLI::open_camera: Cannot set horizontal binning."));
      close_camera();
      return irisCamera::HARDWARE_ERROR;
    }

    camera_running = true;
    return irisCamera::OK;
  }
  else
  {
    ACS_SHORT_LOG((LM_ERROR, "irisCameraFLI::open_camera: Check hardware, camera already active."));
    close_camera();
    return irisCamera::HARDWARE_ERROR;
  }
}

int irisCameraFLI::close_camera(void)
{
  stop_exposure = true;
  if (exposure_running)
  {
    abort_exposure();
  }

  if (dev != 0)
  {
    FLIClose(dev);
    dev = 0;
  }

  if (cam != 0)
  {
    ACE_OS::free(cam);
    cam = 0;
  }

  camera_running = false;
  return (irisCamera::OK | irisCamera::CAMERA_OFF);
}

bool irisCameraFLI::set_number_of_flushes(const long& _number_of_flushes)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    if (FLISetNFlushes(dev, _number_of_flushes) == 0)
    {
      number_of_flushes = _number_of_flushes;
      ret_value = true;
    }
  }
  return ret_value;
}

CORBA::Long irisCameraFLI::init_wheel(void)
{
  CORBA::Long ret(-1);

  if (camera_running)
  {
  }
  return ret;
}

CORBA::Long irisCameraFLI::exit_wheel(void)
{
  CORBA::Long ret(-1);

  if (camera_running)
  {
  }
  return ret;
}

CORBA::Long irisCameraFLI::move_wheel_up(void)
{
  CORBA::Long ret(-1);

  if (camera_running)
  {
  }
  return ret;
}

CORBA::Long irisCameraFLI::move_wheel_down(void)
{
  CORBA::Long ret(-1);

  if (camera_running)
  {
  }
  return ret;
}

CORBA::Long irisCameraFLI::move_wheel_to(CORBA::Long position)
{
  CORBA::Long ret(-1);

  if (camera_running)
  {
  }
  return ret;
}

CORBA::Long irisCameraFLI::get_wheel_position(void) const
{
  if (camera_running)
  {
    return static_cast<CORBA::Long> (wheel_position);
  }
  return CORBA::Long(-1);
}
