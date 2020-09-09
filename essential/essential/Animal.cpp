#include "Animal.h"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal Constructor --" << "\n";
}
Animal::~Animal()
{
	std::cout << "Animal Destructor" << "\n";
}

int Animal::some_val() const // const means that inside function any variable would not be changed
{
	std::cout << "some_val" << "\n";
	return 0;
}

string Animal::get_current_class()
{
	return "Animal Class";
}