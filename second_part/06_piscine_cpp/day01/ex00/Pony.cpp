#include "Pony.hpp"
#include <iostream>

Pony::Pony(char const *name) : name(name){
	Pony::_nbInst += 1;
	return;
}

Pony::~Pony(void) {
	Pony::_nbInst -= 1;
	return;
}

void	Pony::snort(void) const {
	std::cout << this->name << " -> Huhuhuhuhhuuuuuuuuuuuu" << std::endl;
}
void	Pony::walk(void) const {
	std::cout << this->name << " -> is walking..." << std::endl;
}
void	Pony::stop(void) const {
	this->snort();
	std::cout << this->name << " has stoped." << std::endl;
}

int		Pony::getNbInst(void) {
	return Pony::_nbInst;
}

int		Pony::_nbInst = 0;