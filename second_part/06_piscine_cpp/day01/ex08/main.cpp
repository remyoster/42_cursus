#include "Human.hpp"

int main() {
	Human bob = Human("Bob");
	Human jean("Jean");

	bob.action("meleeAttack", jean.getName());
	jean.action("rangedAttack", bob.getName());
	bob.action("intimidatingShout", jean.getName());

	bob.action("test", jean.getName());

	return (0);
}