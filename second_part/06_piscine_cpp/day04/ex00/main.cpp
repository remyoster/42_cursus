#include <iostream>
#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Gobelin.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << std::endl;

	Sorcerer gandalf("Gandalf", "the grey");
	Gobelin pierre("Pierre");

	std::cout << gandalf << pierre;

	gandalf.polymorph(pierre);

	return 0;
}