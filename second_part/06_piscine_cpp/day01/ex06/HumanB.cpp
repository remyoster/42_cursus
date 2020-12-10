#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}
HumanB::~HumanB(void) {}

void HumanB::attack(void)
{
    std::cout << this->_name << " attacks with his ";
    std::cout << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
