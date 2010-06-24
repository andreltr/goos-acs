#include "STRModelsHeaders/STRgCCDSIM.h"

/*
 * Implementation of gCCDSIM strategy for the Strategy Pattern
 *
 */

STRgCCDSIM::STRgCCDSIM() {
	currentTemp = 0;
}

STRgCCDSIM::~STRgCCDSIM() {

}

void STRgCCDSIM::on() {

}

void STRgCCDSIM::off() {

}

void STRgCCDSIM::resetCamera() {

}

/*Code simulation for FITS creation goes here...*/
std::string* STRgCCDSIM::startExposure() {

	IMAGE_WIDTH = 640;
	IMAGE_HEIGHT = 480;

	double exposureTime = componentProperties->getExposureTime();

	FITS::setVerboseMode(true);

	string *filenames = new string[(int) exposureTime + 1];

	try {
		for (int i = 0; i < (int) exposureTime; i++) {
			if (!writeImage(componentProperties->getNumberOfAcquisitions(), i))
				std::cerr << "";
			std::string s;
			std::stringstream out;
			out << i;
			s = out.str();
			filenames[i] = "gCCDSIMimage" + s;
		}
		filenames[(int) exposureTime] = "null";
	} catch (FitsException&) {
		std::cerr << " Fits Exception Thrown by test function \n";
	}

	return filenames;
}

void STRgCCDSIM::stopExposure() {

}

void STRgCCDSIM::startCooler() {
	//trace for testing only, should be removed
	std::cout << "Current ComponentProperties temp: "
			<< componentProperties->getActualCCDTemperature() << std::endl;

	std::cout << "Current ComponentProperties temp: "
				<< componentProperties->getCommandedCCDTemperature() << std::endl;

	componentProperties->setActualCCDTemperature(
			componentProperties->getCommandedCCDTemperature());
	componentProperties->notifyObservers();
	return;
}

void STRgCCDSIM::stopCooler() {
	return;
}

void STRgCCDSIM::update() {
	std::cout << "STRgCCDSIM::update()" << std::endl;
}

void STRgCCDSIM::setComponentProperties(Observable *observable) {
	componentProperties = (ComponentProperties*) observable;
	setObservable(componentProperties);
}

int STRgCCDSIM::writeImage(int frames, int fileCorrelation) {

	frames--;
	if (frames < 0)
		frames = 0;

	long naxis = 2;
	long naxes[2] = { IMAGE_WIDTH, IMAGE_HEIGHT };

	std::auto_ptr<FITS> pFits(0);

	try {
		std::string s;
		std::stringstream out;
		out << fileCorrelation;
		s = out.str();

		const std::string fileName("!gCCDSIMimage" + s + ".fits");
		pFits.reset(new FITS(fileName, BYTE_IMG, naxis, naxes));
	} catch (FITS::CantCreate) {
		// ... or not, as the case may be.
		return -1;
	}

	long& vectorLength = naxes[0];
	long& numberOfRows = naxes[1];
	long nelements(1);

	nelements = std::accumulate(&naxes[0], &naxes[naxis], 1, std::multiplies<
			long>());

	long fpixel(1);

	for (int i = 0; i < frames; i++) {

		std::string s;
		std::stringstream out;
		out << i;
		s = out.str();

		std::vector<long> extAx(2, 0);
		extAx.front() = IMAGE_WIDTH;
		extAx.back() = IMAGE_HEIGHT;

		string newName("NEW-EXTENSION-" + s);

		ExtHDU* imageExt = pFits->addImage(newName, BYTE_IMG, extAx);

		std::valarray<int> row(vectorLength);

		for (long j = 0; j < vectorLength; ++j)
			row[j] = j;

		std::valarray<int> array(nelements);

		for (int i = 0; i < numberOfRows; ++i) {
			array[std::slice(vectorLength * static_cast<int> (i), vectorLength,
					1)] = row + i;
		}

		long extElements = std::accumulate(&naxes[0], &naxes[naxis], 1,
				std::multiplies<long>());

		std::valarray<float> ranData(extElements);

		const float PIBY(M_PI / 150.);

		for (int jj = 0; jj < extElements; ++jj) {
			float arg = PIBY * jj;
			ranData[jj] = std::cos(arg);
		}

		imageExt->write(fpixel, extElements, array);
	}

	std::valarray<int> array(nelements);
	std::valarray<int> row(vectorLength);
	for (int i = 0; i < numberOfRows; ++i) {
		array[std::slice(vectorLength * static_cast<int> (i), vectorLength, 1)]
				= row + i;
	}

	pFits->pHDU().write(fpixel, nelements, array);
	return 0;
}

/*void *STRgCCDSIM::simulateTemperature(void *commandedCCDTemp) {
 float modifier = 0;

 float *commandedTemp = static_cast<float*> (commandedCCDTemp);

 if (currentTemp > *commandedTemp) {
 modifier = -1.3;
 } else {
 modifier = 1.3;
 }

 clock_t endwait;
 endwait = clock() + 20 * CLOCKS_PER_SEC;
 while (clock() < endwait) {
 currentTemp += modifier;
 }

 currentTemp = *commandedTemp;

 pthread_exit(0);
 }*/

