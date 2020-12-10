#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <cstdlib>
#include <ctime>

int	main(void) {
	std::srand(std::time(NULL));
	std::cout << "Constructors :" << std::endl;

	FragTrap robot1;
	FragTrap robot2("42Trap");
	FragTrap robot3(robot1);

	ScavTrap robot4;
	ScavTrap robot5("42SCAV");
	ScavTrap robot6(robot4);

	ClapTrap robot7;

	NinjaTrap robot8("42NINJAAA");
	NinjaTrap robot9;

	SuperTrap robot10;
	SuperTrap robot11("42SUPERTRAP");
	SuperTrap robot12(robot10);


	std::cout << std::endl << "Attack/damage functions :" << std::endl;
/*
	robot1.rangedAttack(robot2.getName());
	robot2.takeDamage(robot1.getRangedAttackDamage());
	robot1.meleeAttack(robot2.getName());
	robot2.takeDamage(robot1.getMeleeAttackDamage());
	robot2.takeDamage(0);
	robot2.takeDamage(8000);
	robot2.takeDamage(8000);

	robot4.rangedAttack(robot5.getName());
	robot5.takeDamage(robot4.getRangedAttackDamage());
	robot4.meleeAttack(robot5.getName());
	robot5.takeDamage(robot4.getMeleeAttackDamage());
	robot5.takeDamage(0);
	robot5.takeDamage(8000);
	robot5.takeDamage(8000);

	robot8.rangedAttack(robot9.getName());
	robot9.takeDamage(robot8.getRangedAttackDamage());
	robot8.meleeAttack(robot9.getName());
	robot9.takeDamage(robot8.getMeleeAttackDamage());
	robot9.takeDamage(0);
	robot9.takeDamage(8000);
	robot9.takeDamage(8000);
*/
	robot10.rangedAttack(robot11.getName());
	robot11.takeDamage(robot10.getRangedAttackDamage());
	robot10.meleeAttack(robot11.getName());
	robot11.takeDamage(robot10.getMeleeAttackDamage());
	robot11.takeDamage(0);
	robot11.takeDamage(8000);
	robot11.takeDamage(8000);

	std::cout << std::endl << "Repair functions :" << std::endl;

/*
	robot2.beRepaired(50);
	robot2.beRepaired(50);
	robot2.beRepaired(50);

	robot5.beRepaired(50);
	robot5.beRepaired(50);
	robot5.beRepaired(50);

	robot9.beRepaired(50);
	robot9.beRepaired(50);
	robot9.beRepaired(50);
*/
	robot11.beRepaired(50);
	robot11.beRepaired(50);
	robot11.beRepaired(50);


	std::cout << std::endl << "VAULTHUNTER.EXE functions :" << std::endl;
/*
	robot2.vaulthunter_dot_exe(robot1.getName());
	robot2.vaulthunter_dot_exe(robot4.getName());
	robot2.vaulthunter_dot_exe(robot3.getName());
	robot2.vaulthunter_dot_exe(robot8.getName());
	robot2.vaulthunter_dot_exe(robot3.getName());
*/
	robot11.vaulthunter_dot_exe(robot3.getName());
	robot11.vaulthunter_dot_exe(robot8.getName());
	robot11.vaulthunter_dot_exe(robot3.getName());

/*
	std::cout << std::endl << "chalengeNewComer functions :" << std::endl;

	robot5.challengeNewcomer();
	robot5.challengeNewcomer();
	robot5.challengeNewcomer();
*/

	std::cout << std::endl << "ninjaShoebox functions :" << std::endl;
/*
	robot8.ninjaShoebox(robot7);
	robot8.ninjaShoebox(robot6);
	robot8.ninjaShoebox(robot1);
	robot8.ninjaShoebox(robot9);
*/
	robot11.ninjaShoebox(robot7);
	robot11.ninjaShoebox(robot6);
	robot11.ninjaShoebox(robot1);
	robot11.ninjaShoebox(robot9);

	robot2 = robot1;
	robot5 = robot4;
	robot8 = robot9;
	robot10 = robot11;

	std::cout << std::endl << "Destructors :" << std::endl;
	return (0);
}
