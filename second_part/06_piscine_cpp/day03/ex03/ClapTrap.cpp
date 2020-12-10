#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap") {
	std::cout << "Claptrap constructor" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string str) : _name(str) {
	std::cout << "Claptrap constructor" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "Claptrap constructor" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Claptrap destructor" << std::endl;
	return ;
}

void	ClapTrap::rangedAttack(std::string const & target) {

	std::cout << this->_name <<  " attaque " << target;
	std::cout << " à distance, causant " << this->_rangedAttackDamage;
	std::cout << " points de dégâts !" << std::endl;
	return ;
}

void	ClapTrap::meleeAttack(std::string const & target) {
	std::cout << this->_name <<  " attaque " << target;
	std::cout << " au CAC, causant " << this->_meleeAttackDamage;
	std::cout << " points de dégâts !" << std::endl;
	return ;
}


void	ClapTrap::takeDamage(unsigned int amount) {
	int damage = amount - this->_armorReduction;
	if (damage < 0) {
		std::cout << "Zing! Bullet reflection!" << std::endl;
		return ;
	}
	if (this->_hitPoints > 0)
	{
		if ((unsigned int)damage >= this->_hitPoints)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= damage;
		std::cout << this->_name <<  " est touché :";
		std::cout << " il perd " << damage;
		std::cout << " points de vie ! HP restant : " <<  this->_hitPoints << std::endl;
		if (this->_hitPoints == 0)
			std::cout << "I can see through time..." << std::endl;
		else
			std::cout << "Oh my God, I'm leaking! I think I'm leaking! Ahhhh, I'm leaking! There's oil everywhere!" << std::endl;
	}
	else {
		std::cout << this->_name;
		std::cout <<  " ne peut plus prendre de dommages" << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout <<  this->_name;
		std::cout << " est en pleine forme ! Cette action ne fait rien..." << std::endl;
	}
	else
	{
		if (amount + this->_hitPoints >= this->_maxHitPoints)
			this->_hitPoints = this->_maxHitPoints;
		else
			this->_hitPoints += amount;
		std::cout << this->_name <<  " est soigné de : " << amount << std::endl;
		std::cout << "HP restant : " <<  this->_hitPoints << std::endl;
		std::cout << "Good as new, I think. Am I leaking?" << std::endl;
	}
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
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

unsigned int ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}
unsigned int ClapTrap::getMaxHitPoints() const
{
	return this->_maxHitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}
unsigned int ClapTrap::getMaxEnergyPoints() const
{
	return this->_maxEnergyPoints;
}
unsigned int ClapTrap::getLevel() const
{
	return this->_level;
}
std::string ClapTrap::getName() const
{
	return this->_name;
}
unsigned int ClapTrap::getMeleeAttackDamage() const
{
	return this->_meleeAttackDamage;
}
unsigned int ClapTrap::getRangedAttackDamage() const
{
	return this->_rangedAttackDamage;
}
unsigned int ClapTrap::getArmorReduction() const
{
	return this->_armorReduction;
}