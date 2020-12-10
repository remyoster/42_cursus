#ifndef HUMAN_H
# define HUMAN_H

# include <iostream>

class Human
{
	private:
		void meleeAttack(std::string const &target);
		void rangedAttack(std::string const &target);
		void intimidatingShout(std::string const &target);

		std::string _name;

	public:
		Human(std::string str);
		~Human();
		void action(std::string const &action_name, std::string const &target);
		std::string getName() const;
};

#endif
