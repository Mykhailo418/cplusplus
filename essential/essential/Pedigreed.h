#include <iostream>
#ifndef Animal
#include "Animal.h"
#endif

#define string std::string

// put virtual in order to prevent multiple runs constructor of Base Class 
// when another child inherits from several classes that inherits from one same Base class
// Examlple: Cat -> Pedigreed, Domestic;  Pedigreed -> Animal; Domestic -> Animal
class Pedigreed : public virtual Animal 
{
public:
	string get_history();
	string get_current_class();

private:
	string history;
};

