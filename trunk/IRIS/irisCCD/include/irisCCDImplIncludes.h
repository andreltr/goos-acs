/*
 *
 * "@(#) $Id: irisCCDImplIncludes.h,v 1.8  2009/12/04 10:37:25  mparra Exp $"
 *
 * $Log: irisCCDImplIncludes.h,v $
 * Revision 1.8  2009/12/04 10:37:25  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.7  2005/01/21 14:25:22  tjuerges
 * - Added utility header file for std::pair type.
 *
 * Revision 1.6  2004/09/22 14:15:58  tjuerges
 * - F�r Simulation backgroundNoise und readoutNoise hinzugef�gt, rmsNoise entfernt.
 * - GUI speichert FITS auf Verlangen.
 * - GUI startet externes DS9 und beendet es.
 *
 *
 */

#include <typeinfo>
#include <utility>
#include <irisCameraFactory.h>
#include <irisCameraSimulator.h>
