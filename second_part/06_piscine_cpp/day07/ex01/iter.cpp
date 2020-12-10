#include <iostream>

template<typename T>
void	iter(T *array, size_t size, void (*fct)(T & val)) {
	for (size_t i = 0; i < size; i++)
		fct(array[i]);
}

template<typename T>
void	sum(T & val) {
	val += 1;
}

template<typename T>
void	print_val(T & val) {
	std::cout << val << std::endl;
}

int main() {
	int tab[] = {1, 2, 3, 4};
	std::string test[] = {"Je suis", "Tu es"};

	::iter(tab, 4, &print_val);
	::iter(test, 2, &print_val);
	::iter(tab, 4, &sum);
	::iter(tab, 4, &print_val);
	return (0);
}