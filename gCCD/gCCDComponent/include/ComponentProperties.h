#ifndef COMPONENT_PROPERTIES_H_
#define COMPONENT_PROPERTIES_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <string>
#include "Observable.h"

class ComponentProperties: public Observable {
private:
	double actualAirTemperature;
	double actualCCDTemperature;
	double commandedCCDTemperature;
	std::string cameraName;
	long cameraModel;
	std::string filterName;
	std::string objectName;
	std::string observerName;
	double exposureTime;
	long acquisitionMode;
	long numberOfAcquisitions;
	double focalLength;
	double gain;
	double xPixelSize;
	double yPixelSize;
	long xStart;
	long xEnd;
	long yStart;
	long yEnd;
protected:
public:
	ComponentProperties();
	~ComponentProperties();

	double getActualAirTemperature();
	double getActualCCDTemperature();
	double getCommandedCCDTemperature();
	std::string getCameraName();
	long getCameraModel();
	std::string getFilterName();
	std::string getObjectName();
	std::string getObserverName();
	double getExposureTime();
	long getAcquisitionMode();
	long getNumberOfAcquisitions();
	double getFocalLength();
	double getGain();
	double getxPixelSize();
	double getyPixelSize();
	long getxStart();
	long getxEnd();
	long getyStart();
	long getyEnd();

	void setActualAirTemperature(double actualAirTemperature);
	void setActualCCDTemperature(double actualCCDTemperature);
	void setCommandedCCDTemperature(double commandedCCDTemperature);
	void setCameraName(std::string cameraName);
	void setCameraModel(long cameraModel);
	void setFilterName(std::string filterName);
	void setObjectName(std::string objectName);
	void setObserverName(std::string observerName);
	void setExposureTime(double exposureTime);
	void setAcquisitionMode(long acquisitionMode);
	void setNumberOfAcquisitions(long numberOfAcquisitions);
	void setFocalLength(double focalLength);
	void setGain(double gain);
	void setxPixelSize(double xPixelSize);
	void setyPixelSize(double yPixelSize);
	void setxStart(long xStart);
	void setxEnd(long xEnd);
	void setyStart(long yStart);
	void setyEnd(long yEnd);
};
#endif
