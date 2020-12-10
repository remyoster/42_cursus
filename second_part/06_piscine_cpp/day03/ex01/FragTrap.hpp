#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>

class FragTrap
{

public:
	FragTrap(void);
	FragTrap(std::string str);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	void rangedAttack(std::string const &target);
	void meleeAttack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const &target);

	std::string getName(void) const;
	unsigned int getLevel(void) const;
	unsigned int getHitPoints() const;
	unsigned int getMaxHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getMaxEnergyPoints() const;
	unsigned int getMeleeAttackDamage() const;
	unsigned int getRangedAttackDamage() const;
	unsigned int getArmorReduction() const;

	FragTrap &operator=(FragTrap const &rhs);

private:

	std::string _name;
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	unsigned int _meleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorReduction;
};

#endif
