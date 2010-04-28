/*
 * "@(#) $Id: irisCameraIRIS.cpp,v 1.30  2010/02/06 20:37:12  mparra Exp $"
 *
 * $Log: irisCameraIRIS.cpp,v $
 * * Revision 1.30  2010/02/06 20:37:12  mparra
 * - Adapted to IRIS telescope name.
 * - Set irisClient to our IP address irisClient irisCam("192.168.9.170:4980")
 *
 * Revision 1.29  2005/01/24 15:18:33  tjuerges
 * - Added CVS Log.
 *
 */

#include <irisCameraIRIS.h>
#include <OS.h>
#include <Time_Value.h>
#include <logging.h>

#include <irisCam.h>

//irisClient irisCam("192.168.9.170:4980");
irisClient irisCam("192.168.7.210:4980");
//irisDataServer irisCamDataReceiver((int) (4711));
irisDataServer irisCamDataReceiver((int) (4980));

//Init of static class members
irisCameraIRIS* irisCameraIRIS::myself = 0;
int irisCameraIRIS::reference_counter = 0;

/* Singleton mechanism which is the only
 * possibility the get an instance of this class.
 */
irisCameraIRIS* irisCameraIRIS::get_camera(void)
{
  if (irisCameraIRIS::myself == 0)
  {
    irisCameraIRIS::myself = new irisCameraIRIS;
  }

  //Increase the usage counter by one.
  irisCameraIRIS::reference_counter++;

  //Return the only instance of this class.
  return irisCameraIRIS::myself;
}

// Hidden constructor, not to be used from outside.
irisCameraIRIS::irisCameraIRIS(void)
{
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

irisCameraIRIS::~irisCameraIRIS(void)
{
  //Decrease usage counter by one.
  irisCameraIRIS::reference_counter--;

  if (irisCameraIRIS::reference_counter == 0)
  {
    close_camera();
    irisCameraIRIS::myself = 0;
  }

  //~irisCamDataReceiver;
}

void irisCameraIRIS::delete_camera(void)
{
}

bool irisCameraIRIS::get_camera_temperature(double& temperature) const
{
  bool ret_value(false);
  temperature = -9999.9;

  return ret_value;
}

bool irisCameraIRIS::get_air_temperature(double& temperature) const
{
  bool ret_value(false);
  temperature = -9999.9;
  // nothing to be done her, simply set temperature to 25C

  temperature = 25.0;
  ret_value = true;
  return ret_value;
}

bool irisCameraIRIS::set_camera_temperature(const double& temperature)
{
  bool ret_value(false);

  if (camera_running)
  {
    if (exposure_running)
    {
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraIRIS::set_camera_temperature: Waiting until the current exposure has ended..."));

      timespec wait_time =
      { static_cast<time_t> (0), ACE_ONE_SECOND_IN_NSECS / 1000L };
      while (exposure_running == true)
      {
        ACE_OS::nanosleep(&wait_time);
      };

      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraIRIS::set_camera_temperature: Current exposure ended. Trying to set wanted temperature..."));
    }

    ret_value = true;
  }
  return ret_value;
}

bool irisCameraIRIS::set_camera_frame_type(const long& _frame_type)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    frame_type = _frame_type;
    ret_value = true;
  }
  return ret_value;
}

bool irisCameraIRIS::set_camera_exposure_time(const double& exp_time)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    exposure_time = exp_time;
    irisCam.et((int) (exposure_time));
    ret_value = true;
  }
  return ret_value;
}

int readerThreadRunning = false;
ACE_thread_t *readerThreadID = new ACE_thread_t;
ACE_hthread_t *readerThreadHandle = new ACE_hthread_t;

static void *readerThread(void *arg)
{

  while (readerThreadRunning)
  {
    ACS_SHORT_LOG((LM_INFO, "irisCameraIRIS readerThread running"));
    irisCamDataReceiver.accept_connections();
  }
  irisCamDataReceiver.close_connections();
  ACS_SHORT_LOG((LM_INFO, "irisCameraIRIS readerThread stopped"));
}

bool irisCameraIRIS::start_exposure(void)
{
  bool ret_value(false);

  if (camera_running && (!exposure_running))
  {
    exposure_running = true;
    flush_camera();
    ACS_SHORT_LOG((LM_INFO, "irisCameraIRIS::start_exposure before go() "));
    irisCam.go();
    ACS_SHORT_LOG((LM_INFO, "irisCameraIRIS::start_exposure after go()"));
    stop_exposure = false;
    ret_value = true;
  }
  return ret_value;
}

bool irisCameraIRIS::wait_for_exposure_done(int& ret) const
{
  bool ret_value(false);

  if (camera_running && exposure_running)
  {
    ret = -1;

    ACS_SHORT_LOG((LM_INFO, "irisCameraIRIS::wait_for_exposure_done:  ... done"));

    ret_value = true;
    ret = irisCamera::OK;
  }
  return ret_value;
}

void irisCameraIRIS::abort_exposure(void)
{
  if (camera_running)
  {
    ACS_SHORT_LOG((LM_INFO, "irisCameraIRIS::abort_exposure: unable ..."));
  }
}

void irisCameraIRIS::dump_image_data(void) const
{
  if (camera_running)
  {
  }
}

bool irisCameraIRIS::download_image_from_camera(std::vector<unsigned short int>* myArray)
{
  unsigned short int tempImage[2048][1024];
  bool ret_value(false);
  if (camera_running && exposure_running)
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraSBIG::download_image_from_camera: Start image download from camera."));
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraSBIG::download_image_from_camera: myArray size %d.", myArray->size()));
    
    irisCamDataReceiver.copy_data(tempImage);

    for (int i = 0; i < 1024; i++)
      for (int j = 0; j < 1024; j++)
        (*myArray)[(i * 2048) + j] = tempImage[i][j] - 32768;

    for (int i = 0; i < 1024; i++)
      for (int j = 0; j < 1024; j++)
        (*myArray)[(i * 2048) + j + 1024] = tempImage[i + 1024][j] - 32768;

    ACS_SHORT_LOG((LM_INFO, "irisCameraIRIS::download_image_from_camera: Download complete."));
    ret_value = true;
  }

  exposure_running = false;
  return ret_value;
}

bool irisCameraIRIS::set_image_dimensions(std::pair<long, long>& new_start,
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
          (LM_INFO, "irisCameraSBIG::set_image_dimensions: Setting new image dimensions successful. New image dimensions: (x0,y0)=%d,%d (x1,y1)=%d,%d.", start.first, start.second, end.first, end.second));
    }
    ret_value = true;
  }
  return ret_value;
}

int irisCameraIRIS::find_camera(void)
{
  int ret(irisCamera::NO_CAMERA_FOUND);

  if (introot_path.size() == 0)
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCameraIRIS::find_camera: This client needs to know the environment variable $INTROOT, but received nothing. Aborting!"));
    return ret;
  }

  ACS_SHORT_LOG((LM_INFO, "irisCameraIRIS::find_camera: try to find camera on Ethernet"));

  irisCam.sync();
  ret = irisCamera::OK;

  return ret;
}

int irisCameraIRIS::open_camera(void)
{
  int ret(irisCamera::OK);

  if (!camera_running)
  {
    ret = find_camera();
    if (ret != irisCamera::OK)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCameraIRIS::open_camera: No IRIS camera found."));
      return ret;
    }

    start = min_start = std::pair<long, long>(0L, 0L);
    end.first = max_end.first = static_cast<long> (2048) - 1L;
    end.second = max_end.second = static_cast<long> (1024) - 1L;
    max_start.first = max_end.first - 1L;
    max_start.second = max_end.second - 1L;
    min_end.first = min_start.first + 1L;
    min_end.second = min_start.second + 1L;
    gain = 1;
    camera_dimensions = image_dimensions = std::pair<long, long>(2048, 1024);
    ACS_SHORT_LOG(
        (LM_INFO, "irisCameraIRIS::open_camera: Imaging width=%d, height=%d, gain=%g.", image_dimensions.first, image_dimensions.second, gain));

    irisCam.clear();
    irisCam.dl();
    irisCam.xfer("192.168.7.210", "4980");

    readerThreadRunning = true;
    ACE_OS::printf("spawning thread\n");
    fflush( stdout);
    if (ACE_Thread::spawn((ACE_THR_FUNC) readerThread, 0, THR_JOINABLE | THR_NEW_LWP,
        readerThreadID, readerThreadHandle) == -1)
      ACE_ERROR_RETURN((LM_ERROR, "%p\n", "spawn"), -1);

    ret = irisCamera::OK;
    camera_running = true;
    // Everything initialized.
  }
  else
  {
    ACS_SHORT_LOG((LM_ERROR, "irisCameraIRIS::open_camera: Check hardware, camera already active."));
    return HARDWARE_ERROR;
  }
  return ret;
}

int irisCameraIRIS::close_camera(void)
{
  stop_exposure = true;
  readerThreadRunning = false;
  irisCamDataReceiver.close_connections();

  if (exposure_running)
  {
    abort_exposure();
  }

  delete_camera();
  camera_running = false;
  ACS_SHORT_LOG((LM_INFO, "irisCameraIRIS::close_camera: camera closed"));
  return (irisCamera::OK | irisCamera::CAMERA_OFF);
}

bool irisCameraIRIS::set_number_of_flushes(const long& _number_of_flushes)
{
  if (camera_running && (!exposure_running))
  {
    number_of_flushes = _number_of_flushes;
    return true;
  }
  return false;
}

void irisCameraIRIS::flush_camera(void) const
{
}

void irisCameraIRIS::discard_ccd_lines(const long& number_of_lines) const
{
}

CORBA::Long irisCameraIRIS::init_wheel(void)
{
  CORBA::Long ret(-1L);

  if (camera_running)
  {
    ret = irisCam.filter("rehome");
    ret = irisCam.filter("1");
    wheel_position = 1;
  }
  return ret;
}

CORBA::Long irisCameraIRIS::exit_wheel(void)
{
  CORBA::Long ret(-1L);

  if (camera_running)
  {
    wheel_position = 0;
    ret = 0;
  }
  return ret;
}

CORBA::Long irisCameraIRIS::move_wheel_down(void)
{
  CORBA::Long ret(-1L);
  char data_buf[5];

  if (camera_running)
  {
    wheel_position--;
    if (wheel_position < 1)
      wheel_position = 8;
    ACE_OS::sprintf(data_buf, "%d", wheel_position);
    ret = irisCam.filter(data_buf);
  }
  return ret;
}

CORBA::Long irisCameraIRIS::move_wheel_up(void)
{
  CORBA::Long ret(-1L);
  char data_buf[5];
  
  if (camera_running)
  {
    wheel_position++;
    if (wheel_position > 8)
      wheel_position = 1;
    ACE_OS::sprintf(data_buf, "%d", wheel_position);
    ret = irisCam.filter(data_buf);
  }
  return ret;
}

CORBA::Long irisCameraIRIS::move_wheel_to(CORBA::Long _position)
{
  CORBA::Long ret(-1L);
  char data_buf[5];

  if (camera_running)
  {
    if (wheel_position != _position)
    {
      ACE_OS::sprintf(data_buf, "%d", _position);
      ret = irisCam.filter(data_buf);
      ACS_SHORT_LOG(
          (LM_INFO, "irisCameraIRIS::move_wheel_to: from %d  to %d", wheel_position, _position));
      wheel_position = _position;
    }
  }
  return ret;
}

CORBA::Long irisCameraIRIS::get_wheel_position(void) const
{
  CORBA::Long ret(-1L);
  if (camera_running)
  {
    ret = wheel_position;
  }
  return ret;
}
