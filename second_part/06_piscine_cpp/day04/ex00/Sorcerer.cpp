#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) : _name("Gandalf"), _title("le gris") {
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return ;
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;

}

Sorcerer::Sorcerer(Sorcerer const & src) {
	*this = src;
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return ;
}

Sorcerer::~Sorcerer(void) {
	std::cout << this->_name << ", " << this->_title;
	std::cout << " , is dead. Consequences will never be the same!" << std::endl;
	return ;
}

Sorcerer &	Sorcerer::operator=(Sorcerer const & rhs) {
	this->_title = rhs.getTitle();
	return (*this);
}

std::string	Sorcerer::getName(void) const { 
	return (this->_name);
}

std::string	Sorcerer::getTitle(void) const { 
	return (this->_title);
}

void	Sorcerer::polymorph(Victim const & v) const {
	v.getPolymorphed();
	return ;
}

std::ostream &	operator<<(std::ostream & o, Sorcerer const & i) {
	o << "I am " << i.getName() << ", " << i.getTitle() << ", and i like ponies!" << std::endl;
	return (o);
}
