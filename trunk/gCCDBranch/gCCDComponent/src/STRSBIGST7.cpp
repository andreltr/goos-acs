#include "STRSBIGST7.h"

/*
 *
 * Implementation of SBIGST7 strategy for the Strategy Pattern
 *
 */

STRSBIGST7::STRSBIGST7() {

}

STRSBIGST7::~STRSBIGST7() {

}

std::string* STRSBIGST7::getImage(int width, int height, int acquisitionMode,
		int numberOfAcquisitions, float exposureTime) {
	std::cout << "STRSBIGST7::getImage()" << std::endl;

	//Test queue
	int queueSize = 4;
	filesQueue = new std::string[queueSize];
	filesQueue[0] = "inputImg00";
	filesQueue[1] = "inputImg01";
	filesQueue[2] = "inputImg02";
	filesQueue[3] = "null";
	return filesQueue;
}
