#ifndef SUPERTRAP_H
#define SUPERTRAP_H

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

class SuperTrap : public FragTrap, public NinjaTrap
{
	public:
		SuperTrap(void);
		SuperTrap(std::string str);
		SuperTrap(SuperTrap const &src);
		~SuperTrap(void);

		SuperTrap &operator=(SuperTrap const &rhs);

		using FragTrap::rangedAttack;
		using NinjaTrap::meleeAttack;
		
		using FragTrap::getBaseHitPoints;
		using FragTrap::getBaseMaxHitPoints;
		using NinjaTrap::getBaseEnergyPoints;
		using NinjaTrap::getBaseMaxEnergyPoints;
		using NinjaTrap::getBaseMeleeAttackDamage;
		using FragTrap::getBaseRangedAttackDamage;
		using FragTrap::getBaseArmorReduction;

	private:
};

#endif
