#include <iostream>
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) {
	this->_name = "SuperTrap";
	this->_hitPoints = this->getBaseHitPoints();
	this->_maxHitPoints = this->getBaseMaxHitPoints();
	this->_energyPoints = this->getBaseEnergyPoints();
	this->_maxEnergyPoints = this->getBaseMaxEnergyPoints();
	this->_level = 1;
	this->_meleeAttackDamage = this->getBaseMeleeAttackDamage();
	this->_rangedAttackDamage = this->getBaseRangedAttackDamage();
	this->_armorReduction = this->getBaseArmorReduction();
	std::cout << this->_name;
	std::cout << " : Step right up, to the Bulletnator 9000!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(std::string str) {
	this->_name = str;
	this->_hitPoints = this->getBaseHitPoints();
	this->_maxHitPoints = this->getBaseMaxHitPoints();
	this->_energyPoints = this->getBaseEnergyPoints();
	this->_maxEnergyPoints = this->getBaseMaxEnergyPoints();
	this->_level = 1;
	this->_meleeAttackDamage = this->getBaseMeleeAttackDamage();
	this->_rangedAttackDamage = this->getBaseRangedAttackDamage();
	this->_armorReduction = this->getBaseArmorReduction();
	std::cout << this->_name;
	std::cout << " : Step right up, to the Bulletnator 9000!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(SuperTrap const & src) {
	*this = src;
	std::cout << this->_name;
	std::cout << " : Step right up, to the Bulletnator 9000!" << std::endl;
	return ;
}

SuperTrap::~SuperTrap(void) {
	std::cout << this->_name;
	std::cout << " : I bet your mom could do better!" << std::endl;
	return ;
}

SuperTrap &	SuperTrap::operator=(SuperTrap const & rhs) {
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
