#include "Human.hpp"

Human::Human(std::string str) : _name(str) {}

Human::~Human() {}

void Human::meleeAttack(std::string const &target)
{
	std::cout << this->_name << " melee attacks " << target << std::endl;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << this->_name << " ranged attacks " << target << std::endl;
}

void Human::intimidatingShout(std::string const &target)
{
	std::cout << this->_name << " intimidating shouts " << target << std::endl;
}

void Human::action(std::string const &action_name, std::string const &target)
{
	std::string actions[] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};
	void (Human::*fct[])(std::string const &target) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};
	size_t idx = 0;

	while (idx < 3)
	{
		if (actions[idx].compare(action_name) == 0)
		{
			(this->*fct[idx])(target);
			return;
		}
		idx++;
	}
	std::cout << action_name << " action does't exists" << std::endl;
}

std::string Human::getName() const {
	return (this->_name);
}