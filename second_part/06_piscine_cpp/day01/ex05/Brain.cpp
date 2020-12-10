#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain(void) {
	std::stringstream s;
	s << (void const *)this;
	this->_addr = s.str();
}

Brain::~Brain(void) {}

std::string Brain::identify(void) const {
	return (this->_addr);
}