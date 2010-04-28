/*
 *
 * "@(#) $Id: irisCCDLocalProperties.h,v 1.11  2009/12/04 10:37:25  mparra Exp $"
 *
 * $Log: irisCCDLocalProperties.h,v $
 * Revision 1.11  2009/12/04 10:37:25  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.10  2005/03/09 14:34:27  tjuerges
 * - Changed DO_running to component_running.
 *
 * Revision 1.9  2005/01/26 11:51:25  tjuerges
 * - Removed acs_error and time_stamp from global definition.
 *
 * Revision 1.8  2004/11/04 15:33:59  tjuerges
 * - time_stamp in ACS::Time ge�ndert.
 *
 * Revision 1.7  2004/09/26 13:13:11  tjuerges
 * *** empty log message ***
 *
 *
 */

//Image data goes to these vectors:
std::vector<unsigned short int>* tempImage;

// Time service class:
myTimeService* timeservice;

//Time service stuff
double myEpoch;
std::string myTime;

// Camera class:
irisCamera* camera;
std::string camera_name;

//Checkpoints:
bool component_running, stop_exposure, waiting_for_next_exposure;

//Worker threads
static void CameraExposureThread(void*);
static void getTemperatureThread(void*);
//

//Stuff
void set_error(int);
void set_to_error(int);

bool transfer_image_to_ACS(void);
void set_time_exposure_start(void);
void set_time_exposure_end(void);
bool set_image_dimensions(void);
bool resize_arrays(void);
void wait_for_next_exposure(void);
bool setup_camera(void);
bool set_simulation_parameters(void);
//
