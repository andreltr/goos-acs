/*
 * "@(#) $Id: irisCamera.h,v 1.13  2010/01/07 18:50:23  mparra Exp $"
 *
 * $Log: irisCamera.h,v $
 ** Revision 1.13  2010/01/07 18:50:23  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.12  2005/01/20 15:08:55  tjuerges
 * - Changed to usage of std::pair containers for data which occurs in pairs like pixel size,
 * 	image dimensions, camera dimensions, image widht/height etc.
 * - Moved some error checking from creation of simulated stars to irisCameraSimulator module. This
 * 	made it possible to have a kind of windowing a.k.a. sub frames.
 *
 * Revision 1.11  2005/01/18 16:47:35  tjuerges
 * - Removed unnecessary method from camera simulation.
 *
 * This class is an interface class for the several CCD cameras used
 * with a telescope
 *
 */

#ifndef irisCamera_h
#define irisCamera_h

#include <vector>
#include <utility>
#include <tao/corba.h>

class irisCamera
{

  public:

    virtual ~irisCamera(void);
    virtual int open_camera(void)=0;
    virtual int close_camera(void)=0;
    virtual int reset_camera(void);

    virtual bool start_exposure(void)=0;
    virtual void stop_running_exposure(void);
    virtual bool wait_for_exposure_done(int&) const=0;
    virtual void abort_exposure(void)=0;
    virtual bool download_image_from_camera(std::vector<unsigned short int>*)=0;
    virtual bool get_camera_running(void) const;
    virtual bool get_exposure_running(void) const;
    virtual bool get_image_size(long&) const;

    virtual bool set_camera_exposure_time(const double&)=0;

    virtual bool set_camera_frame_type(const long&)=0;

    virtual bool set_image_dimensions(std::pair<long, long>&, std::pair<long, long>&)=0;
    virtual bool check_image_dimensions(std::pair<long, long>&, std::pair<long, long>&);
    virtual bool get_image_area(std::pair<long, long>&, std::pair<long, long>&) const;

    virtual bool set_camera_temperature(const double&)=0;
    virtual bool get_camera_temperature(double&) const=0;
    virtual bool get_air_temperature(double&) const=0;

    virtual bool get_gain(double&) const;

    virtual bool get_pixel_size(std::pair<double, double>&) const;

    virtual bool set_number_of_flushes(const long&)=0;

    virtual bool set_simulation_parameters(const std::vector<std::pair<double, double> >& position,
        const std::pair<double, double>& fwhm, const std::vector<double>& amplitude,
        const bool noiseEnable, const double& noiseBackground, const double& noiseReadout)
    {
      return true;
    }
    ;

    //Controllers for filter wheel:
    virtual CORBA::Long init_wheel(void);
    virtual CORBA::Long exit_wheel(void);
    virtual CORBA::Long move_wheel_up(void);
    virtual CORBA::Long move_wheel_down(void);
    virtual CORBA::Long move_wheel_to(CORBA::Long);
    virtual CORBA::Long get_wheel_position(void) const;

    enum CCD_status_enum
    {
      ERROR = 0,
      OK,
      CAMERA_OFF,
      EXPOSING,
      DOWNLOADING_FROM_CAMERA,
      CAMERA_SEARCH,
      NO_CAMERA_FOUND,
      NO_REALLOC,
      NOMEM_ERROR,
      HARDWARE_ERROR,
      CONNECTION_PORT_ERROR,
      CCD_LIBRARY_ERROR,
      TIME_OUT,
      EXPOSURE_ERROR,
      EXPOSURE_ABORTED
    };

  protected:

    virtual void dump_image_data(void) const=0;

    std::pair<long, long> camera_dimensions;
    std::pair<long, long> image_dimensions;
    std::pair<long, long> min_start;
    std::pair<long, long> max_start;
    std::pair<long, long> min_end;
    std::pair<long, long> max_end;
    std::pair<long, long> start;
    std::pair<long, long> end;
    std::pair<double, double> pixelSize;
    double gain;
    long number_of_flushes;
    bool camera_running;
    bool exposure_running;
    bool stop_exposure;
};
#endif //irisCamera_h
