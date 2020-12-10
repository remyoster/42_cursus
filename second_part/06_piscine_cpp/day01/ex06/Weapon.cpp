#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string str) : _type( new std::string (str)) {
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

std::string const & Weapon::getType() const {
	return (*(this->_type));
}

void	Weapon::setType(std::string str) {
	delete this->_type;
	this->_type = new std::string (str);
}
