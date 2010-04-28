/*
 * "@(#) $Id: irisCCDGUISaveDataToDisk.cpp,v 1.18  2009/12/03 15:48:37  mparra Exp $"
 *
 * $Log: irisCCDGUISaveDataToDisk.cpp,v $
 * Revision 1.18  2009/12/03 15:48:37  mparra
 * - Adapted to IRIS telescope name.
 *
 * Revision 1.17  2005/02/11 14:48:37  tjuerges
 * - Added wait in case the same thread is already running when a new image arrives.
 *
 * Revision 1.16  2005/02/02 16:44:58  tjuerges
 * - Used different (direct) way of xpaset for displaying images.
 *
 * Revision 1.15  2005/02/02 14:45:38  tjuerges
 * - Added functionality: displaying of every nth frame is possible.
 *
 * Revision 1.14  2005/01/31 17:19:17  tjuerges
 * - Added a -title option to xpaset process. This enables ds9 do distinguish between different clients which want to show images.
 *
 * Revision 1.13  2005/01/26 11:50:40  tjuerges
 * - Added ACSErr::Completion_var to local method.
 *
 * Revision 1.12  2004/12/28 17:31:12  tjuerges
 * - Added #ifdefs for developers not using the IRIS software. Say make -DNO_IRIS_USAGE to make the package compile without other iris ACS components.
 *
 * Revision 1.11  2004/12/28 13:43:21  tjuerges
 * - Changes needed due to strange bahaviour of SimpleClient. No two different connections to the same component from one SimpleCLient are possible.
 *
 * Revision 1.10  2004/12/09 16:45:25  tjuerges
 * - Added check for is_nil of camera object in destroy_monitor.
 *
 * Revision 1.9  2004/11/25 19:48:47  tjuerges
 * - Wrong camera name in client connection corrected.
 *
 * Revision 1.8  2004/11/25 17:51:56  tjuerges
 * - Added saving of MCU, M1 and M2 positions.
 *
 * Revision 1.7  2004/11/18 08:49:39  tjuerges
 * - myMonitor templates in irisStarUtils has been changed to use only two template parameters.
 *
 * Revision 1.6  2004/11/15 18:57:29  tjuerges
 * - Changed create_Monitor call to create_monitor respecting changes in irisStarUtils.
 *
 * Revision 1.5  2004/11/15 10:20:36  tjuerges
 * - Anpassungen an neues Monitor-Template.
 *
 * Revision 1.4  2004/11/02 13:20:47  tjuerges
 * - Datenpfad wird nicht mehr im Empf�nger gesetzt, sondern vom GUI selbst.
 *
 * Revision 1.1  2004/09/22 14:16:35  tjuerges
 * - F�r Simulation backgroundNoise und readoutNoise hinzugef�gt, rmsNoise entfernt.
 * - GUI speichert FITS auf Verlangen.
 * - GUI startet externes DS9 und beendet es.
 *
 *
 */

#include <iterator>
#include <algorithm>
#include <baciC.h>
#include <acstime.h>
#include <ace/Time_Value.h>
#include <irisCCDGUISaveDataToDisk.h>
#include <irisCCDC.h>
#include <logging.h>
#include <qmutex.h>

extern irisCCD::CCD_var camera;

void SaveDataToDisk::run(void) {
	/* All right, a new exposure has been taken.
	 * 1. Get image dimensions.
	 * 2. Get image data.
	 * 3. Get telescope commanded position
	 * and offsets of commanded position and everything else. :)
	 * 4. Get starting and ending time of exposure.
	 * 5. Get misc. camera and telescope parameters.
	 *
	 * General remark: here we rely on processing image data one at a time.
	 * Ok for single images but not ok for too fast delivery by camera as
	 * image-object  might be partially overwritten before we processed it.
	 * To be improved....
	 *
	 * TJ: Now this runs in a thread which might make things more reliable.
	 */

	// 1.
	ACSErr::Completion_var completion;

	img_width = xEnd->get_sync(completion.out()) - xStart->get_sync(
			completion.out());
	img_height = yEnd->get_sync(completion.out()) - yStart->get_sync(
			completion.out());
	img_width++;
	img_height++;
	data = new std::vector<unsigned short int>(
			static_cast<std::size_t> (img_width * img_height));
	if (data->size() != static_cast<std::size_t> (img_width * img_height)) {
		delete data;
		ACS_SHORT_LOG(
				(LM_ERROR, "SaveDataToDisk::image_arrived: Not enough memory for image data available. Aborting!"));
		return;
	}

	// 2.
	ACS::longSeq_var image_data;
	image_data = img_sequence->get_sync(completion.out());

	ACS_SHORT_LOG(
			(LM_INFO, "SaveDataToDisk::image_arrived: An image arrived with dimensions (x,y): (%d,%d) with %d pixel.", img_width, img_height, image_data->length()));

	// 3.
	write_fits* wfits = new write_fits; // Setup a writing FITS class...

#ifndef NO_IRIS_USAGE
	if (!CORBA::is_nil(mount.in())) {
		ra_val = ra->get_sync(completion.out());
		dec_val = dec->get_sync(completion.out());
		az_val = az->get_sync(completion.out());
		ele_val = ele->get_sync(completion.out());
		ra_offset_val = ra_offset->get_sync(completion.out());
		dec_offset_val = dec_offset->get_sync(completion.out());

		pol_val = pol->get_sync(completion.out());
		az_offset_val = az_offset->get_sync(completion.out());
		ele_offset_val = ele_offset->get_sync(completion.out());
		pol_offset_val = pol_offset->get_sync(completion.out());

		equinox_val = equinox->get_sync(completion.out());

		wfits->set_RA_coord(static_cast<double> (ra_val));
		wfits->set_DEC_coord(static_cast<double> (dec_val));
		wfits->set_POL_coord(static_cast<double> (pol_val));
		wfits->set_AZ_coord(static_cast<double> (az_val));
		wfits->set_ELE_coord(static_cast<double> (ele_val));

		wfits->set_RA_offset(static_cast<double> (ra_offset_val));
		wfits->set_DEC_offset(static_cast<double> (dec_offset_val));
		wfits->set_POL_offset(static_cast<double> (pol_offset_val));
		wfits->set_AZ_offset(static_cast<double> (az_offset_val));
		wfits->set_ELE_offset(static_cast<double> (ele_offset_val));

		wfits->set_equinox(static_cast<double> (equinox_val));
	}
#endif

	// 4.
	exposureTime_val = exposureTime->get_sync(completion.out());
	timeExposureStart_val = timeExposureStart->get_sync(completion.out());
	timeExposureEnd_val = timeExposureEnd->get_sync(completion.out());
	wfits->set_exposure_time(static_cast<double> (exposureTime_val));
	wfits->set_start_time(static_cast<std::string> (timeExposureStart_val));
	wfits->set_end_time(static_cast<std::string> (timeExposureEnd_val));

	// 5.
	cameraName_val = cameraName->get_sync(completion.out());
	darkFrame_val = darkFrame->get_sync(completion.out());
	filterName_val = filterName->get_sync(completion.out());
	observerName_val = observerName->get_sync(completion.out());
	objectName_val = objectName->get_sync(completion.out());
	telescopeName_val = telescopeName->get_sync(completion.out());
	actualCCDTemperature_val = actualCCDTemperature->get_sync(completion.out());
	actualAirTemperature_val = actualAirTemperature->get_sync(completion.out());
	focalLength_val = focalLength->get_sync(completion.out());

	if (pathname.length() > 0) {
		wfits->set_filename_root(pathname);
	}
	if ((exposureTime_val == 0.0) && (darkFrame_val == 1L)) {
		wfits->set_exposure_type(BIAS);
	} else if ((exposureTime_val != 0.0) && (darkFrame_val == 1L)) {
		wfits->set_exposure_type(DARK);
	} else if ((exposureTime_val != 0.0) && (darkFrame_val == 0L)) {
		wfits->set_exposure_type(OBJECT);
	} else {
		/* HELP_REQUEST
		 * Attention: Cannot determine difference between FLAT and OBJECT
		 * frames with exposure time and dark frame only.
		 * So this point will be never reached. Some intelligent stuff
		 * should be done to determine the difference!
		 */
		wfits->set_exposure_type(FLAT);
	}

	wfits->set_telescope_name(static_cast<std::string> (telescopeName_val));
	wfits->set_instrument_name(static_cast<std::string> (cameraName_val));
	wfits->set_filter_name(static_cast<std::string> (filterName_val));
	wfits->set_observer_name(static_cast<std::string> (observerName_val));
	wfits->set_object_name(static_cast<std::string> (objectName_val));
	const std::string dummy_origin("AIRUB");
	wfits->set_origin_name(dummy_origin);
	wfits->set_focal_length(static_cast<double> (focalLength_val));
	wfits->set_pixel_width(static_cast<double> (xPixelSize_val));
	wfits->set_pixel_height(static_cast<double> (yPixelSize_val));
	wfits->set_gain(static_cast<double> (gain_val));
	wfits->set_ccd_temperature(static_cast<double> (actualCCDTemperature_val));

	/* The FLI camera does not have an air temperature sensor.
	 * Thus the read value will be the default value of -9999.9 and it is
	 * quite unnecessary to store this value in the FITS file.
	 */
	if (actualAirTemperature_val > -9999.9) {
		wfits->set_air_temperature(
				static_cast<double> (actualAirTemperature_val));
	}

	ACS_SHORT_LOG(
			(LM_INFO, "SaveDataToDisk::image_arrived: Copying image data..."));
	long i(0L);
	try {
		for (i = (img_width * img_height) - 1; i >= 0; --i) {
			(*data)[i] = static_cast<unsigned short int> (image_data[i]);
		}
	} catch (...) {
		long row = i / img_width;
		long column = i - row * img_width;
		ACS_SHORT_LOG(
				(LM_ERROR, "SaveDataToDisk::image_arrived: Cannot access data at index %d, which is pixel (%d,%d). Aborting!", i, column, row));
		delete data;
		delete wfits;
		return;
	}
	ACS_SHORT_LOG(
			(LM_INFO, "SaveDataToDisk::image_arrived: Copying image data complete. Writing FITS file if wanted..."));

	wfits->write_fits_file(img_width, img_height, &(data[0]));
	wfits->get_last_filename(last_filename);
	display_file(last_filename);
	if (saveImage == false) {
		delete_image();
	}

	// Backup image data.
	last_img_width = img_width;
	last_img_height = img_height;

	if (last_data) {
		delete last_data;
	}
	last_data = data;

	if (last_image) {
		delete last_image;
	}
	last_image = wfits;
}

void SaveDataToDisk::save_last(void) {
	if (last_image && last_data) {
		last_image->write_fits_file(last_img_width, last_img_height,
				&(last_data[0]));
	}
}

void SaveDataToDisk::delete_image(void) {
	if (last_filename.size() == 0) {
		ACS_SHORT_LOG(
				(LM_INFO, "SaveDataToDisk::delete_image: No image to delete yet."));
		return;
	}

	std::string command("rm -f ");
	command += last_filename;
	ACE_OS::system(command.c_str());
	ACS_SHORT_LOG(
			(LM_INFO, "SaveDataToDisk::delete_image: image %s deleted.", last_filename.c_str()));
	last_filename = "";
}

void SaveDataToDisk::enable_save(bool on) {
	saveImage = on;
}

void SaveDataToDisk::activate(bool on) {
	if (on == true) {
		disconnect();
		connect();
	} else {
		disconnect();
	}
}

void SaveDataToDisk::set_pathName(const QString& _path) {
	pathname = _path.latin1();
}

SaveDataToDisk::~SaveDataToDisk(void) {
	disconnect();
	if (last_image) {
		delete last_image;
	}
	if (last_data) {
		delete last_data;
	}
}

void SaveDataToDisk::connect(void) {
	try {
		connect_to_components();
		setup_property_values();
		setup_monitor();
	} catch (...) {
		ACS_SHORT_LOG(
				(LM_ERROR, "SaveDataToDisk::setup_cameraName: Something weird happened while setup of the client class. Check the source code for bugs!"));
	};
}

void SaveDataToDisk::disconnect(void) {
	/*
	 Every method mentioned below will take care about
	 the fact that a monitor/propoerty may be NOT initialized.
	 */
	destroy_monitor();
	destroy_properties();
	release_components();
}

void SaveDataToDisk::setSimpleClient(maci::SimpleClient* theClient) {
	mySimpleClient = theClient;

	display_nth_frame = 1;
	monitor = 0;
#ifndef NO_IRIS_USAGE
	client_Mnt = 0;
#endif

	last_image = 0;
	last_data = 0;
	saveImage = false;
}

void SaveDataToDisk::set_cameraName(const QString& _camname) {
	std::string camname(_camname.latin1());

	if ((camname != "CCD_FLI") && (camname != "CCD_ST9") && (camname
			!= "CCD_STL") && (camname != "CCD_IRIS") && (camname
			!= "CCD_Simulator")) {
		ACS_SHORT_LOG(
				(LM_ERROR, "SaveDataToDisk::set_camera_name: Please pass a the name of the camera for which this client is responsible as parameter:\n\tFLI\n\tST9\n\tSTL\n\tSimulator\n"));
		return;
	}
	camera_name = camname;
}

/*
 * Called by by the monitoring class.
 * See irisStarUtils/include/irisStarUtils.h->Mopnitors
 * for details.
 */
void SaveDataToDisk::image_arrived(void) {
	if (this->running() == true) {
		this->wait();
	}
	this->start();
}

void SaveDataToDisk::connect_to_components(void) {

#ifndef NO_IRIS_USAGE
	// Get the Mnt, MCU, M1 and M2 components.
	client_Mnt = new myComponentClient<irisMnt::Mnt> (std::string("Mnt"),
			mySimpleClient);
	client_Mnt->connect();
	mount = client_Mnt->get_object();
#endif
}

void SaveDataToDisk::release_components(void) {
#ifndef NO_IRIS_USAGE
	if (client_Mnt) {
		delete client_Mnt;
		client_Mnt = 0;
	}
#endif
}

// Fetch the real references to ACS properties: 
void SaveDataToDisk::setup_property_values(void) {
	img_sequence = camera->imageData();
	xPixelSize = camera->xPixelSize();
	yPixelSize = camera->xPixelSize();
	gain = camera->gain();
	actualCCDTemperature = camera->actualCCDTemperature();
	actualAirTemperature = camera->actualAirTemperature();
	xStart = camera->xStart();
	xEnd = camera->xEnd();
	yStart = camera->yStart();
	yEnd = camera->yEnd();
	exposureTime = camera->exposureTime();
	darkFrame = camera->darkFrame();
	timeExposureStart = camera->timeExposureStart();
	timeExposureEnd = camera->timeExposureEnd();
	focalLength = camera->focalLength();
	telescopeName = camera->telescopeName();
	filterName = camera->filterName();
	observerName = camera->observerName();
	objectName = camera->objectName();
	cameraName = camera->cameraName();
	numberOfFlushes = camera->numberOfFlushes();
	commandedCCDTemperature = camera->commandedCCDTemperature();
	exposureSequence = camera->exposureSequence();
	numberOfExposuresInSequence = camera->numberOfExposuresInSequence();
	waitTimeBetweenExposuresInSequence
			= camera->waitTimeBetweenExposuresInSequence();

#ifndef NO_IRIS_USAGE
	if (!CORBA::is_nil(mount.in())) {
		ra = mount->referenceRA();
		dec = mount->referenceDec();
		az = mount->referenceAz();
		ele = mount->referenceEl();
		pol = mount->referencePolarisation();
		ra_offset = mount->offsetRA();
		dec_offset = mount->offsetDec();
		az_offset = mount->offsetAz();
		ele_offset = mount->offsetEl();
		pol_offset = mount->offsetPolarisation();
		equinox = mount->JEpoch();
	}
#endif

	telescopeName_val = telescopeName->get_sync(completion.out());
	cameraName_val = cameraName->get_sync(completion.out());
	xPixelSize_val = xPixelSize->get_sync(completion.out());
	yPixelSize_val = yPixelSize->get_sync(completion.out());
	pixel_square = std::sqrt(xPixelSize_val * yPixelSize_val);
	gain_val = gain->get_sync(completion.out());
}

void SaveDataToDisk::destroy_properties(void) {
	/*
	 * For future use of property deletion and
	 * intended for cleaning up client space
	 * if not already done...
	 */

}

void SaveDataToDisk::display_file(const std::string& file) {
	display_nth_frame_mutex.lock();
	static int nth_frame(0);
	++nth_frame;

	if (display_nth_frame == nth_frame) {
		std::string display_command("xpaset -p ");
		display_command += camera_name.c_str();
		display_command += " file ";
		display_command += file;
		ACE_OS::system(display_command.c_str());
		nth_frame = 0;
	} else if (nth_frame > display_nth_frame) {
		nth_frame = display_nth_frame - 1;
	}
	display_nth_frame_mutex.unlock();
}

void SaveDataToDisk::set_display_nth_frame(int n) {
	/*
	 * Avoid setting the property while display_file() is accessing it.
	 */
	display_nth_frame_mutex.lock();
	display_nth_frame = n;
	display_nth_frame_mutex.unlock();
}

void SaveDataToDisk::setup_monitor(void) {
	ACS_SHORT_LOG(
			(LM_INFO, "SaveDataToDisk::setup_monitor: Creating monitor for CCD image counter..."));
	/*
	 Pass the name of the wanted property to the callback class
	 constructor.
	 */
	monitor = new myMonitor(long,SaveDataToDisk)(std::string("imageReady"), &SaveDataToDisk::image_arrived, this);
	if (!monitor->create_monitor(camera->imageReady(), 0, 1, true)) {
		ACS_SHORT_LOG(
				(LM_ERROR, "SaveDataToDisk::setup_monitor: Monitor object NOT created. It seems that the property \"imageReady\" is not available."));
		delete monitor;
		monitor = 0;
	}
}

void SaveDataToDisk::destroy_monitor(void) {
	if (!CORBA::is_nil(camera.in())) {
		if (monitor) {
			delete monitor;
			monitor = 0;
		}
	}
}
