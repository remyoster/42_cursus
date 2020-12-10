#include "FragTrap.hpp"
#include <cstdlib>
#include <ctime>

int	main(void) {
	std::srand(std::time(NULL));
	std::cout << "Constructors :" << std::endl;

	FragTrap robot1;
	FragTrap robot2("42Trap");
	FragTrap robot3(robot1);

	std::cout << std::endl << "Attack/damage functions :" << std::endl;

	robot1.rangedAttack(robot2.getName());
	robot2.takeDamage(robot1.getRangedAttackDamage());
	robot1.meleeAttack(robot2.getName());
	robot2.takeDamage(robot1.getMeleeAttackDamage());
	robot2.takeDamage(0);
	robot2.takeDamage(8000);
	robot2.takeDamage(8000);

	std::cout << std::endl << "Repair functions :" << std::endl;

	robot2.beRepaired(50);
	robot2.beRepaired(50);
	robot2.beRepaired(50);

	std::cout << std::endl << "VAULTHUNTER.EXE functions :" << std::endl;

	robot2.vaulthunter_dot_exe(robot1.getName());
	robot2.vaulthunter_dot_exe(robot3.getName());
	robot2.vaulthunter_dot_exe(robot1.getName());
	robot2.vaulthunter_dot_exe(robot3.getName());
	robot2.vaulthunter_dot_exe(robot3.getName());

	robot2 = robot1;

	std::cout << std::endl << "Destructors :" << std::endl;
	return (0);
}
