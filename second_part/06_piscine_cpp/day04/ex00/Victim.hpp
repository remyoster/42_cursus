#ifndef VICTIM_H
# define VICTIM_H

# include <iostream>

class Victim {

public:

	Victim(std::string name);
	Victim(Victim const & src);
	virtual ~Victim(void);

	Victim &	operator=(Victim const & rhs);

	virtual void	getPolymorphed(void) const;

	std::string getName(void) const;

protected:
	Victim(void);

	std::string	_name;

private:


};

std::ostream &	operator<<(std::ostream & o, Victim const & i);

#endif
