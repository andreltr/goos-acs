#include "luckyCameraSTRLuckyEMCCD.h"

/*
 *
 * Implementation of Lucky EMCCD strategy for the Strategy Pattern
 *
 */

STRLuckyEMCCD::STRLuckyEMCCD() {

}

STRLuckyEMCCD::~STRLuckyEMCCD() {

}

std::string* STRLuckyEMCCD::getImage(int width, int height,
		int acquisitionMode, int numberOfAcquisitions, float exposureTime) {
	std::cout << "STRLuckyEMCCD::getImage()" << std::endl;

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

void STRLuckyEMCCD::initialize() {
	unsigned long error = Initialize("/usr/local/etc/andor");
	if (error != DRV_SUCCESS) {
		std::cout << "Initialization error...exiting" << std::endl;
		return;
	}
	sleep(2);
}

void STRLuckyEMCCD::shutDown() {
	ShutDown();
}
