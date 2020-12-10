#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter {

public:

	Character(std::string const & name);
	Character(Character const & src);
	~Character(void);

	Character &	operator=(Character const & rhs);
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	AMateria *getMateria(int idx) const;
	int	getEquiped() const;

private:
	Character();
	void				_deleteInv();

	typedef struct		s_inventory {
		AMateria 		*materia;
		s_inventory		*next;
	}					t_inventory;

	std::string const	& _name;
	t_inventory 		*_inv;
	int 				_equiped;


};

#endif
