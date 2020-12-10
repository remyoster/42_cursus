#ifndef NINJATRAP_H
#define NINJATRAP_H

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
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

	unsigned int getBaseHitPoints() const;
	unsigned int getBaseMaxHitPoints() const;
	unsigned int getBaseEnergyPoints() const;
	unsigned int getBaseMaxEnergyPoints() const;
	unsigned int getBaseMeleeAttackDamage() const;
	unsigned int getBaseRangedAttackDamage() const;
	unsigned int getBaseArmorReduction() const;

	protected:

	private:
};

#endif
