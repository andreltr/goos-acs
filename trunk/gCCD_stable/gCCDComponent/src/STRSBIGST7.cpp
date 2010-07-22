#include "STRModelsHeaders/STRSBIGST7.h"
#define IP_ADRESS	0xC0A8010C

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
	this->odp.deviceType = DEV_ETH;
	this->odp.ipAddress = IP_ADRESS;
	p_Cam = new CSBIGCam(odp);
	error = p_Cam->EstablishLink();
	if (error != CE_NO_ERROR) {
		throw 1;
	}
}

void STRSBIGST7::off() {
	cout << "Closing 1st Device..." << endl;
	p_Cam->CloseDevice();
	cout << "Closing 1st Driver..." << endl;
	p_Cam->CloseDriver();
}

void STRSBIGST7::resetCamera() {

}

std::string* STRSBIGST7::startExposure() {
	std::cout << "STRSBIGST7::getImage()" << std::endl;

	p_Img = new CSBIGImg;

	/*
	 * set exposure time before acquire image
	 */
	p_Cam->SetExposureTime(componentProperties->getexposureTime());

	/*
	 * Acquires an entire image. Allocates the image buffer and acquires the
	 * image from the active CCD using the set readout mode, exposure, etc.
	 * It is a high-level exposure command.
	 *
	 * TODO: test high level asynchronous acquiring
	 * p_Cam->GrabSetup(p_Img, SBDF_LIGHT_ONLY);
	 * p_Cam->GrabMain(p_Img, SBDF_LIGHT_ONLY);
	 */
	error = p_Cam->GrabImage(p_Img, SBDF_DARK_ALSO);
	if (error != CE_NO_ERROR) {
		throw 1;
	}
	p_Img->AutoBackgroundAndRange();
	p_Img->SetFocalLength(componentProperties->getfocalLength());
	p_Img->SetObserver(componentProperties->getobserverName());
	p_Img->SetFilter(componentProperties->getfilterName());
	p_Img->SetExposureTime(componentProperties->getexposureTime());
	imageError = p_Img->SaveImage("ST7img.fits", SBIF_FITS);
	if (imageError != SBFE_NO_ERROR) {
		throw 1;
	}

	std::string *filenames = new string[2];
	filenames[0] = "ST7img";
	filenames[1] = "null";

	shutDown();

	return filenames;
}

void STRSBIGST7::stopExposure() {
	p_Cam->EndExposure();
}

void STRSBIGST7::startCooler() {
	coolerEnabled = TRUE;
	double setPoint = componentProperties->getcommandedCCDTemperature();
	error = p_Cam->SetTemperatureRegulation(coolerEnabled, setPoint);
	if (error != CE_NO_ERROR) {
		throw 1;
	}
	componentProperties->setactualCCDTemperature(
			componentProperties->getcommandedCCDTemperature());
	componentProperties->notifyObservers();
	return;
}

void STRSBIGST7::stopCooler() {
	double temp = 0;
	coolerEnabled = FALSE;
	double setPoint = componentProperties->getcommandedCCDTemperature();
	error = p_Cam->SetTemperatureRegulation(coolerEnabled, setPoint);
	if (error != CE_NO_ERROR) {
		throw 1;
	}
	p_Cam->GetCCDTemperature(temp);
	componentProperties->setactualCCDTemperature(temp);
	componentProperties->notifyObservers();
	return;
}

void STRSBIGST7::update() {
	std::cout << "STRSBIGST7::update()" << std::endl;
}

void STRSBIGST7::initialize() {

}

void STRSBIGST7::shutDown() {

}

