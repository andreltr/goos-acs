#include "Observable.h"
#include "Observer.h"

Observer::Observer()
{

}

Observer::~Observer()
{

}

void Observer::setObservable(Observable *observable) {
	std::cout << "Observer::setObservable(...)" << std::endl;
	this->observable = observable;

	this->observable->addObserver(this);
}
