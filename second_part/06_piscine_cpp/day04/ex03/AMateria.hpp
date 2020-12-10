#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{

	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		virtual ~AMateria(void);

		std::string const &getType() const;
		unsigned int getXP() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target) = 0;

		AMateria &operator=(AMateria const &rhs);

		void	setXp(int xp);

	private:
		unsigned int		_xp;
		std::string	const	_type;
	};

#endif
