#include "Gobelin.hpp"

Gobelin::Gobelin(void) {
	this->_name = "Xuark";
	std::cout << "Rouik rouik" << std::endl;
	return ;
}

Gobelin::Gobelin(std::string name) : Victim(name) {
	std::cout << "Rouik rouik" << std::endl;
	return ;
}

Gobelin::Gobelin(Gobelin const & src) {
	*this = src;
	std::cout << "Rouik rouik." << std::endl;
	return ;
}

Gobelin::~Gobelin(void) {
	std::cout << "Blijsaidjaisdi..." << std::endl;
	return ;
}

Gobelin &	Gobelin::operator=(Gobelin const & rhs) {
	this->_name = rhs.getName();
	return (*this);
}

void	Gobelin::getPolymorphed(void) const {
	std::cout << this->_name << " was just polymorphed into a cute woman!" << std::endl;
	return;
}

std::ostream &	operator<<(std::ostream & o, Gobelin const & i) {
	o << "I'm " << i.getName() << " and I like mud!" << std::endl;
	return (o);
}

