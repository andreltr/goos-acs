/*
 *
 * "@(#) $Id: irisCameraSimulator.h,v 1.15  2010/01/07 19:10:33  mparra Exp $"
 *
 * $Log: irisCameraSimulator.h,v $
 * Revision 1.15  2010/01/07 19:10:33  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.14  2005/01/20 15:08:55  tjuerges
 * - Changed to usage of std::pair containers for data which occurs in pairs like pixel size,
 * 	image dimensions, camera dimensions, image widht/height etc.
 * - Moved some error checking from creation of simulated stars to irisCameraSimulator module. This
 * 	made it possible to have a kind of windowing a.k.a. sub frames.
 *
 * Revision 1.13  2005/01/18 16:47:35  tjuerges
 * - Removed unnecessary method from camera simulation.
 *
 * Revision 1.12  2005/01/18 14:58:08  tjuerges
 * - Changed Simulator to enable the possibility of many simulated stars.
 *
 * Revision 1.11  2005/01/11 16:48:12  tjuerges
 * - Changed simulation parameters from float to double.
 *
 * Revision 1.10  2004/09/22 13:36:26  tjuerges
 * - CreateGauss in CreaStarData umbenannt.
 * - Neue Algotithmen f�r Rauscherzeugung.
 *
 * Revision 1.9  2004/08/19 08:01:18  tjuerges
 * - Kleine Sch�nheitskorrekturen im Code. Keine �nderungen der Logik.
 *
 * Revision 1.8  2004/08/17 12:10:33  tjuerges
 * - Erzeugen von Gauss in Simulator eingef�gt.
 *
 * This class is an implementation of the interface class for the several
 * CCD cameras used with the Hexapod telescope.
 * It simulates a CCD camera. Basic generation of star images takes place
 * in the helper module irisStarUtils.
 *
 * Implemented with usage of
 * - Singleton pattern
 * - Factory pattern (see irisCamera, irisCameraFactory)
 *
 */

#ifndef irisCameraSimulator_h
#define irisCameraSimulator_h

#include <irisStarUtils.h>
#include <vector>
#include <utility>
#include <irisCamera.h>
#include <tao/corba.h>

class irisCameraSimulator: public irisCamera
{

  public:

    static irisCameraSimulator* get_camera(void);
    virtual ~irisCameraSimulator();

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

    virtual bool set_simulation_parameters(const std::vector<std::pair<double, double> >& position,
        const std::pair<double, double>& fwhm, const std::vector<double>& amplitude,
        const bool noiseEnable, const double& noiseBackground, const double& noiseReadout);

  protected:

    void dump_image_data(void) const;

    std::vector<unsigned short int>* image_data;
    double ccd_temperature;
    double exposure_time;
    long frame_type;

    // Simulation parameters:
    std::vector<std::pair<double, double> >* simulationPosition;
    std::pair<double, double> simulationFwhm;
    std::vector<double>* simulationAmplitude;
    bool simulationEnableNoise;
    double simulationBackgroundNoise;
    double simulationReadoutNoise;

    //Class pointer to the only instance of the class.
    static irisCameraSimulator* myself;
    //Reference counter for this class.
    static int reference_counter;

  private:

    irisCameraSimulator();
};
#endif //irisCameraSimulator_h
