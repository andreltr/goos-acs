/*
 * "@(#) $Id: irisCamera.cpp,v 1.11  2010/01/07 19:23:39  mparra Exp $"
 *
 * $Log: irisCamera.cpp,v $
 * Revision 1.11  2010/01/07 19:23:39  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.10  2005/01/24 15:18:33  tjuerges
 * - Added CVS Log.
 *
 *
*/

#include <irisCamera.h>
#include <logging.h>

//Empty Destructor needed for the children...
irisCamera::~irisCamera(void)
{
}

void irisCamera::stop_running_exposure(void)
{
  stop_exposure=true;
}

bool irisCamera::get_gain(double& _gain) const
{
  if(camera_running)
  {
    _gain=gain;
    return true;
  }
  return false;
}

bool irisCamera::get_camera_running(void) const
{
  return camera_running;
}

bool irisCamera::get_exposure_running(void) const
{
  return exposure_running;
}

bool irisCamera::check_image_dimensions(std::pair<long,long>& new_start,std::pair<long,long>& new_end)
{
  if(new_start<min_start)
  {
    new_start=min_start;
    ACS_SHORT_LOG((LM_WARNING,"irisCamera::check_image_dimensions: x0,y0 is too small, setting it to %d,%d.",new_start.first,new_start.second));
  }
  else if(new_start>max_start)
  {
    new_start=max_start;
    ACS_SHORT_LOG((LM_WARNING,"irisCamera::check_image_dimensions: x0 is too big, setting it to %d,%d.",new_start.first,new_start.second));
  }
  if(new_end<min_end)
  {
    new_end=min_end;
    ACS_SHORT_LOG((LM_WARNING,"irisCamera::check_image_dimensions: x1 is too small, setting it to %d,%d.",new_end.first,new_end.second));
  }
  else if(new_end>max_end)
  {
    new_end=max_end;
    ACS_SHORT_LOG((LM_WARNING,"irisCamera::check_image_dimensions: x1,y1 is too big, setting it to %d,%d.",new_end.first,new_end.second));
  }

	/*
	 * If the old image dimensions are the same as the
	 * new dimensions, no setting of them is needed.
	 * In this case return true.
	 * Otherwise return false.
	 */
  if(start!=new_start)
  {
    return false;
  }
  else if(end!=new_end)
  {
    return false;
  }
  else
  {
    return true;
  }
}

int irisCamera::reset_camera(void)
{
  int ret(HARDWARE_ERROR|CAMERA_OFF);
  if(camera_running)
  {
    ret=close_camera();
    if(ret!=(OK|CAMERA_OFF))
		{
		  return ret;
		}
    else
		{
		  ret=open_camera();
		  if(ret!=OK)
	    {
	      return ret;
	    }
		}
  }
  return ret;
}

bool irisCamera::get_pixel_size(std::pair<double,double>& size) const
{
  if(camera_running)
  {
    size=pixelSize;
    return true;
  }
  return false;
}

bool irisCamera::get_image_size(long& _size) const
{
  if(camera_running)
  {
    _size=image_dimensions.first*image_dimensions.second;
    return true;
  }
  return false;
}

bool irisCamera::get_image_area(std::pair<long,long>& _start,std::pair<long,long>& _end) const
{
  if(camera_running)
  {
    _start=start;
    _end=end;
    return true;
  }
  return false;
}

CORBA::Long irisCamera::init_wheel(void)
{
	return static_cast<CORBA::Long>(-1);
}

CORBA::Long irisCamera::exit_wheel(void)
{
	return static_cast<CORBA::Long>(-1);
}

CORBA::Long irisCamera::move_wheel_up(void)
{
	return static_cast<CORBA::Long>(-1);
}

CORBA::Long irisCamera::move_wheel_down(void)
{
	return static_cast<CORBA::Long>(-1);
}

CORBA::Long irisCamera::move_wheel_to(CORBA::Long)
{
	return static_cast<CORBA::Long>(-1);
}

CORBA::Long irisCamera::get_wheel_position(void) const
{
	return static_cast<CORBA::Long>(-1);
}
