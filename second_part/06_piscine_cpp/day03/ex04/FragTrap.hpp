#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string str);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		void vaulthunter_dot_exe(std::string const &target);

		FragTrap &operator=(FragTrap const &rhs);

	unsigned int getBaseHitPoints() const;
	unsigned int getBaseMaxHitPoints() const;
	unsigned int getBaseEnergyPoints() const;
	unsigned int getBaseMaxEnergyPoints() const;
	unsigned int getBaseMeleeAttackDamage() const;
	unsigned int getBaseRangedAttackDamage() const;
	unsigned int getBaseArmorReduction() const;

	private:
};

#endif
