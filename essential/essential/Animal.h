#ifndef Animal_HEADER // this is need when this file includes in multiple files ans those files includes in ne place, like Domestic and Pedigreed
#define Animal_HEADER

#include <iostream>

#ifndef string
#define string std::string
#endif

class Animal
{
public:
	Animal();
	virtual ~Animal();
	int virtual some_val() const;
	string virtual get_current_class();
};
#endif

