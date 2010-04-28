/*
 * "@(#) $Id: irisCameraSimulatorCreateStarData.h,v 1.6  2010/01/07 19:14:26  mparra Exp $"
 *
 * $Log: irisCameraSimulatorCreateStarData.h,v $
 * Revision 1.6  2010/01/07 19:14:26  mparra
 * - Adapted to IRIS telescope name
 * Revision 1.5  2005/01/27 16:34:46  tjuerges
 * - SImulation has been changed to use GNU scientific library methods now.
 *
 * Revision 1.4  2005/01/20 15:08:55  tjuerges
 * - Changed to usage of std::pair containers for data which occurs in pairs like pixel size,
 * 	image dimensions, camera dimensions, image widht/height etc.
 * - Moved some error checking from creation of simulated stars to irisCameraSimulator module. This
 * 	made it possible to have a kind of windowing a.k.a. sub frames.
 *
 * Revision 1.3  2005/01/18 14:58:08  tjuerges
 * - Changed Simulator to enable the possibility of many simulated stars.
 *
 * Revision 1.2  2005/01/11 16:48:12  tjuerges
 * - Changed simulation parameters from float to double.
 *
 * Revision 1.1  2004/09/22 13:36:26  tjuerges
 * - CreateGauss in CreaStarData umbenannt.
 * - Neue Algotithmen f�r Rauscherzeugung.
 *
 * Revision 1.1  2004/08/17 12:10:33  tjuerges
 * - Erzeugen von Gauss in Simulator eingef�gt.
 *
 * Class which creates a gaussian star in a 2D unsigned short vector.
 * Needs:
 * - std::vector<std::pair<double,double> > vector reference,
 * - image width,
 * - image height.
 * - std::vector<std::pair<double,double> > FWHM in x,y direction,
 * - std::vector<double> maximum amplitude of star.
 * Optional:
 * - noise enabled?,
 * - noise of background,
 * - readout noise,
 * - rms of noise.
 *
 */

#ifndef irisCameraSimulatorCreateStarData_h
#define irisCameraSimulatorCreateStarData_h

#include <vector>
#include <utility>
#include <gsl/gsl_rng.h>

class CreateStarData
{

  public:

    CreateStarData();
    virtual ~CreateStarData();
    virtual bool make_star(std::vector<unsigned short int>& data, const double& exposure_time,
        const std::pair<long, long>& data_dimension,
        const std::vector<std::pair<double, double> >& position,
        const std::pair<double, double>& fwhm, const std::vector<double>& amplitude,
        const double& gain, const bool& noise, const double& noise_background,
        const double& noise_readout);

  protected:

    virtual void make_gauss_noise(std::vector<double>*);
    virtual void make_poisson_noise(std::vector<double>*);

    std::vector<double>* temp_data;
    gsl_rng* random_number_generator;
    const double two_Pi;
    const double ONE_POINT_FIVEFIVE;
    double gain, background_noise, readout_noise;
};
#endif
