#include <iostream>
#include "Character.hpp"

Character::Character(void) {}

Character::Character(std::string const & name) : _name(name), _ap(40), _weapon(NULL) {
	return ;
}

Character::Character(Character const & src) : _name(src.getName()) {
	*this = src;
	return ;
}

Character::~Character(void) {}

Character &	Character::operator=(Character const & rhs) {
	if (this != &rhs) {
		this->_ap = rhs.getApPoints();
		this->_weapon = rhs.getWeapon();
	}
	return (*this);
}

std::string const Character::getName() const {
	return (this->_name);
}

int	Character::getApPoints() const {
	return (this->_ap);
}

AWeapon *Character::getWeapon() const {
	return (this->_weapon);
}

void	Character::recoverAP() {
	if (this->_ap < 40) {
		this->_ap += 10;
		this->_ap > 40 ? this->_ap = 40 : this->_ap;
	}
}

void	Character::attack(Enemy *enemy) {
	if (this->_weapon && this->_ap >= this->_weapon->getAPCost() && enemy) {
		std::cout << this->_name << " attack " << enemy->getType();
		std::cout << " with a " << this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		this->_ap -= this->_weapon->getAPCost();
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() <= 0) {
			delete enemy;
			enemy = NULL;
		}
	}
}

void	Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

std::ostream &	operator<<(std::ostream & o, Character const & i) {
	AWeapon *tmp;

	tmp = i.getWeapon();
	o << i.getName() << " has " << i.getApPoints() << " AP and ";
	if (tmp)
		o << "carries a " << tmp->getName();
	else
		o << "is unarmed";
	o << std::endl;
	return (o);
}

