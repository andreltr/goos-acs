/*
 * "@(#) $Id: irisCameraSBIG.h,v 2.0  2010/01/08 16:06:24  mparra Exp $"
 *
 * $Log: irisCameraSBIG.h,v $
 * Revision 2.0  2010/01/08 16:06:24  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.9  2005/01/20 15:08:55  tjuerges
 * - Changed to usage of std::pair containers for data which occurs in pairs like pixel size,
 * 	 image dimensions, camera dimensions, image widht/height etc.
 * - Moved some error checking from creation of simulated stars to irisCameraSimulator module. This
 * 	 made it possible to have a kind of windowing a.k.a. sub frames.
 *
 * This class is an implementation of the interface class for the several
 * CCD cameras used with the IRIS telescope.
 * It uses a SBIG CCD camera.
 *
 * Implemented with usage of
 * - Singleton pattern
 * - Factory pattern (see irisCamera, irisCameraFactory)
 *
 */

#ifndef irisCameraSBIG_h
#define irisCameraSBIG_h

#include <vector>
#include <irisCamera.h>
#include <csbigcam.h>
#include <tao/corba.h>

class irisCameraSBIG: public irisCamera
{

  public:

    static irisCameraSBIG* get_camera(void);
    virtual ~irisCameraSBIG();

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

    //Controllers for SBIG filter wheel:
    virtual CORBA::Long init_wheel(void);
    virtual CORBA::Long exit_wheel(void);
    virtual CORBA::Long move_wheel_up(void);
    virtual CORBA::Long move_wheel_down(void);
    virtual CORBA::Long move_wheel_to(CORBA::Long);
    virtual CORBA::Long get_wheel_position(void) const;

  protected:

    virtual void dump_image_data(void) const;
    void discard_ccd_lines(const long&) const;
    int find_camera(void);
    void delete_SBIG_structure_memory(void);
    void flush_camera(void) const;
    void delete_camera(void);
    bool load_sbig_kernel_modules(void);
    void unload_sbig_kernel_modules(void);
    /*
     * Not needed anymore.
     void set_systime_from_rtc(void);
     */

    std::string introot_path;
    unsigned short int frame_type;
    double exposure_time;

    // SBIG camera stuff:
    CSBIGCam* cam;
    short unsigned int wheel_type;
    short unsigned int wheel_position;

    //Class pointer to the only instance of the class.
    static irisCameraSBIG* myself;
    //Reference counter for this class.
    static int reference_counter;

  private:

    irisCameraSBIG();
};
#endif //irisCameraSBIG_h
