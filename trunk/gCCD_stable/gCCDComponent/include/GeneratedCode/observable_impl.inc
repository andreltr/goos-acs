ComponentProperties::ComponentProperties() {
}
ComponentProperties::~ComponentProperties() {
}
double ComponentProperties::getactualAirTemperature() {
	return actualAirTemperature;
}
double ComponentProperties::getactualCCDTemperature() {
	return actualCCDTemperature;
}
double ComponentProperties::getcommandedCCDTemperature() {
	return commandedCCDTemperature;
}
std::string ComponentProperties::getcameraName() {
	return cameraName;
}
long ComponentProperties::getcameraModel() {
	return cameraModel;
}
std::string ComponentProperties::getfilterName() {
	return filterName;
}
std::string ComponentProperties::getobjectName() {
	return objectName;
}
std::string ComponentProperties::getobserverName() {
	return observerName;
}
double ComponentProperties::getexposureTime() {
	return exposureTime;
}
long ComponentProperties::getacquisitionMode() {
	return acquisitionMode;
}
long ComponentProperties::getnumberOfAcquisitions() {
	return numberOfAcquisitions;
}
double ComponentProperties::getfocalLength() {
	return focalLength;
}
double ComponentProperties::getgain() {
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
std::string ComponentProperties::gettelescopeName() {
	return telescopeName;
}
void ComponentProperties::setactualAirTemperature(double actualAirTemperature) {
	if (this->actualAirTemperature != actualAirTemperature) {
		this->actualAirTemperature = actualAirTemperature;
	}
}
void ComponentProperties::setactualCCDTemperature(double actualCCDTemperature) {
	if (this->actualCCDTemperature != actualCCDTemperature) {
		this->actualCCDTemperature = actualCCDTemperature;
	}
}
void ComponentProperties::setcommandedCCDTemperature(double commandedCCDTemperature) {
	if (this->commandedCCDTemperature != commandedCCDTemperature) {
		this->commandedCCDTemperature = commandedCCDTemperature;
	}
}
void ComponentProperties::setcameraName(std::string cameraName) {
	if (this->cameraName != cameraName) {
		this->cameraName = cameraName;
	}
}
void ComponentProperties::setcameraModel(long cameraModel) {
	if (this->cameraModel != cameraModel) {
		this->cameraModel = cameraModel;
	}
}
void ComponentProperties::setfilterName(std::string filterName) {
	if (this->filterName != filterName) {
		this->filterName = filterName;
	}
}
void ComponentProperties::setobjectName(std::string objectName) {
	if (this->objectName != objectName) {
		this->objectName = objectName;
	}
}
void ComponentProperties::setobserverName(std::string observerName) {
	if (this->observerName != observerName) {
		this->observerName = observerName;
	}
}
void ComponentProperties::setexposureTime(double exposureTime) {
	if (this->exposureTime != exposureTime) {
		this->exposureTime = exposureTime;
	}
}
void ComponentProperties::setacquisitionMode(long acquisitionMode) {
	if (this->acquisitionMode != acquisitionMode) {
		this->acquisitionMode = acquisitionMode;
	}
}
void ComponentProperties::setnumberOfAcquisitions(long numberOfAcquisitions) {
	if (this->numberOfAcquisitions != numberOfAcquisitions) {
		this->numberOfAcquisitions = numberOfAcquisitions;
	}
}
void ComponentProperties::setfocalLength(double focalLength) {
	if (this->focalLength != focalLength) {
		this->focalLength = focalLength;
	}
}
void ComponentProperties::setgain(double gain) {
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
void ComponentProperties::settelescopeName(std::string telescopeName) {
	if (this->telescopeName != telescopeName) {
		this->telescopeName = telescopeName;
	}
}
