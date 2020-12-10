#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string str);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);

		void challengeNewcomer(void);

		ScavTrap &operator=(ScavTrap const &rhs);

	private:
};

#endif
