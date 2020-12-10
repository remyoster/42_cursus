#include <iostream>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap() {
	this->_name = "NinjaTrap";
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorReduction = 3;
	std::cout << this->_name;
	std::cout << " : Look out everybody! Things are about to get awesome!";
	std::cout << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(std::string str) : ClapTrap(str) {
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorReduction = 3;
	std::cout << this->_name;
	std::cout << " : Look out everybody! Things are about to get awesome!";
	std::cout << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) {
	*this = src;
	std::cout << this->_name;
	std::cout << " : Look out everybody! Things are about to get awesome!";
	std::cout << std::endl;
	return ;
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << this->_name << " : You can't kill me!" << std::endl;
	return ;
}


NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs)
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

void	NinjaTrap::ninjaShoebox(ClapTrap const & rhs) {
		std::cout << this->_name << " lance ninjaShoebox sur " << rhs.getName();
		std::cout << std::endl << "Hyah!" << std::endl;
	return ;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const & rhs) {
		std::cout << this->_name << " lance ninjaShoebox sur " << rhs.getName();
		std::cout << std::endl << "Heyyah!" << std::endl;
	return ;
}

void	NinjaTrap::ninjaShoebox(FragTrap const & rhs) {
		std::cout << this->_name << " lance ninjaShoebox sur " << rhs.getName();
		std::cout << std::endl << "Bop!" << std::endl;
	return ;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const & rhs) {
		std::cout << this->_name << " lance ninjaShoebox sur " << rhs.getName();
		std::cout << std::endl << "I'm on a roll!" << std::endl;
	return ;
}
