#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src)
	: AWeapon(src.getName(), src.getAPCost(), src.getDamage()) {
	*this = src;
	return ;
}

PlasmaRifle::~PlasmaRifle(void) {}

PlasmaRifle &	PlasmaRifle::operator=(PlasmaRifle const & rhs) {
	if (this != &rhs) {
		this->setAPCost(rhs.getAPCost());
		this->setDamage(rhs.getDamage());
	}
	return (*this);
}

void	PlasmaRifle::attack() const {
	std::cout <<  "* piouuu piouuu piouuu *" << std::endl;
}

