#include "luckyCameraSTRTestCCD.h"

/*
 *
 * Implementation of a Test strategy for the Strategy Pattern
 *
 */

STRTestCCD::STRTestCCD() {

}

STRTestCCD::~STRTestCCD() {

}

std::string* STRTestCCD::getImage(int width, int height, int acquisitionMode,
		int numberOfAcquisitions, float exposureTime) {
	std::cout << "STRTestCCD::getImage()" << std::endl;

	 //Test queue
	 int queueSize = 4;
	 filesQueue = new std::string[queueSize];
	 filesQueue[0] = "inputImg00";
	 filesQueue[1] = "inputImg01";
	 filesQueue[2] = "inputImg02";
	 filesQueue[3] = "null";
	 return filesQueue;
}
