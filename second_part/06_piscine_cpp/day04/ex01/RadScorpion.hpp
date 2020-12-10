#ifndef RADSCORPION_H
# define RADSCORPION_H

# include <iostream>
# include "Enemy.hpp"

class RadScorpion : public Enemy {

public:

	RadScorpion(void);
	~RadScorpion(void);

	RadScorpion &	operator=(RadScorpion const & rhs);

private:
	RadScorpion(RadScorpion const & src);

};

#endif
