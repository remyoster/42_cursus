#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

# include "Zombie.hpp"

class ZombieHorde {

public:
	ZombieHorde(size_t n);
	~ZombieHorde(void);

	Zombie *zombies;

	void	announce(void) const;

private:

	size_t _horde_size;
};

#endif
