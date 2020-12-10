#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_name = "ScavTrap";
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorReduction = 3;
	std::cout << this->_name;
	std::cout << " : Hey everybody! Check out my package!" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string str) : ClapTrap(str) {
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorReduction = 3;
	std::cout << this->_name;
	std::cout << " : Hey everybody! Check out my package!" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	*this = src;
	std::cout << this->_name;
	std::cout << " : Hey everybody! Check out my package!" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->_name;
	std::cout << " : Unce! Unce! I think I lost the beat... but, Unce! Unce!";
	std::cout << std::endl;
	return;
}

void ScavTrap::challengeNewcomer(void)
{
	std::string buff;
	static const std::string attacks[5] = {
		"jump over that cliff",
		"shoot a bullet in your feet",
		"dance with claptrap",
		"kiss a slag on the chick",
		"run naked trough the desert",
	};
	std::cout << this->_name << " : Pick a challenge newbie : " << std::endl;
	for (size_t i = 0; i < 5; i++)
		std::cout << i << " : " << attacks[i] << std::endl;
	std::getline(std::cin, buff);
	if (buff.length() > 1 || (int)buff[0] - 48 > 4)
	{
		std::cout << "Error in index" << std::endl;
		return;
	}
	std::cout << "You " << attacks[(int)buff[0] - 48];
	std::cout << ", and die in horrible circumstances" << std::endl;
	std::cout << this->_name << " : So uh...great weather we're having." << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	this->_hitPoints = rhs.getHitPoints();
	this->_maxHitPoints = rhs.getMaxHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
	this->_level = rhs.getLevel();
	this->_name = rhs.getName();
	this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
	this->_rangedAttackDamage = rhs.getRangedAttackDamage();
	this->_armorReduction = rhs.getArmorReduction();
	return (*this);
}
