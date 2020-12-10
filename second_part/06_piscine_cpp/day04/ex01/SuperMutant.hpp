#ifndef SUPERMUTANT_H
# define SUPERMUTANT_H

# include <iostream>
# include "Enemy.hpp"

class SuperMutant : public Enemy {

public:
	SuperMutant(void);
	~SuperMutant(void);

	SuperMutant &	operator=(SuperMutant const & rhs);
	
	virtual void takeDamage(int);

private:
	SuperMutant(SuperMutant const & src);

};

#endif
