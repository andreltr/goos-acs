#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <vector>
#include "Observer.h"

/**
 * Abstract base class for an Observable class
 */
class Observable {
private:
	std::vector < class Observer * > observers;
	int counter;
protected:
public:
	Observable();
	~Observable();
	void addObserver(Observer *obs);
	void removeObserver(int position);
	void notifyObservers();
};
#endif
