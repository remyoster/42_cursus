#include "Pony.hpp"
#include <iostream>


void ponyOnTheStack(void) {
	Pony instance("Stack jumper");

	std::cout << "(poneyOnTheStack)Pony object : " << Pony::getNbInst() << std::endl;

	instance.snort();
	instance.walk();
	instance.stop();
}

void ponyOnTheHeap(void) {
	Pony *instance = new Pony("Heap jumper");

	std::cout << "(poneyOnTheHeap)Pony object : " << Pony::getNbInst() << std::endl;
	
	instance->snort();
	instance->walk();
	instance->stop();

	delete (instance);
}

int main(void) {
	std::cout << "(main)Pony object : " << Pony::getNbInst() << std::endl;
	ponyOnTheStack();
	ponyOnTheHeap();
	std::cout << "(main)Pony object : " << Pony::getNbInst() << std::endl;
}