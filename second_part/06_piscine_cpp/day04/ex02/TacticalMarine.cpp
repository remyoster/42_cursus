#include <iostream>
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void) {
	std::cout << "Tactical Marine ready for action !" << std::endl;
	return ;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src) {
	(void)src;
	std::cout << "Tactical Marine ready for action !" << std::endl;
	return ;
}

TacticalMarine::~TacticalMarine(void) {
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

ISpaceMarine	*TacticalMarine::clone() const {
	return (new TacticalMarine(*this));
}

TacticalMarine &	TacticalMarine::operator=(TacticalMarine const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

void	TacticalMarine::battleCry() const {
	std::cout << "For the Holy PLOT !" << std::endl;
	return ;
}

void	TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with a bolter *" << std::endl;
	return ;
}

void	TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with a chainsword *" << std::endl;
	return ;
}

