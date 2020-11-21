#include <iostream>
#pragma once

void bind_example() {
	using namespace std::placeholders;

	auto sub = [](int a, int b, int c) -> int {
		return a - b - c;
	} ;
	auto w = std::bind(sub, _2, _1, -5); // _1 - first argument, _2 - second argument, 

	std::cout << "Bind Example sub: " << w(2, 1) << "\n";
}