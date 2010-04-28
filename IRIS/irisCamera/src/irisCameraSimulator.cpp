/*
 * "@(#) $Id: irisCameraSimulator.cpp,v 1.20  2010/01/07 23:56:18  mparra Exp $"
 *
 * $Log: irisCameraSimulator.cpp,v $
 * Revision 1.20  2010/01/07 23:56:18  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.19  2005/02/11 15:27:11  tjuerges
 * - Added possibility to create stars which are outside the CCD window. Now these stars do not generate an error but are silently ignored.
 *
 * Revision 1.18  2005/01/27 13:40:34  tjuerges
 * - Fixed bug in wait method: waited 10 times of the wanted time.
 *
 * Revision 1.17  2005/01/20 18:18:44  tjuerges
 * - Improvements for empty list of simulated stars. Then create a dark.
 *
 * Revision 1.16  2005/01/20 15:08:55  tjuerges
 * - Changed to usage of std::pair containers for data which occurs in pairs like pixel size,
 * 	image dimensions, camera dimensions, image widht/height etc.
 * - Moved some error checking from creation of simulated stars to irisCameraSimulator module. This
 * 	made it possible to have a kind of windowing a.k.a. sub frames.
 *
 *
 */

#include <irisCameraSimulator.h>
#include <irisCameraSimulatorCreateStarData.h>
#include <irisStarUtils.h>
#include <OS.h>
#include <Time_Value.h>
#include <logging.h>
#include <utility>

//Init of static class members
irisCameraSimulator* irisCameraSimulator::myself = 0;
int irisCameraSimulator::reference_counter = 0;

/* Singleton mechanism which is the only
 * possibility the get an instance of this class.
 */
irisCameraSimulator* irisCameraSimulator::get_camera(void)
{
  if (irisCameraSimulator::myself == 0)
  {
    irisCameraSimulator::myself = new irisCameraSimulator;
  }

  //Increase the usage counter by one.
  irisCameraSimulator::reference_counter++;

  //Return the only instance of this class.
  return irisCameraSimulator::myself;
}

// Hidden constructor, not to be used from outside.
irisCameraSimulator::irisCameraSimulator(void)
{
  camera_dimensions = image_dimensions = start = end = min_start = max_start = min_end = max_end
      = std::pair<long, long>(-9999L, -9999L);
  gain = 1.297016861;
  number_of_flushes = 0L;
  camera_running = exposure_running = stop_exposure = false;
  image_data = 0;
  simulationPosition = new std::vector<std::pair<double, double> >;
  simulationAmplitude = new std::vector<double>;
}

irisCameraSimulator::~irisCameraSimulator(void)
{
  //Decrease usage counter by one.
  irisCameraSimulator::reference_counter--;

  if (irisCameraSimulator::reference_counter == 0)
  {
    close_camera();
    irisCameraSimulator::myself = 0;
    delete simulationAmplitude;
    delete simulationPosition;
  }
}

bool irisCameraSimulator::get_camera_temperature(double& temperature) const
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    temperature = ccd_temperature;
    ret_value = true;
  }
  else
  {
    temperature = -9999.9;
  }
  return ret_value;
}

bool irisCameraSimulator::get_air_temperature(double& temperature) const
{
  temperature = -9999.9;
  return false;
}

bool irisCameraSimulator::set_camera_temperature(const double& temperature)
{
  bool ret_value(false);

  if (camera_running)
  {
    if (exposure_running)
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraSimulator::set_camera_temperature: Waiting until the current exposure has ended..."));

      timespec wait_time =
      { static_cast<time_t> (0), ACE_ONE_SECOND_IN_NSECS / 1000L };
      while (exposure_running == true)
      {
        ACE_OS::nanosleep(&wait_time);
      };

      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraSimulator::set_camera_temperature: Current exposure ended. Trying to set wanted temperature..."));
    }

    ccd_temperature = temperature;
    ret_value = true;
  }
  return ret_value;
}

bool irisCameraSimulator::set_camera_frame_type(const long& _frame_type)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    frame_type = _frame_type;
    ret_value = true;
  }
  return ret_value;
}

bool irisCameraSimulator::set_camera_exposure_time(const double& exp_time)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    exposure_time = exp_time;
    ret_value = true;
  }
  return ret_value;
}

bool irisCameraSimulator::start_exposure(void)
{
  bool ret_value(false);

  if ((camera_running) && (!exposure_running))
  {
    exposure_running = true;
    bool ret(false), do_it(true);
    try
    {
      if (exposure_time == 0.0)
      {
        simulationPosition->resize(0);
        simulationFwhm = std::pair<double, double>(0.0, 0.0);
        simulationAmplitude->resize(0);
      }
      else if (frame_type != 0L)
      {
        simulationPosition->resize(0);
        simulationFwhm = std::pair<double, double>(0.0, 0.0);
        simulationAmplitude->resize(0);
      }
      else if (simulationPosition->size() > 0)
      {
        const std::pair<double, double> tmp_start(start), tmp_end(end);

        std::vector<double>::iterator amplitudeIterator(simulationAmplitude->begin());
        for (std::vector<std::pair<double, double> >::iterator positionIterator(
            simulationPosition->begin()); positionIterator != simulationPosition->end(); ++positionIterator, ++amplitudeIterator)
        {
          if (((*positionIterator) < tmp_start) || ((*positionIterator) > tmp_end))
          {
            simulationPosition->erase(positionIterator);
            simulationAmplitude->erase(amplitudeIterator);
          }
          else
          {
            (*positionIterator).first -= start.first;
            (*positionIterator).second -= start.second;
          }
        }
      }

      if (do_it)
      {
        CreateStarData* stardata = new CreateStarData;
        ret = stardata->make_star(*(image_data), exposure_time, image_dimensions,
            *simulationPosition, simulationFwhm, *simulationAmplitude, gain, simulationEnableNoise,
            simulationBackgroundNoise, simulationReadoutNoise);
        delete stardata;
      }
    }
    catch (...)
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraSimulator::start_exposure: Generating image date threw an exception."));
      ret = false;
    }

    if (ret == false)
    {
      abort_exposure();
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraSimulator::start_exposure: Error while starting. Exposure aborted!"));
    }
    else
    {
      stop_exposure = false;
      ret_value = true;
    }
  }
  return ret_value;
}

bool irisCameraSimulator::wait_for_exposure_done(int& ret) const
{
  bool ret_value(false);

  if (camera_running && exposure_running)
  {
    ret = -1;
    double wait_seconds(exposure_time);

    if ((wait_seconds > 0.0) && (stop_exposure == false))
    {
      /*
       Usually one would call nanosleep only once, but:
       Wait for wait_loop_counter cycles of 0.001 s.
       This ensures, that a stopExposureAction will
       be noticed.
       */
      const long wait_nsecs(ACE_ONE_SECOND_IN_NSECS / 100L);
      const timespec wait_time =
      { 0, wait_nsecs };
      long wait_loop_counter(
          static_cast<long> (wait_seconds * ACE_ONE_SECOND_IN_NSECS / wait_nsecs));

      while ((wait_loop_counter >= 0) && (stop_exposure == false))
      {
        ACE_OS::nanosleep(&wait_time);
        wait_loop_counter--;
      }
    }
    //No error:
    if (stop_exposure == false)
    {
      ret_value = true;
      ret = irisCamera::OK;
    }
    else
    {
      ret_value = true;
      ret = irisCamera::EXPOSURE_ABORTED;
    }
  }
  else
  {
    ret = irisCamera::EXPOSURE_ERROR;
  }
  return ret_value;
}

void irisCameraSimulator::abort_exposure(void)
{
  if (camera_running)
  {
    stop_exposure = true;
    dump_image_data();
    exposure_running = false;
    ACS_SHORT_LOG((LM_INFO, "irisCameraSimulator::abort_exposure: Exposure aborted."));
  }
}

void irisCameraSimulator::dump_image_data(void) const
{
  if (camera_running)
  {
    image_data->assign(image_data->size(), 0);
  }
}

bool irisCameraSimulator::download_image_from_camera(std::vector<unsigned short int>* myArray)
{
  bool ret_value(false);

  if (camera_running && exposure_running)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraSimulator::download_image_from_camera: Start image download from camera."));

    long size(0L);
    ret_value = get_image_size(size);

    if ((ret_value == true) && (myArray->size() == static_cast<std::size_t> (size)))
    {
      myArray->assign(image_data->begin(), image_data->end());
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraSimulator::download_image_from_camera: Download complete."));
      ret_value = true;
    }
    else
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraSimulator::download_image_from_camera: Not enough memory for temporary image data. Download aborted!"));
    }
  }

  exposure_running = false;
  return ret_value;
}

bool irisCameraSimulator::set_image_dimensions(std::pair<long, long>& new_start, std::pair<long,
    long>& new_end)
{
  if (camera_running && !(exposure_running))
  {
    if (check_image_dimensions(new_start, new_end) == false)
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraSimulator::set_image_dimensions: Trying to set image dimensions to (x0,y0)=%d,%d (x1,y1)=%d,%d.", new_start.first, new_start.second, new_end.first, new_end.second));

      std::pair<long, long> new_image_dimensions(new_end.first - new_start.first + 1L,
          new_end.second - new_start.second + 1L);

      image_data->resize(static_cast<std::size_t> (new_image_dimensions.first
          * new_image_dimensions.second));

      if (image_data->size() != static_cast<std::size_t> (new_image_dimensions.first
          * new_image_dimensions.second))
      {
        // Oops, an error! Restore old values.
        image_data->resize(static_cast<std::size_t> (image_dimensions.first
            * image_dimensions.second));
        new_start = start;
        new_end = end;
        ACS_SHORT_LOG(
            (LM_ERROR, "irisCameraSimulator::set_image_dimensions: Setting new image dimensions failed! Using old image dimensions: (x0,y0)=%d,%d (x1,y1)=%d,%d.", start.first, start.second, end.first, end.second));

        return false;
      }
      else
      {
        start = new_start;
        end = new_end;
        image_dimensions = new_image_dimensions;
        ACS_SHORT_LOG(
            (LM_INFO, "irisCameraSimulator::set_image_dimensions: Setting new image dimensions successful. New image dimensions: (x0,y0)=%d,%d (x1,y1)=%d,%d.", start.first, start.second, end.first, end.second));

        return true;
      }
    }
    else
    {
      return true;
    }
  }
  return false;
}

int irisCameraSimulator::open_camera(void)
{
  if (!camera_running)
  {
    ACS_SHORT_LOG((LM_INFO, "irisCameraSimulator::open_camera: Simulator camera found."));

    pixelSize = std::pair<double, double>(9.0E-6, 9.0E-6);

    start = std::pair<long, long>(0L, 0L);
    min_start = std::pair<long, long>(0L, 0L);
    end = std::pair<long, long>(999L, 999L);
    max_end = std::pair<long, long>(9999L, 9999L);
    max_start.first = max_end.first - 1L;
    max_start.second = max_end.second - 1L;
    min_end.first = min_start.first + 1L;
    min_end.second = min_start.second + 1L;
    camera_dimensions.first = end.first - start.first + 1L;
    camera_dimensions.second = end.second - start.second + 1L;
    image_dimensions.first = end.first - start.first + 1L;
    image_dimensions.second = end.second - start.second + 1L;

    if (image_data != 0)
    {
      delete image_data;
    }
    image_data = new std::vector<unsigned short int>(image_dimensions.first
        * image_dimensions.second);
    if (image_data->size() != static_cast<std::size_t> (image_dimensions.first
        * image_dimensions.second))
    {
      delete image_data;
      image_data = 0;
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCameraSimulator::open_camera: Check hardware! ;-) No memory for image data."));
      return irisCamera::HARDWARE_ERROR;
    }

    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraSimulator::open_camera: Imaging width=%d, height=%d.", image_dimensions.first, image_dimensions.second));

    camera_running = true;
    return irisCamera::OK;
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCameraSimulator::open_camera: Check hardware, camera already active."));
    return irisCamera::HARDWARE_ERROR;
  }
}

int irisCameraSimulator::close_camera(void)
{
  int ret(irisCamera::HARDWARE_ERROR);

  if (camera_running)
  {
    stop_exposure = true;
    if (exposure_running)
    {
      abort_exposure();
    }
    delete image_data;
    image_data = 0;
    camera_running = false;
    ret = (irisCamera::OK | irisCamera::CAMERA_OFF);
  }
  return ret;
}

bool irisCameraSimulator::set_number_of_flushes(const long& _number_of_flushes)
{
  if (camera_running && (!exposure_running))
  {
    number_of_flushes = _number_of_flushes;
    return true;
  }
  return false;
}

bool irisCameraSimulator::set_simulation_parameters(
    const std::vector<std::pair<double, double> >& _position,
    const std::pair<double, double>& _fwhm, const std::vector<double>& _amplitude,
    const bool _noiseEnable, const double& _noiseBackground, const double& _noiseReadout)
{
  if (camera_running)
  {
    simulationPosition->assign(_position.begin(), _position.end());
    simulationFwhm = _fwhm;
    simulationAmplitude->assign(_amplitude.begin(), _amplitude.end());
    simulationEnableNoise = _noiseEnable;
    simulationBackgroundNoise = _noiseBackground;
    simulationReadoutNoise = _noiseReadout;
    return true;
  }
  return false;
}
