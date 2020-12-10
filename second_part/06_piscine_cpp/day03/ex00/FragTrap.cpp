#include <iostream>
#include "FragTrap.hpp"
#include <cstdlib>

FragTrap::FragTrap(void) : _name("FragTrap"), _hitPoints(100),
						   _maxHitPoints(100), _energyPoints(100),
						   _maxEnergyPoints(100), _level(1),
						   _meleeAttackDamage(30),
						   _rangedAttackDamage(20), _armorReduction(5)
{
	std::cout << "I am the best robot. Yeah, yeah, yeah, I am the best robot." << std::endl;
	return;
}

FragTrap::FragTrap(std::string str) : _name(str), _hitPoints(100),
									  _maxHitPoints(100), _energyPoints(100),
									  _maxEnergyPoints(100), _level(1),
									  _meleeAttackDamage(30),
									  _rangedAttackDamage(20), _armorReduction(5)
{
	std::cout << "I am the best robot. Yeah, yeah, yeah, I am the best robot." << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "I am the best robot. Yeah, yeah, yeah, I am the best robot." << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->_name << " : I can see... the code" << std::endl;
	return;
}

void FragTrap::rangedAttack(std::string const &target)
{

	std::cout << this->_name << " attaque " << target;
	std::cout << " à distance, causant " << this->_rangedAttackDamage;
	std::cout << " points de dégâts !" << std::endl;
	return;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << this->_name << " attaque " << target;
	std::cout << " au CAC, causant " << this->_meleeAttackDamage;
	std::cout << " points de dégâts !" << std::endl;
	return;
}

void FragTrap::takeDamage(unsigned int amount)
{
	int damage = amount - this->_armorReduction;

	if (damage < 0)
	{
		std::cout << "Zing! Bullet reflection!" << std::endl;
		return;
	}
	if (this->_hitPoints > 0)
	{
		if ((unsigned int)damage >= this->_hitPoints)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= damage;
		std::cout << this->_name << " est touché :";
		std::cout << " il perd " << damage;
		std::cout << " points de vie ! HP restant : " << this->_hitPoints << std::endl;
		if (this->_hitPoints == 0)
			std::cout << "I can see through time..." << std::endl;
		else
			std::cout << "Oh my God, I'm leaking! I think I'm leaking! Ahhhh, I'm leaking! There's oil everywhere!" << std::endl;
	}
	else
	{
		std::cout << this->_name;
		std::cout << " ne peut plus prendre de dommages" << std::endl;
	}
	return;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout << this->_name;
		std::cout << " est en pleine forme ! Cette action ne fait rien..." << std::endl;
		std::cout << "Yeah? Well, hmph!" << std::endl;
	}
	else
	{
		if (amount + this->_hitPoints >= this->_maxHitPoints)
			this->_hitPoints = this->_maxHitPoints;
		else
			this->_hitPoints += amount;
		std::cout << this->_name << " est soigné de : " << amount << std::endl;
		std::cout << "HP restant : " << this->_hitPoints << std::endl;
		std::cout << "Good as new, I think. Am I leaking?" << std::endl;
	}
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

unsigned int FragTrap::getHitPoints() const
{
	return this->_hitPoints;
}
unsigned int FragTrap::getMaxHitPoints() const
{
	return this->_maxHitPoints;
}
unsigned int FragTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}
unsigned int FragTrap::getMaxEnergyPoints() const
{
	return this->_maxEnergyPoints;
}
unsigned int FragTrap::getLevel() const
{
	return this->_level;
}
std::string FragTrap::getName() const
{
	return this->_name;
}
unsigned int FragTrap::getMeleeAttackDamage() const
{
	return this->_meleeAttackDamage;
}
unsigned int FragTrap::getRangedAttackDamage() const
{
	return this->_rangedAttackDamage;
}
unsigned int FragTrap::getArmorReduction() const
{
	return this->_armorReduction;
}
