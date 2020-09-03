#include <iostream> // search directive in folder include
#include <string>
#include "test.h" // search in work catalogue

#define MAX_SIZE 100 // something like a constant
#define ABS(a) (a) < 0 ? -(a) : (a) // function also could be macros
#define createSTR(value) #value // conver value to string
#define concat(a, b)	 a##b   // concat to variables a and b


using namespace std;

void symbolFunctions(); // prototype of function

void calculatePointerFunc(string nameFunc, int value, double(*pFunc)(int));
double funcPointer1(int num);
double funcPointer2(int num);

string FuncOverridedgString();
string FuncOverridedgString(string str);

// anonymous namespace, to create variables that would be unique
namespace {
	int aa = 10;
}

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
	cout << x << " " << y << " " << k << endl;

	// Types of initialization variables
	cout << " -- Types of initialization variables: " << endl;
	int c(255);
	int d = { 3 };
	int e { 2 };
	cout << "Types of initialization variables: " << c << " " << d << " " << e << endl;

	int j = 1;
	int i = 2;
	float r = j / i;
	cout << " int / int === int: " << r << endl; // r === 0 because int / int === int

	// Auto setting type
	cout << " -- Auto setting type: " << endl;
	auto a1 = 1; // int
	auto b1 = 1.1; // double
	auto c1 = 'A'; // char
	cout << "AUTO: " << a1 << " " << b1 << " " << c1 << endl;

	cout.setf(ios::boolalpha); // setf - set formatting of output in console, boolalpha - show bool values as a string
	cout << false << endl;
	cout.unsetf(ios::boolalpha); // unset - unset formatting

	// Get value from console
	cout << " -- Get value from console: " << endl;
	string val;
	cin >> val;
	cout << "You entered value: " + val << endl;

	symbolFunctions();

	// -- START Pointers
	cout << " -- Pointers: " << endl;
	int age = 18;
	int *p_age = &age; // always need to sign some value to pointer at least NULL
	cout << "Pointer: " << p_age << endl;
	cout << "Value: " << *p_age << endl;
	cout << "Enter new value for age" << endl;
	cin >> *p_age;
	cout << "New Pointer Address: " << p_age << endl;
	cout << "New Value: " << age << endl;

	int* pPointer = new int[5]; // [5] - 5 * 4 (5 blocks by 4 bites) bites of memory
	*(pPointer + 0) = 10; // the same as pPointer[0],  save value to first block of memory
	cout << "pPointer[0]: " << pPointer[0] << endl;
	delete[] pPointer; // can be deleted if create via new
	pPointer = NULL; // need to set NULL after deleting pointer from memory

	int a5 = 6;
	int b5 = 9;
	const int *pA = &a5;
	pA = &b5; // norm
	//*pA = &b5; // error

	int *const pA2 = &a5;
	//pA2 = &b5; // error
	*pA2 = 88; // norm

	const int *const pA3 = &a5;
	//pA3 = &b5; // error
	//*pA3 = 88; // error

	int hh = 9;
	int* pHh = &hh;
	cout << pHh << " : " << *pHh << endl;
	pHh--;
	pHh++;
	cout << pHh << " : " << *pHh << endl;

	calculatePointerFunc("funcPointer1: ", 5, funcPointer1); // add function as a pointer to argument
	calculatePointerFunc("funcPointer2: ", 5, funcPointer2);

	// -- END Pointers

	// Overrided Functions
	cout << " -- Overrided Functions: " << endl;
	cout << FuncOverridedgString() << endl; // function should start from capital letter in order to override
	cout << FuncOverridedgString("Vasya") << endl;

	// Links
	cout << " -- Links: " << endl;
	int ab = 1;
	int& lAb = ab; // creating link
	cout << "before ab: " << ab << " before lAb: " << lAb << endl;

	lAb = 2;
	cout << "after ab: " << ab << " after lAb: " << lAb << endl;

	// Array
	cout << " -- Array: " << endl;
	int arr[3];
	arr[0] = 5;
	arr[1] = 15;
	cout << "First Elelemnt Address of Array: " << arr << endl;
	cout << "Address Element Array: " << &arr[1] << " Value Element Array: " << arr[1] << endl;
	// arr[3] = 6; // never do it like this,  you need control working with array elements

	int arr2[4] = { 10, 20, 30, 40 }; // arr[0] == 10, arr[1] == 20,  etc..
	int arr3[] = { 10, 20, 30, 40 }; // compiler will calculate the length of array

	cout << "Zize of Array in Bites: " << sizeof(arr2) << endl;
	cout << "Length of Array: " << sizeof(arr2) / sizeof(arr2[0]) << endl;

	int arr4[2][2] = { // two-dimensional array
		{1, 2},
		{3, 4}
	};

	int arr5[2] = { 10, 20 };
	int* pArr5 = arr5;
	cout << "First: " << pArr5[0] << " The same as " << *(pArr5 + 0) << endl;
	cout << "Second: " << pArr5[1] << " The same as " << *(pArr5 + 1) << endl;
 
	int *arr_pointers[2]; // array of pointers
	int x1 = 100;
	int y1 = 200;
	*arr_pointers = &x1;
	*(arr_pointers + 1) = &y1;
	cout << "Arr Pointer Address: " << *(arr_pointers + 1) << " Arr Pointer Value: " << *(*(arr_pointers + 1)) << endl;


	// Strings
	// '' - char, "" - string
	cout << " -- Strings: " << endl;
	char first_str[5] = { 'h', 'e', 'l', 'l', 'o' }; // is not a string, just number of chars
	char second_str[5] = { 'h', 'e', 'l', 'l', '\0' }; // is a string because contains end of string - \0
	char third_str[] = "Hello World"; // this is also string
	string third_str2 = "Hello World";
	cout << first_str << " " << second_str << " " << third_str << endl;
	cout << "Length of string: " << strlen(third_str) << " : " << third_str2.size() << endl;

	//cin.getline(name, 20) // cin.getline - needs to read hall line with spaces, otherwise space, enter, tab etc it will means end of entered data
	char str_copy[16];
	char str_cat[40] = "Hi! ";
	strcpy_s(str_copy, third_str); // copy string
	strcat_s(str_cat, str_copy); // concatenation
	cout << str_cat << endl;
	// strcmp - compare strings by length Return: 0 or 1 or -1
	char *pFindChar = strchr(third_str, 'o'); // find char in string and return address
	cout << "Find char address: " << &pFindChar << " Find Char: " << *pFindChar << endl;

	// Namespaces
	cout << " -- Namespaces: " << endl;
	std::cout << "Hello std namespace" << std::endl;

	return 0;
}

void symbolFunctions() {
	char ch = 'A';

	bool result = isalpha(ch);				// is a char

	cout << boolalpha << result << endl;

	ch = '\r';
	result = iscntrl(ch);					// is a symbol that control cursor behavior
	cout << boolalpha << result << endl;

	ch = '1';
	result = isdigit(ch);					// is a digit
	cout << boolalpha << result << endl;

	ch = 'q';
	result = islower(ch);					// is lower case
	cout << boolalpha << result << endl;

	result = isupper(ch);					// is upper case
	cout << boolalpha << result << endl;

	ch = ',';
	result = ispunct(ch);					// is a punctoation
	cout << boolalpha << result << endl;

	ch = '\t';
	result = isspace(ch);					// is a space, tab etc
	cout << boolalpha << result << endl;

	ch = tolower('A');						// convert to lower case
	cout << ch << endl;

	ch = toupper(ch);						// convert to upper case
	cout << ch << endl;
}

// -- START Pointers Functions
void calculatePointerFunc(string nameFunc, int value, double(*pFunc)(int)) {
	cout << nameFunc << (*pFunc)(value) << endl;
}
double funcPointer1(int num) {
	return num * 0.5;
}
double funcPointer2(int num) {
	return num * 0.3;
}
// -- END Pointers Functions

// -- START Overriding Functions
string FuncOverridedgString() {
	return "Hello World";
}
string FuncOverridedgString(string str) {
	return str;
}
// -- END Overriding Functions