#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name), type("basic") {
	return ;
}

Zombie::~Zombie(void) {
	return;
}

void	Zombie::advert(void) const {
	std::cout << "<" << this->name << " (" << this->type;
	std::cout << ")> Braiiiiiinnnnssss...." << std::endl;
}

void	Zombie::announce(void) const {
	this->advert();
	return ;
}

void	Zombie::setType(std::string type) {
	this->type = type;
	return;
}