#ifndef GOBELIN_H
# define GOBELIN_H

# include <iostream>
# include "Victim.hpp"

class Gobelin : public Victim {

public:

	Gobelin(std::string name);
	Gobelin(Gobelin const & src);
	~Gobelin(void);
	Gobelin &	operator=(Gobelin const & rhs);

	virtual void	getPolymorphed(void) const;

private:
	Gobelin(void);


};

std::ostream &	operator<<(std::ostream & o, Gobelin const & i);

#endif
