/*
 * "@(#) $Id: irisCCDThreadImpl.cpp,v 1.14  2009/12/03 16:36:45  mparra Exp $"
 *
 * $Log: irisCCDThreadImpl.cpp,v $
 * Revision 1.14  2009/12/03 16:36:45  mparra
 * - Adapted to iris telescope name.
 * - The SmartPropertyPointer has change the methods read and write, there is no need
 *   to  use the int& variable, so the local definition acs_error has been deleted.
 * - Replace all ACS_SHORT_LOG call by ACS_STATIC_SHORT_LOG call.
 *
 * Revision 1.13  2005/03/09 14:44:47  tjuerges
 * - Changed DO_running to component_running.
 * - Added setting of component_status at end of exposure(s).
 *
 * Revision 1.12  2005/03/07 17:07:23  tjuerges
 * - Changed suspend to sleep call in temperature thread. Thx Roland!
 *
 * Revision 1.11  2005/01/26 11:53:01  tjuerges
 * - Replaced get_sync and set_sync to properties by getDevIO()->read and write.
 * - Added local definitions of acs_error and time_stamp for getDevIO calls.
 *
 * Revision 1.10  2005/01/15 17:43:35  tjuerges
 * - Removed stupid resume call in temperature thread. With the call the
 *   thread resumed itself, suspended itself, resumed itself ...
 *   Result: the container ate 100% CPU time. :-(
 *
 * Revision 1.9  2004/12/28 12:24:17  tjuerges
 * - Added check if component is running in threads due to an unwanted functionality of BACIThreads on slow machines.
 *
 * Revision 1.8  2004/09/22 14:16:35  tjuerges
 * - F�r Simulation backgroundNoise und readoutNoise hinzugef�gt, rmsNoise entfernt.
 * - GUI speichert FITS auf Verlangen.
 * - GUI startet externes DS9 und beendet es.
 *
 *
 */
#include "irisCCDC.h"

void CCD::getTemperatureThread(void* threadParam_p)
{
  if (!threadParam_p)
  {
    return;
  }

  BACIThreadParameter* baciParameter_p(
      static_cast<BACIThreadParameter*> (threadParam_p));
  BACIThread* myself_p(baciParameter_p->getBACIThread());
  CCD* component_p(
      static_cast<CCD*> (const_cast<void*> (baciParameter_p->getParameter())));

  double temperature(-9999.9);
  ACS::Time time_stamp(0);
  bool get_temperature_ok(false);

  if (BACIThread::InitThread)
  {
    BACIThread::InitThread("getTemperatureThread");
  }

  while (myself_p->check())
  {
    if ((!myself_p->isSuspended()) && (component_p->component_running))
    {
      /*
       * Triple check:
       * - Check if DO is active.
       * Then:
       * - Check for no running exposure.
       * - Check if camera is attached and ready.
       */

      if (component_p->camera->get_camera_running() == true)
      {
        get_temperature_ok = component_p->camera->get_camera_temperature(
            temperature);
        if (get_temperature_ok == true)
        {
          component_p->m_actualCCDTemperature_p->getDevIO()->write(temperature,
              time_stamp);
        }

        get_temperature_ok = component_p->camera->get_air_temperature(
            temperature);
        if (get_temperature_ok == true)
        {
          component_p->m_actualAirTemperature_p->getDevIO()->write(temperature,
              time_stamp);
        }
      }
      myself_p->sleep();
    } // Got temperatures.

    /*
     * else: thread is suspended but baciThreadManager created this
     * thread with sleep time=... s. Now every ... s program control reaches
     * this else statement. Easy to wake up oneself.
     else
     {
     // Something useful.
     }
     */
  }

  ACS_STATIC_SHORT_LOG(
      (LM_INFO, "irisCCD::%s: Terminating thread which gets temperature from camera.", myself_p->getName().c_str()));

  if (BACIThread::DoneThread)
  {
    BACIThread::DoneThread();
  }

  delete baciParameter_p;
  myself_p->setStopped();
}

void CCD::CameraExposureThread(void* threadParam_p)
{
  if (!threadParam_p)
  {
    return;
  }

  BACIThreadParameter* baciParameter_p(
      static_cast<BACIThreadParameter*> (threadParam_p));
  BACIThread* myself_p(baciParameter_p->getBACIThread());

  // Variables have to be passed explicitly
  CCD* component_p(
      static_cast<CCD*> (const_cast<void*> (baciParameter_p->getParameter())));

  if (BACIThread::InitThread)
  {
    BACIThread::InitThread("CameraExposureThread");
  }

  while (myself_p->check())
  {
    if ((!myself_p->isSuspended()) && (component_p->component_running))
    {
      //Set up image dimensions.
      long sequence_counter(0L);
      long do_sequence(0L);
      int sequence_unlimited(0);
      bool ret(true);
      ACS::Time time_stamp(0);

      component_p->m_componentStatus_p->getDevIO()->write(irisStatus::WORKING,
          time_stamp);

      //Check if a sequence of exposures is to be done.
      do_sequence = component_p->m_exposureSequence_p->getDevIO()->read(
          time_stamp);
      if (do_sequence == 1L)
      {
        //Yes: read how many exposures to do.
        sequence_counter
            = component_p->m_numberOfExposuresInSequence_p->getDevIO()->read(
                time_stamp);
        if (sequence_counter == -1L)
        {
          sequence_counter = 0L;
          sequence_unlimited = 1;
        }
      }
      else
      {
        //No: only one exposure.
        sequence_counter = 1;
      }

      //Main loop:
      while (((ret == true) && (component_p->stop_exposure == false)
          && (sequence_counter > 0L))
          || ((ret == true) && (component_p->stop_exposure == false)
              && (sequence_unlimited == 1)))
      {
        ret = component_p->setup_camera();
        if (ret == false)
        {
          component_p->camera->abort_exposure();
          component_p->stop_exposure = true;
          ACS_STATIC_SHORT_LOG(
              (LM_ERROR, "irisCCD::%s: Setup of camera failed. NO exposure taken!", myself_p->getName().c_str()));
          break;
        }

        component_p->set_error(irisCamera::EXPOSING);

        //Get time of exposure start.
        component_p->set_time_exposure_start();

        //Make the exposure
        ret = component_p->camera->start_exposure();
        if (ret == false)
        {
          component_p->camera->abort_exposure();
          component_p->stop_exposure = true;
          ACS_STATIC_SHORT_LOG(
              (LM_ERROR, "irisCCD::%s: Exposure not started!", myself_p->getName().c_str()));
          break;
        }

        //Wait for exposure ready.
        ACS_STATIC_SHORT_LOG(
            (LM_INFO, "irisCCD::%s: Waiting for exposure ready...", myself_p->getName().c_str()));

        int dummy;
        ret = component_p->camera->wait_for_exposure_done(dummy);

        //Get time of exposure end.
        component_p->set_time_exposure_end();

        component_p->set_error(-irisCamera::EXPOSING);

        if ((component_p->stop_exposure == true) || (ret == false) || (dummy
            != irisCamera::OK))
        {
          //Exposure has been aborted.
          component_p->camera->abort_exposure();
          //Unset bool that exposure is running
          component_p->stop_exposure = true;
          ACS_STATIC_SHORT_LOG(
              (LM_INFO, "irisCCD::%s: Exposure aborted.", myself_p->getName().c_str()));
          break;
        }
        else if ((component_p->stop_exposure == false) && (ret == true)
            && (dummy == irisCamera::OK))
        {
          //Exposure has been successfully taken.
          ACS_STATIC_SHORT_LOG(
              (LM_INFO, "irisCCD::%s: Exposure ready.", myself_p->getName().c_str()));
          /*
           Try to download the image date from the camera.
           */
          component_p->set_error(irisCamera::DOWNLOADING_FROM_CAMERA);
          ret = component_p->camera->download_image_from_camera(
              component_p->tempImage);
          component_p->set_error(-irisCamera::DOWNLOADING_FROM_CAMERA);
          if (ret == false)
          {
            component_p->stop_exposure = true;
            ACS_STATIC_SHORT_LOG(
                (LM_ERROR, "irisCCD::%s: Aborting download! Something is wrong with the camera.", myself_p->getName().c_str()));
            break;
          }

          ret = component_p->transfer_image_to_ACS();
          if (ret == false)
          {
            component_p->stop_exposure = true;
            ACS_STATIC_SHORT_LOG(
                (LM_ERROR, "irisCCD::%s: Transfer to ACS failed!", myself_p->getName().c_str()));
            break;
          }

        }
        /*End of else in if statement, which checks for
         * aborted exposure. The exposure has been successfully taken.
         */
        else
        {
          component_p->camera->abort_exposure();
          component_p->stop_exposure = true;
          ACS_STATIC_SHORT_LOG(
              (LM_ERROR, "irisCCD::%s: Exposure aborted because the camera reported an error while asking it for its status.", myself_p->getName().c_str()));
          break;
        }

        //Subtract on exposure from counter. But do only if not unlimited sequence.
        if (sequence_unlimited == 0L)
        {
          --sequence_counter;
        }

        if (((sequence_counter > 0) || (sequence_unlimited == 1L))
            && (do_sequence == 1L))
        {
          component_p->wait_for_next_exposure();
        }

        if (component_p->stop_exposure == true)
        {
          ACS_STATIC_SHORT_LOG(
              (LM_INFO, "irisCCD::%s: Exposure aborted!", myself_p->getName().c_str()));
          break;
        }
      } // End of main loop.
      // Too much work. Got to bed again. :)
      component_p->m_componentStatus_p->getDevIO()->write(irisStatus::ON,
          time_stamp);
      myself_p->suspend();
    }

    /*
     * This point is reached if the thread is suspended.
     * One could add an else statement to the if statement if the thread is suspended.
     else
     {
     The thread is suspended. Do something different.
     }
     */
  }

  // This point is reached if the thread is terminated.

  ACS_STATIC_SHORT_LOG(
      (LM_INFO, "irisCCD::%s: Terminating thread which gathers image data.", myself_p->getName().c_str()));

  if (BACIThread::DoneThread)
  {
    BACIThread::DoneThread();
  }

  delete baciParameter_p;
  myself_p->setStopped();
}
