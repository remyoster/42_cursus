#ifndef NINJATRAP_H
#define NINJATRAP_H

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{

	public:
		NinjaTrap(void);
		NinjaTrap(std::string str);
		NinjaTrap(NinjaTrap const &src);
		~NinjaTrap(void);

		NinjaTrap &operator=(NinjaTrap const &rhs);

		void ninjaShoebox(ClapTrap const &rhs);
		void ninjaShoebox(ScavTrap const &rhs);
		void ninjaShoebox(FragTrap const &rhs);
		void ninjaShoebox(NinjaTrap const &rhs);

	protected:

	private:
};

#endif
