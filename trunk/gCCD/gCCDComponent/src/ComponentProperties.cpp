#include "ComponentProperties.h"

ComponentProperties::ComponentProperties() {
	actualAirTemperature = 0;
	actualCCDTemperature = 0;
	commandedCCDTemperature = 0;
	cameraName = "";
	cameraModel = 0;
	filterName = "";
	objectName = "";
	observerName = "";
	exposureTime = 0;
	acquisitionMode = 0;
	numberOfAcquisitions = 0;
	focalLength = 0;
	gain = 0;
	xPixelSize = 0;
	yPixelSize = 0;
	xStart = 0;
	xEnd = 0;
	yStart = 0;
	yEnd = 0;
}

ComponentProperties::~ComponentProperties() {
}

double ComponentProperties::getActualAirTemperature() {
	return actualAirTemperature;
}
double ComponentProperties::getActualCCDTemperature() {
	return actualCCDTemperature;
}
double ComponentProperties::getCommandedCCDTemperature() {
	return commandedCCDTemperature;
}
std::string ComponentProperties::getCameraName() {
	return cameraName;
}
long ComponentProperties::getCameraModel() {
	return cameraModel;
}
std::string ComponentProperties::getFilterName() {
	return filterName;
}
std::string ComponentProperties::getObjectName() {
	return objectName;
}
std::string ComponentProperties::getObserverName() {
	return observerName;
}
double ComponentProperties::getExposureTime() {
	return exposureTime;
}
long ComponentProperties::getAcquisitionMode() {
	return acquisitionMode;
}
long ComponentProperties::getNumberOfAcquisitions() {
	return numberOfAcquisitions;
}
double ComponentProperties::getFocalLength() {
	return focalLength;
}
double ComponentProperties::getGain() {
	return gain;
}
double ComponentProperties::getxPixelSize() {
	return xPixelSize;
}
double ComponentProperties::getyPixelSize() {
	return yPixelSize;
}
long ComponentProperties::getxStart() {
	return xStart;
}
long ComponentProperties::getxEnd() {
	return xEnd;
}
long ComponentProperties::getyStart() {
	return yStart;
}
long ComponentProperties::getyEnd() {
	return yEnd;
}

void ComponentProperties::setActualAirTemperature(double actualAirTemperature) {
	if (this->actualAirTemperature != actualAirTemperature) {
		this->actualAirTemperature = actualAirTemperature;
	}
}
void ComponentProperties::setActualCCDTemperature(double actualCCDTemperature) {
	if (this->actualCCDTemperature != actualCCDTemperature) {
		this->actualCCDTemperature = actualCCDTemperature;
	}
}
void ComponentProperties::setCommandedCCDTemperature(
		double commandedCCDTemperature) {
	if (this->commandedCCDTemperature != commandedCCDTemperature) {
		this->commandedCCDTemperature = commandedCCDTemperature;
	}
}
void ComponentProperties::setCameraName(std::string cameraName) {
	if (this->cameraName != cameraName) {
		this->cameraName = cameraName;
	}
}
void ComponentProperties::setCameraModel(long cameraModel) {
	if (this->cameraModel != cameraModel) {
		this->cameraModel = cameraModel;
	}
}
void ComponentProperties::setFilterName(std::string filterName) {
	if (this->filterName != filterName) {
		this->filterName = filterName;
	}
}
void ComponentProperties::setObjectName(std::string objectName) {
	if (this->objectName != objectName) {
		this->objectName = objectName;
	}
}
void ComponentProperties::setObserverName(std::string observerName) {
	if (this->observerName != observerName) {
		this->observerName = observerName;
	}
}
void ComponentProperties::setExposureTime(double exposureTime) {
	if (this->exposureTime != exposureTime) {
		this->exposureTime = exposureTime;
	}
}
void ComponentProperties::setAcquisitionMode(long acquisitionMode) {
	if (this->acquisitionMode != acquisitionMode) {
		this->acquisitionMode = acquisitionMode;
	}
}
void ComponentProperties::setNumberOfAcquisitions(long numberOfAcquisitions) {
	if (this->numberOfAcquisitions != numberOfAcquisitions) {
		this->numberOfAcquisitions = numberOfAcquisitions;
	}
}
void ComponentProperties::setFocalLength(double focalLength) {
	if (this->focalLength != focalLength) {
		this->focalLength = focalLength;
	}
}
void ComponentProperties::setGain(double gain) {
	if (this->gain != gain) {
		this->gain = gain;
	}
}
void ComponentProperties::setxPixelSize(double xPixelSize) {
	if (this->xPixelSize != xPixelSize) {
		this->xPixelSize = xPixelSize;
	}
}
void ComponentProperties::setyPixelSize(double yPixelSize) {
	if (this->yPixelSize != yPixelSize) {
		this->yPixelSize = yPixelSize;
	}
}
void ComponentProperties::setxStart(long xStart) {
	if (this->xStart != xStart) {
		this->xStart = xStart;
	}
}
void ComponentProperties::setxEnd(long xEnd) {
	if (this->xEnd != xEnd) {
		this->xEnd = xEnd;
	}
}
void ComponentProperties::setyStart(long yStart) {
	if (this->yStart != yStart) {
		this->yStart = yStart;
	}
}
void ComponentProperties::setyEnd(long yEnd) {
	if (this->yEnd != yEnd) {
		this->yEnd = yEnd;
	}
}

