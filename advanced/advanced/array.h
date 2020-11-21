#pragma once
#include <iostream>
#include <array>

using namespace std;

void array_main() {
	cout << "- Arrays: " << endl;
	array<int, 10> my_array;
	my_array[4] = 4;

	cout << "Arra.at: " << my_array.at(4) << endl; // usig at() garantee to get valid value, otherway throw exception
}