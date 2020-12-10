#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & src) : Enemy(src.getHP(), src.getType()) {
	*this = src;
}

RadScorpion::~RadScorpion(void) {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion &	RadScorpion::operator=(RadScorpion const & rhs) {
	if (this != &rhs)
		this->setHP(rhs.getHP());
	return (*this);
}
