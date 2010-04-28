/*
 *
 * "@(#) $Id: irisCCDHelperFunctions.cpp,v 1.23  2009/12/03 15:58:34  mparra Exp $"
 *
 * $Log: irisCCDHelperFunctions.cpp,v $
 * Revision 1.23  2009/12/03 15:58:34  mparra
 * - Adapted to iris telescope name.
 * - The SmartPropertyPointer has change the methods read and write, there is no need
 *   to  use the int& variable, so the local definition acs_error has been deleted.
 *
 * Revision 1.22  2005/02/11 14:48:07  tjuerges
 * - Added possibility to pass centre of simulated field rotation.
 *
 * Revision 1.21  2005/01/26 11:54:04  tjuerges
 * - Replaced get_sync and set_sync to properties by getDevIO()->read and write.
 * - Added local definitions of acs_error and time_stamp for getDevIO calls.
 * - Bug fixes in field rotation calculation of simulated stars.
 *
 * Revision 1.20  2005/01/25 17:20:48  tjuerges
 * - Added simulationFieldRotation to simulated CCD camera.
 *
 * Revision 1.19  2005/01/20 18:19:11  tjuerges
 * - Allow 0 simulated stars.
 *
 * Revision 1.18  2005/01/20 16:08:20  tjuerges
 * - Tried typeof again. To be tested.
 * - Replaced std::make_pair by ctor std::pair<T,T>.
 * - Changed CCD pairwise characteristics to std::pair (dimensions etc.)
 *
 * Revision 1.17  2005/01/18 15:00:36  tjuerges
 * - Changed irisCamera-Simulator to enable the possibility of many simulated stars. This change has to be made in irisCCD and irisCCDGUI, too.
 *
 * Revision 1.16  2004/12/21 19:11:40  tjuerges
 * - Switched back from typeinfo comparison to string comparison in setup_camera.
 *
 * Revision 1.15  2004/10/14 12:06:18  tjuerges
 * - Beim Kopieren gingen Dateien kaputt. Korrekte Version nun hier.
 *
 * Revision 1.13  2004/09/26 13:13:29  tjuerges
 * *** empty log message ***
 *
 *
 */

void CCD::set_error(int error)
{
  /* error represents a bit to be set in the error status bits.
   Set a clear text error value according to error. See file
   irisCCDImpl.h for details about the bits.
   */
  ACS::Time time_stamp(0);

  if (error < 0)
  {
    // A negative error means: Clear this bit.
    error = ((-1) * error);
    m_status_p->getDevIO()->write(m_status_p->getDevIO()->read(time_stamp) & (~(1 << error)),
        time_stamp);
  }
  else
  {
    // A positive error means: Set this bit.
    m_status_p->getDevIO()->write(m_status_p->getDevIO()->read(time_stamp) | (1 << error),
        time_stamp);
  }
}

void CCD::set_to_error(int error)
{
  /* error represents a bit to be set in the error status bits.
   * Set an error text according to error. See file
   * irisCCDImpl.h for details about the bits.
   */
  ACS::Time time_stamp(0);
  m_status_p->getDevIO()->write((1 << error), time_stamp);
}

bool CCD::transfer_image_to_ACS(void)
{
  /*
   * Transfer image data from USHORT to LONG format
   * of array type LongSeq.
   */
  ACS_SHORT_LOG(
      (LM_INFO, "irisCCD::transfer_image_to_acs: Starting image data transfer from vector to sequence..."));

  long size;

  ACS::longSeq_var tempImageSeq = new ACS::longSeq;
  if (camera->get_image_size(size) == true)
  {
    tempImageSeq->length(static_cast<unsigned long> (size));
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::transfer_image_to_acs:needed %d  allocated %d, but the allocated length is %d.", 1024
            * 1024, size, tempImageSeq->length()));
    if (tempImageSeq->length() != static_cast<unsigned long> (size))
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCCD::transfer_image_to_acs: Cannot allocate enough temporary memory for image sequence. The needed sequence length is %d, but the allocated length is %d.", size, tempImageSeq->length()));
      set_error(irisCamera::NOMEM_ERROR);
      return false;
    }
    long i(0L);
    try
    {
      for (i = size - 1; i >= 0; --i)
      {
        tempImageSeq[i] = static_cast<long> ((*tempImage)[i]);
      }
    }
    catch (...)
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCCD::transfer_image_to_acs: Exception while copying image data to temporary sequence. Index i=%d.", i));
      return false;
    };
    //Transfer image data to the ACS
    ACS_SHORT_LOG(
        (LM_INFO, "irisCCD::transfer_image_to_acs: Transfering sequence of length %d to ACS...", tempImageSeq->length()));

    ACS::Time time_stamp(0);
    m_imageData_p->getDevIO()->write(tempImageSeq.in(), time_stamp);

    //Increase image counter by one
    m_imageReady_p->getDevIO()->write(m_imageReady_p->getDevIO()->read(time_stamp) + 1L, time_stamp);

    ACS_SHORT_LOG((LM_INFO, "irisCCD::transfer_image_to_acs: Image transfer to ACS complete."));

    return true;
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::transfer_image_to_acs: Cannot determine amount of pixel in the image. Download aborted!"));
  }
  return false;
}

void CCD::set_time_exposure_start(void)
{
  if (timeservice != 0)
  {
    myTime = "No time";
    myEpoch = -9999.9;

    timeservice->get_time(myTime, myEpoch);
  }
  else
  {
    ACS_SHORT_LOG((LM_ERROR, "irisCCD::set_time_exposure_start: NO time service available!"));
  }
}

void CCD::set_time_exposure_end(void)
{
  if (timeservice != 0)
  {
    ACS::Time time_stamp(0);
    m_timeExposureStart_p->getDevIO()->write(myTime.c_str(), time_stamp);

    myTime = "No time";
    timeservice->get_time(myTime);
    m_timeExposureEnd_p->getDevIO()->write(myTime.c_str(), time_stamp);
  }
  else
  {
    ACS_SHORT_LOG((LM_ERROR, "irisCCD::set_time_exposure_end: NO time service available!"));
  }
}

bool CCD::set_image_dimensions(void)
{
  bool ret(false);
  ACS::Time time_stamp(0);

  std::pair<long, long> new_start(m_xStart_p->getDevIO()->read(time_stamp),
      m_yStart_p->getDevIO()->read(time_stamp));
  std::pair<long, long> new_end(m_xEnd_p->getDevIO()->read(time_stamp), m_yEnd_p->getDevIO()->read(
      time_stamp));
  std::pair<long, long> start(-1L, -1L), end(-1L, -1L);

  //Get current image dimensions:
  ret = camera->get_image_area(start, end);

  if (ret == true)
  {
    //Check if new diensions are correct:
    if (new_start >= end)
    {
      m_xStart_p->getDevIO()->write(start.first, time_stamp);
      m_yStart_p->getDevIO()->write(start.second, time_stamp);
      m_xEnd_p->getDevIO()->write(end.first, time_stamp);
      m_yEnd_p->getDevIO()->write(end.second, time_stamp);

      ACS_SHORT_LOG(
          (LM_ERROR, "irisCCD::set_image_dimensions: Cannot set wanted dimensions, because start coordinates > end coordinates. Old dimensions are used. (%d,%d)(%d,%d)", start.first, start.second, end.first, end.second));
      ret = false;
    }
    //Image dimensions are correct:
    else
    {
      ret = camera->set_image_dimensions(new_start, new_end);
      /*
       * Either an error occured, then the old values are restored
       * or everything is fine, then the new values have to be written
       * to the properties.
       * Check if an error occured.
       */
      if (ret == false)
      {
        ret = camera->set_image_dimensions(start, end);
        m_xStart_p->getDevIO()->write(start.first, time_stamp);
        m_yStart_p->getDevIO()->write(start.second, time_stamp);
        m_xEnd_p->getDevIO()->write(end.first, time_stamp);
        m_yEnd_p->getDevIO()->write(end.second, time_stamp);

        ACS_SHORT_LOG(
            (LM_ERROR, "irisCCD::set_image_dimensions: Cannot set wanted dimensions. Old dimensions will be used. (%d,%d)(%d,%d)", new_start.first, new_start.second, new_end.first, new_end.second));
      }
      else
      {
        ACS_SHORT_LOG(
            (LM_INFO, "irisCCD::set_image_dimensions: Wanted dimensions have been set. (%d,%d)(%d,%d)", new_start.first, new_start.second, new_end.first, new_end.second));
        ret = true;
      }
    }
    ret = resize_arrays();
  }
  else //get_image_area returned an error:
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::set_image_dimensions: Cannot set wanted dimensions. The camera seems to be inactive. Image dimensions are NOT set! The property values are NOT valid!"));
  }
  return ret;
}

bool CCD::resize_arrays(void)
{
  long size;

  bool ret(camera->get_image_size(size));

  if (ret != false)
  {
    tempImage->resize(size);
    if (tempImage->size() != static_cast<std::size_t> (size))
    {
      ACS_SHORT_LOG(
          (LM_ERROR, "irisCCD::resize_arrays: Cannot allocate enough temporary memory for image vector. The needed vector size is %d, but the allocated size is %d.", size, tempImage->size()));
      set_error(irisCamera::NOMEM_ERROR);
      return false;
    }
    return true;
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::resize_arrays: Cannot the needed size of temporary image data. Is the camera active?"));
  }
  return false;
}

void CCD::wait_for_next_exposure(void)
{
  waiting_for_next_exposure = true;

  ACS::Time time_stamp(0);
  double wait_seconds(m_waitTimeBetweenExposuresInSequence_p->getDevIO()->read(time_stamp));

  if ((wait_seconds > 0.0) && (stop_exposure == false))
  {
    /*
     * Usually one would call nanosleep only once, but:
     * Wait for wait_loop_counter cycles of 0.001 s.
     * This ensures, that a stopExposureAction will
     * be noticed.
     */
    const long wait_nsecs(ACE_ONE_SECOND_IN_NSECS / 100L);
    const timespec wait_time =
    { 0, wait_nsecs };
    long wait_loop_counter(static_cast<long> (wait_seconds * ACE_ONE_SECOND_IN_NSECS / wait_nsecs));

    ACS_SHORT_LOG(
        (LM_INFO, "irisCCD::wait_for_next_exposure: Waiting for next exposure to start..."));
    
    while ((wait_loop_counter >= 0) && (stop_exposure == false))
    {
      ACE_OS::nanosleep(&wait_time);
      wait_loop_counter--;
    }
  }
  waiting_for_next_exposure = false;
}

bool CCD::setup_camera(void)
{
  bool ret(false);

  /*
   * Set simulation parameters if needed.
   * Fetching RTTI information of polymorphic class.
   * This works very unreliable!
   */
  if (typeid(*camera) == typeid(irisCameraSimulator))
  {
    ret = set_simulation_parameters();
    if (ret == false)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCCD::setup_camera: Cannot set simulation parameters."));
      return ret;
    }
  }

  //Set number of CCD flushes.
  ACS::Time time_stamp(0);
  long number_of_flushes(m_numberOfFlushes_p->getDevIO()->read(time_stamp));
  ret = camera->set_number_of_flushes(number_of_flushes);
  if (ret == false)
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::setup_camera: Cannot set number of flushes to %d.", number_of_flushes));
    return ret;
  }
  else
  {
    ACS_SHORT_LOG((LM_INFO, "irisCCD::setup_camera: Number of flushes=%d.", number_of_flushes));
  }

  //Set image dimensions.
  ret = set_image_dimensions();
  if (ret == false)
  {
    ACS_SHORT_LOG((LM_ERROR, "irisCCD::setup_camera: Cannot set image dimensions."));
    return ret;
  }

  double exp_time(m_exposureTime_p->getDevIO()->read(time_stamp));
  ret = camera->set_camera_exposure_time(exp_time);
  if (ret == false)
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::setup_camera: Cannot set exposure time to %.3f s.", exp_time));
    return ret;
  }
  else
  {
    ACS_SHORT_LOG((LM_INFO, "irisCCD::setup_camera: Exposure time set to %.3f s.", exp_time));
  }

  long frame_type(m_darkFrame_p->getDevIO()->read(time_stamp));
  ret = camera->set_camera_frame_type(frame_type);
  if (ret == false)
  {
    if (frame_type == 1L)
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCCD::setup_camera: Cannot set exposure type to dark."));
    }
    else
    {
      ACS_SHORT_LOG((LM_ERROR, "irisCCD::setup_camera: Cannot set exposure type to normal."));
    }
    return ret;
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_INFO, "irisCCD::setup_camera: Frame type set to %s frame.\nSetup of camera complete.", (frame_type
            == 1L ? "dark" : "normal")));

    //Set time of exposure start property.
    set_time_exposure_start();
  }
  return ret;
}

bool CCD::set_simulation_parameters(void)
{
  bool ret(false);

  ACS::Time time_stamp(0);
  ACS::doubleSeq_var sim_amplitude(m_simulationAmplitude_p->getDevIO()->read(time_stamp));
  ACS::doubleSeq_var sim_positionX(m_simulationX_p->getDevIO()->read(time_stamp));
  ACS::doubleSeq_var sim_positionY(m_simulationY_p->getDevIO()->read(time_stamp));

  long size(sim_amplitude->length());
  if (size < 0L)
  {
    size = 0L;
  }
  sim_amplitude->length(size);
  sim_positionX->length(size);
  sim_positionY->length(size);

  const double field_rotation(m_simulationFieldRotation_p->getDevIO()->read(time_stamp) * M_PI
      / 180.0);
  const std::pair<double, double> centre(
      m_simulationRotationCentreX_p->getDevIO()->read(time_stamp),
      m_simulationRotationCentreY_p->getDevIO()->read(time_stamp));
  std::vector<double>* _amplitude = new std::vector<double>(size);
  std::vector<std::pair<double, double> >* _position = new std::vector<std::pair<double, double> >(
      size);
  long i(0L);
  std::pair<double, double> _old(0.0, 0.0), _new(0.0, 0.0);
  std::vector<double>::iterator amplitude_iterator(_amplitude->begin());
  for (std::vector<std::pair<double, double> >::iterator position_iterator(_position->begin()); position_iterator
      != _position->end(); ++position_iterator, ++amplitude_iterator, ++i)
  {
    (*position_iterator).first = sim_positionX[i];
    (*position_iterator).second = sim_positionY[i];
    (*amplitude_iterator) = sim_amplitude[i];
    if (field_rotation > 0.0)
    {
      _old = (*position_iterator);
      _old.first -= centre.first;
      _old.second -= centre.second;

      _new.first = _old.first * std::cos(field_rotation) + _old.second * std::sin(field_rotation);
      _new.second = (-_old.first) * std::sin(field_rotation) + _old.second * std::cos(
          field_rotation);

      (*position_iterator).first = _new.first + centre.first;
      (*position_iterator).second = _new.second + centre.second;
    }
  }

  std::pair<double, double> _fwhm(m_simulationFwhmX_p->getDevIO()->read(time_stamp),
      m_simulationFwhmY_p->getDevIO()->read(time_stamp));
  long _noise(m_simulationNoise_p->getDevIO()->read(time_stamp));
  double _background(m_simulationBackgroundNoise_p->getDevIO()->read(time_stamp));
  double _readout(m_simulationReadoutNoise_p->getDevIO()->read(time_stamp));

  ret = camera->set_simulation_parameters(*_position, _fwhm, *_amplitude, _noise, _background,
      _readout);

  delete _position;
  delete _amplitude;

  if (ret == true)
  {
    ACS_SHORT_LOG((LM_INFO, "irisCCD::set_simulation_parameters: Wanted parameters have been set."));
  }
  else
  {
    ACS_SHORT_LOG(
        (LM_ERROR, "irisCCD::set_simulation_parameters: Cannot set wanted parameters. The camera seems to be inactive. Parameters are NOT set. The property values are NOT valid."));
  }
  return ret;
}
