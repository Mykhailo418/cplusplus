#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template <typename T>
T sum(T a, T b)
{
	return a + b;
}

template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a + b) // decltype - calculate which type would be returned
{
	return a + b;
}

// Class Template
template <typename T = double> // can be placed default value, but it is not necessary
class Atempl
{
public:
	void proccess()
	{
		cout << "Template Class Atempl value = " << a << endl;
	}

	T a;
};

template <>
class Atempl<string> // this Class would be used only if Class Atempl will be used with specific type, in this case is "string"
{
public:
	void proccess()
	{
		cout << "Template Class Atempl<string> value = " << a + a << endl;
	}

	string a = "- str - ";
};

// for multiple specific types, for example for pointers
template <typename T>
class Atempl<T*>
{
public:
	void proccess()
	{
		cout << "Template Class Atempl<T*> value = " << *a << " address = " << a << endl;
	}
	template<typename V>
	void process_templ(); // declaring templated method in Classs

	T* a;
};

// template method for Template Class
template <typename T>
template<typename V>
void Atempl<T*>::process_templ()
{
	cout << "Template Method of Template Class: " << static_cast<V>(*a) << endl; // static_car convert primitive types from one to another
}



// Inheritance from template Class
template <typename T, typename U>
class Btempl : public Atempl<T> // if T would be "string" it will inherits from "class Atempl<string>"
{
public:
	U b;
};