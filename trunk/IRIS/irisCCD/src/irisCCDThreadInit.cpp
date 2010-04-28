/*
 * "@(#) $Id: irisCCDThreadInit.cpp,v 1.8  2009/12/03 16:37:29  mparra Exp $"
 *
 * $Log: irisCCDThreadInit.cpp,v $
 * Revision 1.8  2009/12/03 16:37:29  mparra
 * - Adapted to iris telescope name
 * - The method getComponent()->getThreadManager()->getThreadByName("getTemperatureThread")->setSleepTime(static_cast<baci::TimeInterval>(ACE_ONE_SECOND_IN_NSECS/100));
 *   was replace for getComponent()->getThreadManager()->getThreadByName("getTemperatureThread")->setSleepTime(ACE_ONE_SECOND_IN_NSECS/100);
 *   the static_cast<baci::TimeInterval> it's no longer necessary.
 *
 * Revision 1.7  2005/03/07 17:07:53  tjuerges
 * - Added sleep time for temperature thread (1 second).
 *
 * Revision 1.6  2004/09/22 14:16:35  tjuerges
 * - F�r Simulation backgroundNoise und readoutNoise hinzugef�gt, rmsNoise entfernt.
 * - GUI speichert FITS auf Verlangen.
 * - GUI startet externes DS9 und beendet es.
 *
 *
 */

// create and start waitForCameraDone
ACS_SHORT_LOG((LM_INFO,"irisCCD::irisCCDThreadInit: Spawning CameraExposureThread."));
getComponent()->getThreadManager()->create("CameraExposureThread",(void*)(CCD::CameraExposureThread),(void*)(this));
getComponent()->getThreadManager()->suspend("CameraExposureThread");
ACS_SHORT_LOG((LM_INFO,"irisCCD::irisCCDThreadInit: CameraExposureThread is suspended."));

ACS_SHORT_LOG((LM_INFO,"Spawning getTemperatureThread."));
getComponent()->getThreadManager()->create("getTemperatureThread",(void*)(CCD::getTemperatureThread),(void*)(this));
getComponent()->getThreadManager()->suspend("getTemperatureThread");
getComponent()->getThreadManager()->getThreadByName("getTemperatureThread")->setSleepTime(ACE_ONE_SECOND_IN_NSECS/100);
ACS_SHORT_LOG((LM_INFO,"irisCCD::irisCCDThreadInit: getTemperatureThread is suspended."));
