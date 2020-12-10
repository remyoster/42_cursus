#include <iostream>
#include "FragTrap.hpp"
#include <cstdlib>

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorReduction = 5;
	std::cout << this->_name;
	std::cout << " : I am the best robot. Yeah, yeah, yeah, I am the best robot.";
	std::cout << std::endl;
	return;
}

FragTrap::FragTrap(std::string str) : ClapTrap(str)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorReduction = 5;
	std::cout << this->_name;
	std::cout << " : I am the best robot. Yeah, yeah, yeah, I am the best robot.";
	std::cout << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src)
{
	*this = src;
	std::cout << this->_name;
	std::cout << " : I am the best robot. Yeah, yeah, yeah, I am the best robot.";
	std::cout << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->_name << " : I can see... the code" << std::endl;
	return;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	static const std::string attacks[5] = {
		"(unintelligible snarling)",
		"Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!",
		"For you...I commit...seddoku...",
		"You can call me Gundalf!",
		"Grenade confetti!"
	};
	size_t idx = std::rand() % 4;
	if (this->_energyPoints >= 25)
	{
		this->_energyPoints -= 25;
		std::cout << this->_name << " : This time it'll be awesome, I promise!";
		std::cout << std::endl << attacks[idx];
		std::cout << " on : " << target << std::endl;
	}
	else
		std::cout << this->_name << " : Dangit, I'm out!" << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
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
