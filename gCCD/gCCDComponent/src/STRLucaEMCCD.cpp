#include "STRLucaEMCCD.h"

/*
 *
 * Implementation of Luca EMCCD strategy for the Strategy Pattern
 *
 */

STRLucaEMCCD::STRLucaEMCCD() {

}

STRLucaEMCCD::~STRLucaEMCCD() {

}

void STRLucaEMCCD::on() {

}

void STRLucaEMCCD::off() {

}

void STRLucaEMCCD::resetCamera() {

}

std::string* STRLucaEMCCD::getImage(int width, int height,
		int acquisitionMode, int numberOfAcquisitions, float exposureTime) {
	std::cout << "STRLucaEMCCD::getImage()" << std::endl;

	//int width = 640;
	//int height = 480;

	initialize();
	/*Accumulate mode by default*/
	SetAcquisitionMode(acquisitionMode);
	SetNumberAccumulations(numberOfAcquisitions);
	SetExposureTime(exposureTime);
	StartAcquisition();

	int status;
	at_32* imageData = new at_32[width * height];

	//ofstream fout("image.txt", out);

	//Loop until acquisition finished
	GetStatus(&status);
	while (status == DRV_ACQUIRING)
		GetStatus(&status);

	GetAcquiredData(imageData, width * height);

	//for (int i = 0; i < width * height; i++)
	//	fout << imageData[i] << std::endl;

	SaveAsFITS("./inputImg00_out.FITS", 0);

	delete[] imageData;
	/*This should be returning a std::string* with the file names*/
	shutDown();
	return 0;
}

void STRLucaEMCCD::stopExposure() {

}

void STRLucaEMCCD::initialize() {
	unsigned long error = Initialize("/usr/local/etc/andor");
	if (error != DRV_SUCCESS) {
		std::cout << "Initialization error...exiting" << std::endl;
		return;
	}
	sleep(2);
}

void STRLucaEMCCD::shutDown() {
	ShutDown();
}
