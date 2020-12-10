#include "ZombieEvent.hpp"
#include <cstdlib>

ZombieEvent::ZombieEvent(void) : _type("basic") {}
ZombieEvent::~ZombieEvent(void) {}

void ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	newZombie->setType(this->_type);
	newZombie->announce();
	return (newZombie);
}

Zombie *ZombieEvent::randomChump()
{
	return (this->newZombie(this->randomNameGen(8)));
}

std::string ZombieEvent::randomNameGen(size_t len)
{
	static const char chars[] = 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	std::string s(len, 'a');
	for (size_t i = 0; i < len; ++i)
		s[i] = chars[std::rand() % 63];
	return (s);
}