#include "ZombieHorde.hpp"
#include <cstdlib>
#include <ctime>

int	main(void) {
	std::srand(std::time(NULL));
	ZombieHorde instance(10);
	instance.announce();
	return (0);
}
