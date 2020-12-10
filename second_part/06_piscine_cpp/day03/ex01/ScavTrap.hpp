#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>

class ScavTrap {

public:

	ScavTrap(void);
	ScavTrap(std::string str);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(void);
	std::string getName(void) const;
	unsigned int getLevel(void) const;
	unsigned int getHitPoints() const;
	unsigned int getMaxHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getMaxEnergyPoints() const;
	unsigned int getMeleeAttackDamage() const;
	unsigned int getRangedAttackDamage() const;
	unsigned int getArmorReduction() const;

	ScavTrap &	operator=(ScavTrap const & rhs);

private:

	std::string _name;
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	unsigned int _meleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorReduction;

};

#endif
