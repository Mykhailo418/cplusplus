
typedef unsigned int uint;

class Mammal
{
public:
	Mammal();
	Mammal(uint paws);
	Mammal(const Mammal&); // special constructor that make copy from instance of the same Class(Mammal)
	virtual ~Mammal(); // need to put virtual in order to run destructor in child Classes
	void feed_milk();
	uint get_paws();
	uint paws = 4;

	virtual void say();

private:
	int some_private_val;
	int* ptr;
};

