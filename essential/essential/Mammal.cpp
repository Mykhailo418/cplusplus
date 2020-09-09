#include "Mammal.h"
#include <iostream>

Mammal::Mammal()
{
	std::cout << "Mammal Constructor" << "\n";
	ptr = new int[10]; // everything that was creating with "new" should be deleted manualy
}
Mammal::Mammal(uint paws) : paws(paws) // one of the ways to sign value to property in Class
{
	std::cout << "Mammal Constructor with paws param" << " Paws :" << paws << "\n";
}
Mammal::Mammal(const Mammal& other)
{
	paws = other.paws;
}
Mammal::~Mammal()
{
	std::cout << "Mammal Destructor done" << "\n";
	delete[] ptr; // if parameter was created with [] so should be deleted with []
}

void Mammal::feed_milk()
{
	std::cout << 'done' << "\n";
}

uint Mammal::get_paws()
{
	return paws;
}

void Mammal::say()
{
	std::cout << "say something" << "\n";
}