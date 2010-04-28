/*
 *
 * "@(#) $Id: irisCameraSimulatorCreateStarData.cpp,v 1.11  2010/01/07 23:45:39  mparra tjuerges Exp $"
 *
 * $Log: irisCameraSimulatorCreateStarData.cpp,v $
 * Revision 1.11  2010/01/07 23:45:39  mparra
 * - Adapted to IRIS telescope name.
 * - cmath library added, because some math methods was move from std library to this library.
 *
 * Revision 1.10  2005/01/27 16:34:46  tjuerges
 * - SImulation has been changed to use GNU scientific library methods now.
 *
 * Revision 1.9  2005/01/20 18:18:44  tjuerges
 * - Improvements for empty list of simulated stars. Then create a dark.
 *
 * Revision 1.8  2005/01/20 15:15:25  tjuerges
 * - Added creation of a dark frame if no star positions are passed to make_stars.
 *
 * Revision 1.7  2005/01/20 15:08:55  tjuerges
 * - Changed to usage of std::pair containers for data which occurs in pairs like pixel size,
 * 	image dimensions, camera dimensions, image widht/height etc.
 * - Moved some error checking from creation of simulated stars to irisCameraSimulator module. This
 * 	made it possible to have a kind of windowing a.k.a. sub frames.
 *
 * Revision 1.6  2005/01/19 15:50:48  tjuerges
 * - Added check if amount of stars to be simulated==0.
 *
 * Revision 1.5  2005/01/18 16:47:35  tjuerges
 * - Removed unnecessary method from camera simulation.
 *
 * Revision 1.4  2005/01/18 14:58:08  tjuerges
 * - Changed Simulator to enable the possibility of many simulated stars.
 *
 * Revision 1.3  2005/01/11 16:48:12  tjuerges
 * - Changed simulation parameters from float to double.
 *
 * Revision 1.2  2004/11/02 13:18:40  tjuerges
 * *** empty log message ***
 *
 * Revision 1.1  2004/09/22 13:37:28  tjuerges
 * - CreateGauss in CreaStarData umbenannt.
 * - Neue Algotithmen f�r Rauscherzeugung.
 *
 * Revision 1.1  2004/08/17 12:10:56  tjuerges
 * - Erzeugen von Gauss in Simulator eingef�gt.
 *
 */

#include <irisCameraSimulatorCreateStarData.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <logging.h>
#include <utility>
#include <cstdlib>
#include <cmath>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

CreateStarData::CreateStarData() :
  two_Pi(2.0 * M_PI), ONE_POINT_FIVEFIVE(static_cast<double> (sqrt(8.0 * log(2.0))))
{
  temp_data = new std::vector<double>;
  random_number_generator = gsl_rng_alloc(gsl_rng_ran1);
  gsl_rng_set(random_number_generator, static_cast<unsigned long> (rand()));
}

CreateStarData::~CreateStarData()
{
  gsl_rng_free(random_number_generator);
  delete temp_data;
}

bool CreateStarData::make_star(std::vector<unsigned short int>& _data,
    const double& _exposure_time, const std::pair<long, long>& _data_dimension, const std::vector<
        std::pair<double, double> >& _position, const std::pair<double, double>& _fwhm,
    const std::vector<double>& _amplitude, const double& _gain = 85000.0 / 65535.0,
    const bool& _noise_enable = true, const double& _noise_background = 5500.0,
    const double& _noise_readout = 15.0)
{
  const std::pair<double, double> dim(_data_dimension);
  const long size(_data_dimension.first * _data_dimension.second);

  temp_data->resize(static_cast<std::size_t> (size), 0.0);
  if (temp_data->size() != static_cast<std::size_t> (size))
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "CreateStarData::make_star: ERROR! The needed size of a temporary vector (size=%d) is too small (vector_size=%d).", size, temp_data->size()));
    temp_data->resize(0);
    return false;
  }

  const std::pair<double, double> sigma(_fwhm.first / ONE_POINT_FIVEFIVE, _fwhm.second
      / ONE_POINT_FIVEFIVE);
  std::vector<double> amplitude;
  amplitude.assign(_amplitude.begin(), _amplitude.end());

  gain = _gain;
  background_noise = _noise_background / gain;
  readout_noise = _noise_readout;

  if (_exposure_time >= 0.01)
  {
    background_noise *= _exposure_time / 0.01;
  }

  if (_position.size() > 0)
  {
    std::vector<std::pair<double, double> >::const_iterator position_iterator(_position.begin());
    for (std::vector<double>::const_iterator amplitude_iterator(amplitude.begin()); amplitude_iterator
        != amplitude.end(); ++amplitude_iterator, ++position_iterator)
    {
      if ((*amplitude_iterator) > 0.0)
      {
        std::pair<double, double> value(0.0, 0.0);
        long i(0L), j(0L);

        for (j = (_data_dimension.second - 1); j >= 0; --j)
        {
          if (sigma.second == 0.0)
          {
            value.second = (*amplitude_iterator);
          }
          else
          {
            value.second = (*amplitude_iterator) * exp(-0.5 * pow((j - (*position_iterator).second)
                / sigma.second, 2));
          }

          for (i = (_data_dimension.first - 1); i >= 0; --i)
          {
            if (sigma.first == 0.0)
            {
              value.first = (*amplitude_iterator);
            }
            else
            {
              value.first = value.second * exp(-0.5 * pow((i - (*position_iterator).first)
                  / sigma.first, 2));
            }
            (*temp_data)[i + j * _data_dimension.first] += value.first;
          }
        }
      }
    }
  }

  if (_noise_enable)
  {
    if (background_noise > 0.0)
    {
      make_poisson_noise(temp_data);
    }
    if (readout_noise > 0.0)
    {
      make_gauss_noise(temp_data);
    }
  }

  // Check for too low values, i.e. values<0.0, and correct later.
  double min_val(-(*(std::min_element(temp_data->begin(), temp_data->end()))));
  if (min_val > 0.0)
  {
    std::transform(temp_data->begin(), temp_data->end(), temp_data->begin(), std::bind1st(
        std::plus<double>(), min_val));
  }

  // Check for too high values.
  std::replace_if(temp_data->begin(), temp_data->end(), bind2nd(std::greater<double>(), 65535.0),
      65535.0);

  // Copy generated pixels to data vector.
  std::vector<unsigned short int>::iterator data_iterator(_data.begin());
  for (std::vector<double>::iterator temp_data_iterator(temp_data->begin()); temp_data_iterator
      != temp_data->end(); ++temp_data_iterator, ++data_iterator)
  {
    (*data_iterator) = static_cast<unsigned short int> (*temp_data_iterator);
  }

  temp_data->resize(0);
  return true;
}

/*
 * Make gaussian read out noise.
 */
void CreateStarData::make_gauss_noise(std::vector<double>* d)
{
  for (std::vector<double>::iterator i(d->begin()); i != d->end(); ++i)
  {
    (*i) += readout_noise * gsl_ran_gaussian(random_number_generator, 1.0);
  }
}

/*
 * Make poisson background noise.
 */
void CreateStarData::make_poisson_noise(std::vector<double>* d)
{
  double value;
  for (std::vector<double>::iterator i(d->begin()); i != d->end(); ++i)
  {
    value = ((*i) + background_noise) * gain;
    (*i) += (gsl_ran_poisson(random_number_generator, value) - value) / gain;
  }
}
