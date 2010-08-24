#ifndef STRBASE_H_
#define STRBASE_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <iostream>
#include "ComponentProperties.h"
#include "Observer.h"

/**
 * Abstract base class for the Strategy Pattern
 */

class STRBase: public Observer {
protected:
	std::string* filesQueue;
	float currentTemp;
	ComponentProperties* componentProperties;
public:
	STRBase() {
		filesQueue = 0;
		componentProperties = 0;
	}

	virtual ~STRBase() {
		if (filesQueue != 0) {
			delete[] filesQueue;
		}
	}

	virtual void on() = 0;
	virtual void off() = 0;
	virtual void resetCamera() = 0;

	virtual std::string* startExposure() = 0;
	virtual void stopExposure() = 0;

	virtual void startCooler() = 0;
	virtual void stopCooler() = 0;

	//
	float getCurrentCCDTemperatue() {
		return currentTemp;
	}

	virtual void update()=0;

	void setComponentProperties(Observable* observable) {
		componentProperties = (ComponentProperties*) observable;
		setObservable(componentProperties);
	}
};
#endif
