#ifndef PEON_H
# define PEON_H

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim {

public:

	Peon(std::string name);
	Peon(Peon const & src);
	~Peon(void);
	Peon &	operator=(Peon const & rhs);

	virtual void	getPolymorphed(void) const;

private:
	Peon(void);


};

std::ostream &	operator<<(std::ostream & o, Peon const & i);

#endif
