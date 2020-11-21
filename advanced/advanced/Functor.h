#pragma once
#include <iostream>

class Functor 
{
public:
	// overriding operator ()
	void operator()() {
		std::cout << "some operation in functor instance" << "\n";
	}
};

class Functor_sum
{
public:
	// overriding operator ()
	bool operator()(int a, int b) {
		count++;
		std::cout << "functor_sum called times: " << count << "\n";
		return a > b;
	}

	int count = 0;
};