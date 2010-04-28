/*
 *
 * "@(#) $Id: irisCCDImplInit.cpp,v 1.10 2005/03/09 14:46:52 tjuerges Exp $"
 *
 * $Log: irisCCDImplInit.cpp,v $
 * Revision 1.10  2005/03/09 14:46:52  tjuerges
 * - Changed DO_running to component_running.
 *
 * Revision 1.9  2005/01/31 10:35:16  tjuerges
 * - Fixed memory leaks.
 *
 * Revision 1.8  2005/01/26 11:52:33  tjuerges
 * - Replaced get_sync and set_sync to properties by getDevIO()->read and write.
 * - Added local definitions of acs_error and time_stamp for getDevIO calls.
 *
 * Revision 1.7  2004/09/26 13:13:29  tjuerges
 * *** empty log message ***
 *
 *
 */

component_running=stop_exposure=waiting_for_next_exposure=false;
camera=0;
timeservice=0;
tempImage=new std::vector<unsigned short int>;
