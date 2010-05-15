#include "STROcaSimCCD.h"

/*
 * Implementation of OcaSimCCD strategy for the Strategy Pattern
 *
 */

STROcaSimCCD::STROcaSimCCD() {

}

STROcaSimCCD::~STROcaSimCCD() {

}

/*Code simulation for FITS creation goes here...*/
std::string* STROcaSimCCD::getImage(int width, int height, int acquisitionMode,
		int numberOfAcquisitions, float exposureTime) {

	iMAGES_WIDTH = width;
	iMAGES_HEIGHT = height;

	FITS::setVerboseMode(true);

	string *filenames = new string[((int) exposureTime) + 1];

	try {
		for (int i = 0; i < (int) exposureTime; i++) {
			if (!writeImage(numberOfAcquisitions, i))
				std::cerr << "";
			std::string s;
			std::stringstream out;
			out << i;
			s = out.str();
			filenames[i] = "capture" + s;
		}
		filenames[(int) exposureTime] = "null";
	} catch (FitsException&) {
		std::cerr << " Fits Exception Thrown by test function \n";
	}

	return filenames;
}

int STROcaSimCCD::writeImage(int frames, int fileCorrelation) {

	frames--;
	if (frames < 0)
		frames = 0;

	long naxis = 2;
	long naxes[2] = { iMAGES_WIDTH, iMAGES_HEIGHT };

	std::auto_ptr<FITS> pFits(0);

	try {
		std::string s;
		std::stringstream out;
		out << fileCorrelation;
		s = out.str();

		const std::string fileName("!capture" + s + ".fits");
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
		extAx.front() = iMAGES_WIDTH;
		extAx.back() = iMAGES_HEIGHT;

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

