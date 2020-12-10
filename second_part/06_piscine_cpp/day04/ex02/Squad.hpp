#ifndef SQUAD_H
# define SQUAD_H

# include <iostream>
# include "ISquad.hpp"

class Squad : public ISquad {

public:

	Squad(void);
	Squad(Squad const & src);
	virtual ~Squad(void);
	Squad &	operator=(Squad const & rhs);

	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int n) const ;
	virtual int push(ISpaceMarine* soldier);


private:
	void	_deleteArmy();

	int						_nbUnits;
	typedef	struct			s_container {
		ISpaceMarine		*unit;
		struct s_container	*next;
	}						t_container;

	t_container				*_army;
};

#endif
