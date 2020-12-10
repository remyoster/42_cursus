#ifndef POWERFIST_H
# define POWERFIST_H

# include <iostream>
# include "AWeapon.hpp"

class PowerFist : public AWeapon{

public:
	PowerFist(void);
	~PowerFist(void);

	PowerFist &	operator=(PowerFist const & rhs);
	
	virtual void attack() const;

private:
	PowerFist(PowerFist const & src);

};

#endif
