#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(size_t n) : _horde_size(n) {
	this->zombies = new Zombie[n];
}

ZombieHorde::~ZombieHorde(void) {
	delete[] this->zombies;
}

void	ZombieHorde::announce(void) const {
	for (size_t  i = 0; i< this->_horde_size; i++)
		this->zombies[i].announce();
	return ;
}