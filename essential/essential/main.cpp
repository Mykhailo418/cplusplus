#include <iostream>
#include "Cat.h"
#include "Interface.h"
#include "Number.h"
#include "Templates.h"
#include "ScopedPtr.h"
#include "ScopedPtr.cpp" // need to put cpp with .h in another it would be error
#include <memory>
#include <exception>

using namespace std;

typedef int digit; // renaming type from int -> digit
typedef unsigned int positive_digit;

enum class Color : int {red = 5, green, blue}; // "enum class" is strict mode for "enum"

// for Structure need to put params inside from biggest(by size) to lowest(ex from double to in)
// The only difference between a struct and class in C++ is the default accessibility of member variables and methods.
// In a struct they are public; in a class they are private.
struct Car
{
	struct WheelType
	{
		string name;
	};
	string name;
	int width = 50; // default value
	int length{ 4 }; // also default value
	int wheels;
};

// union like a struct, used to use one cell memory for few params, size of union depends equl to size of biggest param,  in this case its double_val
union SomeType {
	int val;
	double double_val;
};

struct SomeStruct
{
	int val;

	// it allows to use params a and b strictlly from struct, ex SomeStruct v; v.a = 1;
	union {
		int a;
		int b;
	};
};

void doSay(Mammal* m);
void inline some_inline_func();

string Cat::word = "Hello static"; // static value must be initialized before code but not inside the Class

struct CCC
{
	// constructor
	CCC(int _data) try : data(_data)  // some kind of try catch inside method of Class
	{
		throw 1;
	}
	catch (...) {

	}

	//destructor
	~CCC()
	{
		cout << "~CCC destructor" << endl;
	}

	int data;
};

struct Custom_exception : exception
{
	Custom_exception() {

	}
	~Custom_exception() {

	}
};

struct Resource {
	//shared_ptr<Resource> other;
	weak_ptr<Resource> other;
};
void weak_ptr_example();

int main() {
	digit g = 0;
	positive_digit n = 2;

	// Typedef
	cout << "-- Typedef: " << endl;
	cout << g + n << endl;

	// Enum
	cout << endl << "-- enum: " << endl;
	Color green = Color::green;
	cout << "Green: " << (int)green << endl; // (int) <- is converting to specifuc type, in this case to int

	// Struct
	cout << endl << "-- Structure: " << endl;
	Car bmw;
	bmw.name = "BMW";
	bmw.length = 100;
	cout << bmw.name << " Length: " << bmw.length << " Width: " << bmw.width << " Wheels: " << bmw.wheels << endl;
	Car* pBmw = &bmw;
	cout << "Pointer of struct : " << pBmw->name << " : " << pBmw->length << endl; // to get params from pointer of struct use ->

	// Class
	cout << endl << "-- Class: " << endl;
	Mammal mammalInst1;
	Mammal mammalInst2(6);
	Mammal mammalCopy = mammalInst1;
	cout << "Paws: " << mammalInst1.get_paws() << " | " << mammalInst2.get_paws() << " | " << mammalCopy.get_paws() << "\n";
	Mammal* new_m = new Mammal();
	new_m->say();
	delete new_m; // pointer with instance would not be deleted after program finished, it is need to be deleted manualy

	// Class - Inheritence
	cout << endl << "-- Class - Inheritence: " << endl;
	Cat c(7);
	Mammal* pCatMammal = new Cat();
	c.say();
	pCatMammal->say(); // if this method would ne be "virtual" it will run method of Base Class, in this case without "virtual" it would run say of Mammal Class
	cout << "-- " << endl;
	doSay(pCatMammal);
	doSay(&c);
	c.Mammal::say(); // we can get access to Base class via instance of Child Class

	// Convertins object types
	cout << endl << "-- Convertins object types: " << endl;
	if (dynamic_cast<Cat*>(pCatMammal)) {
		// dynamic_cast - used to convert instance of on Class to another, if it is possible
		Cat* pCat = dynamic_cast<Cat*>(pCatMammal);
		cout << "dynamic_cast - paws: " << pCat->get_paws() << "\n";
	}
	delete pCatMammal;

	Animal* animal2;
	bool isDomestic = true;
	if (isDomestic) {
		animal2 = new Domestic();
	} else {
		animal2 = new Pedigreed();
	}

	// dynamic_cast used to check to which Class instance related
	if (dynamic_cast<Domestic*>(animal2)) {
		cout << "Animal 2 is Domestic" << "\n";
	} else {
		cout << "Animal 2 is Pedigreed" << "\n";
	}

	Animal* animal6 = new Cat();
	Animal* on = animal6;
	Pedigreed* ptr_ped = dynamic_cast<Pedigreed*>(on);

	// check if objects reference to same object
	if (dynamic_cast<void*>(animal6) == dynamic_cast<void*>(ptr_ped)) {
		cout << "animal6 === ptr_ped " << animal6 << " | " << ptr_ped << "\n";
		cout << animal6->get_current_class() << " | " << ptr_ped->get_current_class() << "\n";
	}

	auto ped_9 = dynamic_cast<Pedigreed*>(animal6);
	auto cat_9 = dynamic_cast<Cat*>(ped_9);
	if (auto dom_9 = dynamic_cast<Domestic*>(cat_9)) {
		cout << "Domestic " << dom_9->get_current_class() << "\n";
	}
	cout << "Converting siblings classes " << ped_9->get_current_class() << " | " << cat_9->get_current_class() << "\n";


	// -- Additional Fetures:
	cout << endl << "-- Additional Fetures: " << endl;
	some_inline_func(); // it would ne replaced by body code of function
	cout << "static value: " << Cat::get_statWord() << "\n";
	B b;
	SomeClass sm;
	b.foo();
	b.get_data(sm);

	// -- Operators overriding
	cout << endl << "-- Operators overriding: " << endl;
	Number a_o(4), b_o(10);
	b_o = a_o;
	cout << a_o + b_o;

	// -- Templates
	cout << endl << "-- Templates: " << endl;
	cout << sum(4, 5) << endl;
	cout << sum(4.5, 6) << endl;
	cout << sum(4, "abcde") << endl;

	Atempl<int> obj_tmpl;
	obj_tmpl.a = 67;
	obj_tmpl.proccess();

	Atempl<string> obj_tmpl_str;
	obj_tmpl_str.proccess();

	Btempl<int, double> b_Btempl;

	int member_ptr = 10;
	Atempl<int*> obj_ptr;
	obj_ptr.a = &member_ptr;
	obj_ptr.proccess();

	double member_ptr2 = 12.5;
	Atempl<double*> obj_ptr2;
	obj_ptr2.a = &member_ptr2;
	obj_ptr2.process_templ<int>(); // in this method would be converting double(12.5) to int


	// -- Smart Pointers
	cout << endl << "-- Smart Pointers: " << endl;
	ScopedPtr<Cat> smart_cat(new Cat()); // this smart pointer will remove Cat pointer automatically, and you do not need delete it manually
	cout << smart_cat->get_name() << endl;

	ScopedPtr<int> smart_int(new int(10));
	cout << "before smart_int = " << *smart_int << endl;
	int& smart_int_link = *smart_int;
	smart_int_link = 99;
	cout << "after smart_int = " << *smart_int << endl;

	// unique_ptr - smart pointer that have only unique pointerand can not be copied or redefined
	unique_ptr<int> a_unique_ptr(new int(5));
	unique_ptr<int> b_unique_ptr(new int(8));
	//b_unique_ptr = a_unique_ptr; // error
	b_unique_ptr = std::move(a_unique_ptr); // in this case it will move and no error, and a_unique_ptr would be empty
	cout << "a_unique_ptr: " << a_unique_ptr.get() << " b_unique_ptr = " << b_unique_ptr.get() << endl;
	if (a_unique_ptr.get()) {
		cout << "Address: " << a_unique_ptr.get() << " a_unique_ptr = " << *a_unique_ptr << endl;
	}
	if (b_unique_ptr.get()) {
		cout << "Address: " << b_unique_ptr.get() << " b_unique_ptr = " << *b_unique_ptr << endl;
	}

	int* ptr77 = new int(100);
	// shared_ptr - one on address can be point several pointers
	shared_ptr<int> a77 = make_shared<int>(*ptr77);
	delete ptr77;
	{
	    shared_ptr<int> b77 = a77;
	    cout << "a = " << *a77 << " b = " << *b77 << endl;
	    *b77 = 9;
	    cout << "a = " << *a77 << " b = " << *b77 << endl;
	    cout << "count  = " << a77.use_count() << endl; // use_count - return number of pointers that reference to current cell of  this instance
	}
	cout << "a = " << *a77 << endl;
	cout << "count  = " << a77.use_count() << endl;

	weak_ptr_example();

	// -- Exceptions
	cout << endl << "-- Exceptions: " << endl;
	try {
		string().at(1);
		// if would be error in try, all instances will run destruction method
	}
	catch (exception& err) {
		cerr << err.what() << endl;
	}
	try {
		CCC ccc(3);
		throw 42;
	}
	catch (logic_error& err) { // can be multiple catch block for one try block

	}
	catch (...) { // ... - if you do not know error type
		cerr << "some error" << endl;
	}

	cout << endl << "-- END Program" << endl;
	return 0;
}
void doSay(Mammal *m) {
	m->say();
}

// inline function that where it runs it place body code of function in that spot
void inline some_inline_func() {
	cout << "Run inline func" << "\n";
}

void weak_ptr_example() {
	// shared_ptr<Resource> a(new Resource)
	auto a = make_shared<Resource>();
	auto b = make_shared<Resource>();
	a->other = b;
	cout << "-----" << endl;
	cout << "count a = " << a.use_count() << endl;
	cout << "count b = " << b.use_count() << endl;
	cout << "-----" << endl;

	b->other = a;
	cout << "-----" << endl;
	cout << "count a = " << a.use_count() << endl;
	cout << "count b = " << b.use_count() << endl;
	cout << "-----" << endl;

	// run destructores ti delete pointers
	a.~shared_ptr();
	b.~shared_ptr();

	// it will show that 1 pointer is exists for both variables, because those pointers referenced to each other, 
	// this is bed and now you can not delete those pointers
	// id you weak_ptr in Resource, s everything would be fine
	cout << "count a = " << a.use_count() << endl;
	cout << "count b = " << b.use_count() << endl;
}