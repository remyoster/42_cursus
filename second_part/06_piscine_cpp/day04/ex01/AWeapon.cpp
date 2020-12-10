#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon(void) {}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name),
	_apcost(apcost), _damage(damage) {}

AWeapon::AWeapon(AWeapon const & src) : _name(src.getName()) {
	*this = src;
	return ;
}

AWeapon::~AWeapon(void) {}

AWeapon &	AWeapon::operator=(AWeapon const & rhs) {
	this->_apcost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return (*this);
}

std::string	const AWeapon::getName() const {
	return (this->_name);
}

int	AWeapon::getAPCost() const {
	return (this->_apcost);
}

int	AWeapon::getDamage() const {
	return (this->_damage);
}

void	AWeapon::setAPCost(int ap) {
	this->_apcost = ap;
}

void	AWeapon::setDamage(int damage) {
	this->_damage = damage;
}