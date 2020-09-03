#include "iostream"

// Creating namespace
namespace NamespaceA {
	void mul(int a, int b) {
		std::cout << (a * b) << std::endl;
	}
}

// namespaces with same name will be combined
// !! variables and functions should be unique
namespace NamespaceA {
	void func() {
		std::cout << "This namespace was added to above one";
	}
	// it would make error during build
	/*void mul(int a, int b) {
		std::cout << (a * b) << std::endl;
	}*/
}

using namespace NamespaceA;

int main1() {
	mul(10, 42);
	func();
	return 0;
}