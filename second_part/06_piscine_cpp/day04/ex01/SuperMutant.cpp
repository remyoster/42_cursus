#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Break everything !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src) : Enemy(src.getHP(), src.getType()) {
	*this = src;
}

SuperMutant::~SuperMutant(void) {
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant &	SuperMutant::operator=(SuperMutant const & rhs) {
	if (this != &rhs)
		this->setHP(rhs.getHP());
	return (*this);
}

void	SuperMutant::takeDamage(int d) {
	d -= 3;
	if (d > 0) {
		this->setHP(this->getHP() - d);
	}
}
