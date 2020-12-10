#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(PowerFist const & src)
	: AWeapon(src.getName(), src.getAPCost(), src.getDamage()) {
	*this = src;
	return ;
}

PowerFist::~PowerFist(void) {}

PowerFist &	PowerFist::operator=(PowerFist const & rhs) {
	if (this != &rhs) {
		this->setAPCost(rhs.getAPCost());
		this->setDamage(rhs.getDamage());
	}
	return (*this);
}

void	PowerFist::attack() const {
	std::cout <<  "* pschhh... SBAM ! *" << std::endl;
}
