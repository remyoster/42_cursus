#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _xp(0), _type(type) {
}

AMateria::AMateria(AMateria const & src) : _xp(src.getXP()), _type(src.getType()) {}

AMateria::~AMateria(void) {}

AMateria &	AMateria::operator=(AMateria const & rhs) {

	if (this != &rhs) {
		this->_xp = rhs.getXP();
	}
	return (*this);
}

unsigned int AMateria::getXP() const {
	return (this->_xp);
}

std::string const & AMateria::getType() const {
	return (this->_type);
}

void	AMateria::setXp(int xp) {
	this->_xp += xp;
}