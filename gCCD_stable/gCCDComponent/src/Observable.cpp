#include "Observable.h"
#include "Observer.h"

Observable::Observable() {
	counter = 0;
}

Observable::~Observable() {

}

void Observable::addObserver(Observer *obs) {
	std::cout << "Observable::addObserver(...) " << std::endl;
	observers.push_back(obs);
	std::cout << "Observable::addObserver(...) observer number " << counter
			<< std::endl;
	counter++;
}

void Observable::removeObserver(int position) {
	std::cout << "Observable::removeObserver(...)" << std::endl;
	observers.erase(observers.begin() + position - 1);
}

void Observable::notifyObservers() {
	std::cout << "Observable::notifyObservers()" << std::endl;
	for (unsigned int i = 0; i < observers.size(); i++) {
		std::cout << "Observable::notifyObservers() observer number " << i
				<< std::endl;
		observers[i]->update();
	}
}
