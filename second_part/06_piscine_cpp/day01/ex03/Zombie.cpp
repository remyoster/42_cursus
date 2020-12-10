#include "Zombie.hpp"
#include <cstdlib>

Zombie::Zombie() {
	this->name = this->randomNameGen(8);
	this->type = "random";
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

std::string Zombie::randomNameGen(size_t len=8)
{
	static const char chars[] = 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	std::string s(len, 'a');
	for (size_t i = 0; i < len; ++i)
		s[i] = chars[rand() % 63];
	return (s);
}