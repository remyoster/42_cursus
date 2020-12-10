#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H

# include <iostream>
# include "Zombie.hpp"

class ZombieEvent {

public:

	ZombieEvent(void);
	~ZombieEvent(void);

	void setZombieType(std::string type);
	Zombie *newZombie(std::string name);
	Zombie *randomChump();


private:

	std::string randomNameGen(size_t len);
	std::string _type;
};

#endif
