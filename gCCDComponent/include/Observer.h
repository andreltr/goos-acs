#ifndef OBSERVER_H_
#define OBSERVER_H_

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <iostream>

class Observable;

/**
 * Abstract base class for an Observer class
 */
class Observer {
private:
	Observable *observable;
protected:
public:
	Observer();
	virtual ~Observer();
	void setObservable(Observable *observable);
	virtual void update()=0;
};
#endif
