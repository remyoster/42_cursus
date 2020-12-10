#include "ZombieEvent.hpp"
#include <ctime>

int	main(void) {
	std::srand(std::time(NULL));
	ZombieEvent instance;
	Zombie *zombie;
	Zombie stack("Test");

	zombie = instance.newZombie("Zombie1");
	instance.setZombieType("fire");
	delete zombie;
	zombie = instance.newZombie("Zombie2");
	delete zombie;
	instance.setZombieType("random");
	zombie = instance.randomChump();
	delete zombie;
	zombie = instance.randomChump();
	delete zombie;
	stack.advert();

	return (0);
}