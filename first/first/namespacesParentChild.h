#include <iostream>

using namespace std;

namespace NamespaceA {
	struct MyStruct
	{

	};
	namespace NamespaceB {
		struct MyStruct
		{

		};

		void method() {
			MyStruct variable1;
			NamespaceA::MyStruct variable2;
		}
	}
}

int main4()
{
	return 0;
}