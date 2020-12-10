#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon {

public:

	Weapon(void);
	Weapon(std::string str);
	~Weapon(void);

	std::string const & getType() const;
	void	setType(std::string str);


private:

	std::string	*_type;

};

#endif
