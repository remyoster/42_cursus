#ifndef AWEAPON_H
# define AWEAPON_H

# include <iostream>

class AWeapon {

public:

	AWeapon(std::string const & name, int apcost, int damage);
	virtual ~AWeapon(void);
	AWeapon &	operator=(AWeapon const & rhs);

	std::string	const getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;

	void	setAPCost(int ap);
	void	setDamage(int damage);


private:
	AWeapon(void);
	AWeapon(AWeapon const & src);
	std::string const	_name;
	int					_apcost;
	int					_damage;

};

#endif
