#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{

public:
	Character(std::string const &name);
	Character(Character const &src);
	~Character(void);

	void recoverAP();
	void equip(AWeapon *);
	void attack(Enemy *);

	std::string const	getName() const;
	int					getApPoints() const;
	AWeapon				*getWeapon() const;

	Character 			&operator=(Character const &rhs);

private:
	Character(void);
	std::string const	_name;
	int					_ap;
	AWeapon				*_weapon;
};

std::ostream &operator<<(std::ostream &o, Character const &i);

#endif
