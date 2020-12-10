#ifndef PLASMARIFLE_H
# define PLASMARIFLE_H

# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:
	PlasmaRifle(void);
	~PlasmaRifle(void);

	PlasmaRifle &	operator=(PlasmaRifle const & rhs);

	virtual void attack() const;

private:
	PlasmaRifle(PlasmaRifle const & src);

};

#endif
