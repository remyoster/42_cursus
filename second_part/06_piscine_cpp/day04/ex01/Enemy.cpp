#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(void) {}

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type) {}

Enemy::Enemy(Enemy const & src) : _type(src.getType()) {
	*this = src;
	return ;
}

Enemy::~Enemy(void) {}

Enemy &	Enemy::operator=(Enemy const & rhs) {
	if (this != &rhs) {
		this->_hp = rhs.getHP();
	}
	return (*this);
}

std::string const Enemy::getType() const {
	return (this->_type);
}

int	Enemy::getHP() const {
	return (this->_hp);
}

void	Enemy::takeDamage(int d) {
	if (d > 0) {
		this->_hp -= d;
	}
}

void	Enemy::setHP(int hp) {
	this->_hp = hp;
}
