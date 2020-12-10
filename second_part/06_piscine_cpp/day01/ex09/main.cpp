#include "Logger.hpp"

int main(int ac, char **av) {

	Logger console("logs");

	if (ac == 3) {
		console.log(av[1], av[2]);
	}
	else {
		console.log("console", "Hello world !");
		console.log("file", "Hello world !");
	}

	return (0);
}