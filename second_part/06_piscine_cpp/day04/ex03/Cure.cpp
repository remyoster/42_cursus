#include <iostream>
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(Cure const & src) : AMateria("cure") {
	*this = src;
}

Cure::~Cure(void) {}

AMateria * Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target) {
	this->setXp(10);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure &	Cure::operator=(Cure const & rhs) {
	if (this != &rhs) {
		this->setXp(rhs.getXP() - this->getXP());
	}
	return (*this);
}
