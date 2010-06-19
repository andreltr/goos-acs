#include "STRSBIGST7.h"
#define IP_ADRESS	0xC0A8010C

/*
 *
 * Implementation of SBIGST7 strategy for the Strategy Pattern
 *
 */

STRSBIGST7::STRSBIGST7() {

}

STRSBIGST7::~STRSBIGST7() {
	delete p_Cam;
	delete p_Img;

}

void STRSBIGST7::on() {

}

void STRSBIGST7::off() {

}

void STRSBIGST7::resetCamera() {

}

std::string* STRSBIGST7::getImage(int width, int height, int acquisitionMode,
		int numberOfAcquisitions, float exposureTime) {
	std::cout << "STRSBIGST7::getImage()" << std::endl;

	initialize();
	p_Img = new CSBIGImg;

	/*
	 * set exposure time before acquire image
	 */
	p_Cam->SetExposureTime((double) exposureTime);

	/*
	 * Acquires an entire image. Allocates the image buffer and acquires the
	 * image from the active CCD using the set readout mode, exposure, etc.
	 * It is a high-level exposure command.
	 *
	 * TODO: test high level asynchronous acquiring
	 * p_Cam->GrabSetup(p_Img, SBDF_LIGHT_ONLY);
	 * p_Cam->GrabMain(p_Img, SBDF_LIGHT_ONLY);
	 */
	p_Cam->GrabImage(p_Img, SBDF_LIGHT_ONLY);
	p_Img->AutoBackgroundAndRange();
	p_Img->SaveImage("img1.fits", SBIF_FITS);

	std::string *filenames = new string[2];
	filenames[0] = "img1";
	filenames[1] = "null";

	shutDown();

	return filenames;
}

void STRSBIGST7::stopExposure() {
	p_Cam->EndExposure();

}

void STRSBIGST7::initialize() {
	this->odp.deviceType = DEV_ETH;
	this->odp.ipAddress = IP_ADRESS;
	p_Cam = new CSBIGCam(odp);
	p_Cam->EstablishLink();
}

void STRSBIGST7::shutDown() {
	cout << "Closing 1st Device..." << endl;
	p_Cam->CloseDevice();
	cout << "Closing 1st Driver..." << endl;
	p_Cam->CloseDriver();
}
