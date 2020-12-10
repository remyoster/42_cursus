#include <iostream>
#include "Victim.hpp"

Victim::Victim(void) : _name("Jean") {
	std::cout << "A random victim called " << this->_name;
	std::cout << " just appeared!" << std::endl;
	return ;
}

Victim::Victim(std::string name) : _name(name) {
	std::cout << "A random victim called " << this->_name;
	std::cout << " just appeared!" << std::endl;
	return ;
}

Victim::Victim(Victim const & src) {
	*this = src;
	std::cout << "A random victim called " << this->_name;
	std::cout << " just appeared!" << std::endl;
	return ;
}

Victim::~Victim(void) {
	std::cout << "The victim " << this->_name;
	std::cout << " died for no apparent reasons!" << std::endl;
	return ;
}

Victim &	Victim::operator=(Victim const & rhs) {
	this->_name = rhs.getName();
	return (*this);
}

std::string Victim::getName(void) const {
	return (this->_name);
}

void	Victim::getPolymorphed(void) const {
	std::cout << this->_name << " was just polymorphed in a cute little sheep!" << std::endl;
	return;
}

std::ostream &	operator<<(std::ostream & o, Victim const & i) {
	o << "I'm " << i.getName() << " and I like otters!" << std::endl;
	return (o);
}

