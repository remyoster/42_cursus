#include "Human.hpp"
#include "Brain.hpp"

Human::Human(void) {}

Human::~Human(void) {}

std::string Human::identify(void) const {
	return (this->_brain.identify());
}

Brain	Human::getBrain(void) const {
	return (this->_brain);
}