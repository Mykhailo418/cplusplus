#pragma once
#include <iostream>
#include <vector>

using namespace std;

void vector_main() {
	cout << "- Vectors: " << endl;
	vector<int> my_vector; // like a dynamic array
	my_vector.reserve(3);
	my_vector = { 1, 2, 3, 4 }; // increase size of vector even if it reserve 3 cells
	cout << "My Vector Capacity: " << my_vector.capacity() << endl; // how many cells vector reserve, 
	cout << "My Vector Size: " << my_vector.size() << endl; // how many cells used

	vector<int> a = { 5, 6, 23 };
	a.push_back(66); // add elevemnt to vector

	cout << "Iterator Vector 1: " << endl;
	for (auto it = a.begin(); it != a.end(); it++) {
		cout << "Vector item: " << *it << endl;
	}
	cout << endl << "Iterator Vector 2: " << endl;
	for (auto it : a) {
		cout << "Vector item: " << it << endl;
	}
}