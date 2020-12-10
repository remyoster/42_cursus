#include <iostream>
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(Ice const & src) : AMateria("ice") {
	*this = src;
}

Ice::~Ice(void) {}

AMateria * Ice::clone() const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target) {
	this->setXp(10);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice &	Ice::operator=(Ice const & rhs) {
	if (this != &rhs)
		this->setXp(rhs.getXP() - this->getXP());
	return (*this);
}
