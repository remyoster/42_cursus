#include <iostream>
#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void) {
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src) {
	(void)src;
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator::~AssaultTerminator(void) {
	std::cout << "I’ll be back ..." << std::endl;
	return ;
}

AssaultTerminator &	AssaultTerminator::operator=(AssaultTerminator const & rhs) {
	std::cout << "BIFDOF" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

ISpaceMarine	*AssaultTerminator::clone() const {
	return (new AssaultTerminator(*this));
}

void	AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. Purify it !" << std::endl;
	return ;
}

void	AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
	return ;
}

void	AssaultTerminator::meleeAttack() const {
	std::cout << "* attaque with chainfists *" << std::endl;
	return ;
}
