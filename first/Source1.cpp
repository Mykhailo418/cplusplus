#include <iostream>

using namespace std;

int main() {
	printf("Hello World"); // print to console
	//getwchar(); // whait to get symbol
	cout << endl; // move coursor to next line
	cout << "str line"; // cout (console out) from iostream library, "<<" - put params to object
	cin.get(); // cin (console in)
	cout << endl;
	// short - 16 bit, long - 64 bit, (no long, no short) - 32bit, double - 64 bit
	short int x = 10; // short/long - range of values
	unsigned short int y = 5; // unsigned - means need value > 0 (короче беззнаковый тип)
	const unsigned long int k = 8888;
	cout << x << endl << y << endl << k;
	return 0;
}