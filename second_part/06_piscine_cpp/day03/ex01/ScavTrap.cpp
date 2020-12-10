#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _name("ScavTrap"), _hitPoints(100),
						   _maxHitPoints(100), _energyPoints(50), _maxEnergyPoints(50), _level(1), _meleeAttackDamage(20),
						   _rangedAttackDamage(15), _armorReduction(3)
{
	std::cout << this->_name;
	std::cout << " : Hey everybody! Check out my package!" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string str) : _name(str), _hitPoints(100),
									  _maxHitPoints(100), _energyPoints(50), _maxEnergyPoints(50), _level(1), _meleeAttackDamage(20),
									  _rangedAttackDamage(15), _armorReduction(3)
{
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

void ScavTrap::rangedAttack(std::string const &target)
{

	std::cout << this->_name << " attaque " << target;
	std::cout << " à distance, causant " << this->_rangedAttackDamage;
	std::cout << " points de dégâts !" << std::endl;
	return;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << this->_name << " attaque " << target;
	std::cout << " au CAC, causant " << this->_meleeAttackDamage;
	std::cout << " points de dégâts !" << std::endl;
	return;
}

void ScavTrap::takeDamage(unsigned int amount)
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
			std::cout << "Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
		else
			std::cout << "You got me!" << std::endl;
	}
	else
	{
		std::cout << this->_name;
		std::cout << " ne peut plus prendre de dommages" << std::endl;
	}
	return;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout << this->_name;
		std::cout << " est en pleine forme ! Cette action ne fait rien..." << std::endl;
	}
	else
	{
		if (amount + this->_hitPoints >= this->_maxHitPoints)
			this->_hitPoints = this->_maxHitPoints;
		else
			this->_hitPoints += amount;
		std::cout << this->_name << " est soigné de : " << amount << std::endl;
		std::cout << "HP restant : " << this->_hitPoints << std::endl;
		std::cout << "Health over here!" << std::endl;
	}
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

unsigned int ScavTrap::getHitPoints() const
{
	return this->_hitPoints;
}
unsigned int ScavTrap::getMaxHitPoints() const
{
	return this->_maxHitPoints;
}
unsigned int ScavTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}
unsigned int ScavTrap::getMaxEnergyPoints() const
{
	return this->_maxEnergyPoints;
}
unsigned int ScavTrap::getLevel() const
{
	return this->_level;
}
std::string ScavTrap::getName() const
{
	return this->_name;
}
unsigned int ScavTrap::getMeleeAttackDamage() const
{
	return this->_meleeAttackDamage;
}
unsigned int ScavTrap::getRangedAttackDamage() const
{
	return this->_rangedAttackDamage;
}
unsigned int ScavTrap::getArmorReduction() const
{
	return this->_armorReduction;
}
