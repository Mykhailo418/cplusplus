#ifndef Animal
#include "Animal.h"
#endif
#include <iostream>

#define string std::string

// put virtual in order to prevent multiple runs constructor of Base Class 
// when another child inherits from several classes that inherits from one same Base class
// Examlple: Cat -> Pedigreed, Domestic;  Pedigreed -> Animal; Domestic -> Animal
class Domestic : public virtual Animal
{
public:
	string get_name();
	string get_current_class();

private:
	string name;
};

