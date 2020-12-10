#include "Base.hpp"
#include <iostream>

void	identify_pointer_from(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference( Base & p) {
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}

int main() {
	A a;
	B b;
	C c;

	std::cout << "Identify from pointer" << std::endl;
	identify_pointer_from(&a);
	identify_pointer_from(&b);
	identify_pointer_from(&c);

	std::cout << "Identify from reference" << std::endl;
	identify_from_reference(a);
	identify_from_reference(b);
	identify_from_reference(c);

}