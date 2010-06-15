#include "STRSBIGST7.h"
#define IP_ADDRESS	0xC0A8010C

/*
 *
 * Implementation of SBIGST7 strategy for the Strategy Pattern
 *
 */

STRSBIGST7::STRSBIGST7() {
	p_Cam = 0;
	p_Img = 0;

}

STRSBIGST7::~STRSBIGST7() {
	if (p_Cam != 0) {
		delete p_Cam;
	}
	if (p_Img != 0) {
		delete p_Img;
	}

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

}

void STRSBIGST7::startCooler(float commandedCCDTemp) {
	return;
}

void STRSBIGST7::stopCooler() {
	return;
}

void STRSBIGST7::initialize() {
	this->odp.deviceType = DEV_ETH;
	this->odp.ipAddress = IP_ADDRESS;
	p_Cam = new CSBIGCam(odp);
	p_Cam->EstablishLink();
}

void STRSBIGST7::shutDown() {
	cout << "Closing 1st Device..." << endl;
	p_Cam->CloseDevice();
	cout << "Closing 1st Driver..." << endl;
	p_Cam->CloseDriver();
}
