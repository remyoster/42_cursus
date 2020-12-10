#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {

public:

	Zombie(std::string name);
	~Zombie(void);

	std::string	name;
	std::string type;

	void advert(void) const;
	void announce(void) const;
	void setType(std::string type);
};

#endif
