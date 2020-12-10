#ifndef TACTICALMARINE_H
# define TACTICALMARINE_H

# include <iostream>
# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

public:

	TacticalMarine(void);
	TacticalMarine(TacticalMarine const & src);
	virtual ~TacticalMarine();

	TacticalMarine &	operator=(TacticalMarine const & rhs);
	
	virtual ISpaceMarine *clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;

private:

};

#endif
