#include <iostream>
#include "Peon.hpp"

Peon::Peon(void) : Victim("Claude") {
	std::cout << "Zog zog" << std::endl;
}

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog" << std::endl;
}

Peon::Peon(Peon const & src) {
	*this = src;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}

Peon &	Peon::operator=(Peon const & rhs) {
	if (this != &rhs)
		this->_name = rhs.getName();
	return (*this);
}

void	Peon::getPolymorphed(void) const {
	std::cout << this->_name << " was just polymorphed into a pink pony!" << std::endl;
}

std::ostream &	operator<<(std::ostream & o, Peon const & i) {
	o << "I'm " << i.getName() << " and I like otters!" << std::endl;
	return (o);
}

