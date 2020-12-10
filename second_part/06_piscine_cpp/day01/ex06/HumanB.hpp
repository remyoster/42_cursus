#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void attack(void);
        void setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon *_weapon;
};

#endif
