#include "Cat.h"
#include <iostream>

typedef unsigned int uint;

Cat::Cat()
{
	std::cout << "CAT constructor " << "\n";
}

Cat::Cat(uint paws) : Mammal(paws)
{
	std::cout << "CAT constructor With Params" << this->paws << " | " << paws << "\n"; // this means current Class
}

Cat::~Cat()
{
	std::cout << "CAT destructor " << "\n";
}

void Cat::say()
{
	std::cout << "Meow!" << "\n";
}

string Cat::get_current_class()
{
	return "Cat Class";
}

