/*
 * "@(#) $Id: irisCameraFLI.h,v 1.9  2010/01/07 19:04:24  mparra Exp $"
 *
 * $Log: irisCameraFLI.h,v $
 * Revision 1.9  2010/01/07 19:04:24  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.8  2005/01/20 15:08:55  tjuerges
 * - Changed to usage of std::pair containers for data which occurs in pairs like pixel size,
 * 	image dimensions, camera dimensions, image widht/height etc.
 * - Moved some error checking from creation of simulated stars to irisCameraSimulator module. This
 * 	made it possible to have a kind of windowing a.k.a. sub frames.
 *
 * This class is an implementation of the interface class for the several
 * CCD cameras used with the IRIS telescope.
 * It uses a Finger Lakes Instrumentation CCD camera.
 *
 * Implemented with usage of
 * - Singleton pattern
 * - Factory pattern (see irisCamera, irisCameraFactory)
 */

#ifndef irisCameraFLI_h
#define irisCameraFLI_h

#include <vector>
#include <irisCamera.h>
#include <libfli.h>
#include <tao/corba.h>

class irisCameraFLI: public irisCamera
{

  public:

    static irisCameraFLI* get_camera(void);
    virtual ~irisCameraFLI();

    virtual int open_camera(void);
    virtual int close_camera(void);

    virtual bool start_exposure(void);
    virtual bool wait_for_exposure_done(int&) const;
    virtual void abort_exposure(void);
    virtual bool download_image_from_camera(std::vector<unsigned short int>*);
    virtual bool set_camera_exposure_time(const double&);

    virtual bool set_camera_frame_type(const long&);

    virtual bool set_image_dimensions(std::pair<long, long>&, std::pair<long, long>&);

    virtual bool set_camera_temperature(const double&);
    virtual bool get_camera_temperature(double&) const;
    virtual bool get_air_temperature(double&) const;

    virtual bool set_number_of_flushes(const long&);

    //Controllers for FLI filter wheel:
    virtual CORBA::Long init_wheel(void);
    virtual CORBA::Long exit_wheel(void);
    virtual CORBA::Long move_wheel_up(void);
    virtual CORBA::Long move_wheel_down(void);
    virtual CORBA::Long move_wheel_to(CORBA::Long);
    virtual CORBA::Long get_wheel_position(void) const;

  protected:

    typedef struct
    {
        flidomain_t domain;
        char *dname;
        char *camera_name;
    } cam_t;

    virtual void dump_image_data(void) const;
    int find_camera(cam_t**, int&, char*);

    //FLI stuff:
    cam_t* cam;
    flidev_t dev;
    flidev_t wheel_device;
    long wheel_position;

    //Class pointer to the only instance of the class.
    static irisCameraFLI* myself;
    //Reference counter for this class.
    static int reference_counter;

  private:

    irisCameraFLI();
};
#endif //irisCameraFLI_h
