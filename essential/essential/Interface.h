#include <iostream>
class B;
class SomeClass;
void some_func(SomeClass& some);
// -- START Friends Class Implementation

class SomeClass
{
private:
	int share_data() {
		return data;
	}
	int data = 20;

	friend B; // allow to use private properties and methods in Class friend
	//friend int B::get_data(SomeClass& some); // allow only this method would have access to all properties of Class
	friend void some_func(SomeClass& some); //  allow only this function would have access to all properties of Class
};
void some_func(SomeClass& some)
{
	some.share_data();
}
// -- END Friends Class Implementation

// -- START Interface Implementation
class Interface
{
public:
	virtual void foo() = 0; // creating absjtract method like this, it will declare that this Class is now interface/abstract
};

void Interface::foo()
{
	std::cout << "Interface - foo" << "\n";
}

class B : public Interface
{
public:
	void foo() override;
	int get_data(SomeClass& some);
};

void B::foo()
{
	Interface::foo();
	std::cout << "B - foo" << "\n";
}
int B::get_data(SomeClass& some)
{
	std::cout << "Friends Class - getting private data " << some.share_data() << "\n";
	return some.data;
}
// -- END Interface Implementation