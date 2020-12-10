#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string str);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		void vaulthunter_dot_exe(std::string const &target);

		FragTrap &operator=(FragTrap const &rhs);

	private:
};

#endif
