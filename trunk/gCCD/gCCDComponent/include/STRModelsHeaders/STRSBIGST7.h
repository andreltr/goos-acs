#ifndef STR_SBIGST7_H_
#define STR_SBIGST7_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include "STRModelsHeaders/STRBase.h"
#include "csbigcam.h"
#include "csbigimg.h"

class STRSBIGST7: public STRBase {

public:
	STRSBIGST7();
	~STRSBIGST7();
	/*CAMERA FUNCTIONS*/
	void on();
	void off();
	void resetCamera();
	std::string* startExposure();
	void stopExposure();

	void startCooler();
	void stopCooler();

	void update();
	void setComponentProperties(Observable *observable);

	void initialize();
	void shutDown();
	void setObserverName(std::string observerName);
	std::string getObserverName();
	void setFocalLength(double focalLength);
	double getFocalLength();
private:
	OpenDeviceParams odp;
	CSBIGCam* p_Cam;
	CSBIGImg* p_Img;
};

#endif
