#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap {

public:

	ClapTrap(void);
	ClapTrap(std::string str);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);
	ClapTrap &	operator=(ClapTrap const & rhs);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string getName(void) const;
	unsigned int getLevel(void) const;
	unsigned int getHitPoints() const;
	unsigned int getMaxHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getMaxEnergyPoints() const;
	unsigned int getMeleeAttackDamage() const;
	unsigned int getRangedAttackDamage() const;
	unsigned int getArmorReduction() const;
	

protected:

	std::string _name;
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	unsigned int _meleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorReduction;

private:

};

#endif
