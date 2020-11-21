#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "Atemp.h"
#include <string>
#include <map>
#include "Functor.h"
#include "bind_example.h"
#include "array.h"
#include "vector.h"
#include "lists.h"
#include "associative_containers.h"
#include "unordered.h"
#include "adapters.h"

using namespace std;

using muFunc_stdFunction = int(int, int);

int sum(int a, int b);
int sum_with_functor(int a, int b, Functor f);
bool comparator(int a, int b);

int main() {

	// -- Data type output by using templates
	cout << "-- Data type output by using templates" << endl;
	double b = 4.5;
	auto c = b;
	auto d = 4.f;

	cout << endl << "Iterator Map: " << endl;
	map<string, int> mp = { // in map key can be anything
		{"map1", 5},
		{"map2", 15},
		{"map3", 75}
	};
	auto map2 = mp.find("map2"); // find cell
	mp.erase(map2);    // or mp.erase("map2");        // delete in map cell
	for (auto it : mp) {
		cout << "Map: " << "key - " << it.first << ", value - " << it.second << endl;
	}

	auto x3 = { 27 }; // std::initializer_list<int> with value 27

	// -- Decltype
	cout << endl << "-- Decltype: " << endl;
	int a33 = 50;
	decltype(a33) b33 = 10.8; // declare the same type as a33 hase
	cout << "b33 = " << b33 << endl;

	// -- Functor
	cout << endl << "-- Functor: " << endl;
	Functor f;
	Functor_sum f_sum;

	cout << "Functor sum: " << sum_with_functor(4, 5, f) <<endl;

	// -- Sorting
	cout << endl << "-- Sorting: " << endl;
	vector<int> vect_sort = { 6, 2, 7, 1 };

	//sort(vect_sort.begin(), vect_sort.end(), comparator); // with simple function
	sort(vect_sort.begin(), vect_sort.end(), f_sum); // with functor
	for (auto it : vect_sort) {
		cout << it << " ";
	}

	// -- std::function - Class that can wrap any kind of callable element 
	cout << endl << "-- std::function: " << endl;
	std::function<muFunc_stdFunction> std_sum_func; // without initializing it will queal nullptr
	std_sum_func = sum;
	cout << "std::function - sum = " << std_sum_func(9, 4) << endl;

	// -- Lambda Expressions
	cout << endl << "-- Lambda Expressions: " << endl;
	// [=] - scope variable accessibility which variable can be availabled inside lamda functuons, = - means all variable available
	// () - as a classic function declaration
	// mutable - optional, variable outside lamda function can be mutated
	// throw() - 
	// -> int - what lamda function will return
	vector<int> vect_sort2 = { 8, 2, 1, 4 };
	sort(vect_sort2.begin(), vect_sort2.end(), [](int a, int b) -> bool { return a > b; }); // lambda function as a param

	auto lamda_f = [vect_sort2] () mutable {
		// does not change vect_sort2 outside of this function
		vect_sort2[2] = 10;
		for (auto it : vect_sort2) {
			cout << it << " ";
		}
		cout << endl;
	};
	lamda_f();
	[]() { cout << "this function created and run" << endl; }();

	bind_example();

	// -- CONTAINERS
	cout << endl << "-- CONTAINERS: " << endl;
	array_main();
	vector_main();
	lists_main();
	assoc_containers_main();
	unordered_main();
	adapters_main();

	return 0;
}

int sum(int a, int b) {
	return a + b;
}

int sum_with_functor(int a, int b, Functor f) {
	f();
	return sum(a, b);
}

// function for sorting function
bool comparator(int a, int b) { 
	return b < a;
}