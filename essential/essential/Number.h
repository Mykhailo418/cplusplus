#include <iostream>

using namespace std;

// operators overriding
class Number
{
public:
	explicit Number(int data); // explicit means constructor need to call directly
	Number& operator=(const Number& other);
	Number operator+(const Number& other) const;
	friend ostream& operator<<(ostream& s, const Number& number);
private:
	int data;
};

