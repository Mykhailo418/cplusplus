#define MAX_SIZE 100
#define PRODUCTION 10		// DEVELOMENT

#include <iostream>

using namespace std;

int main8()
{
	// сравниваем значение макроса с литералом.
#if MAX_SIZE <= 100
	cout << "The size of the array is normal!" << endl;
#elif MAXSIZE > 100
	cout << "Please enter a different size. The size is too big!" << endl;
#elif MAX_SIZE <= 0
	cout << "The size of the array can not be less than 0!";
#endif


#ifdef PRODUCTION // if PRODUCTION is defined
	int a = 1;
	cout << "Product version." << endl;
#elif DEVELOMENT
	cout << "Dev version." << endl;
#endif 

#ifndef DEVELOMENT // if DEVELOPMENT is Not defined
	int a = 1;
	cout << "Dev version." << endl;
#elif PRODUCTION
	cout << "Product version." << endl;
#endif 


	system("pause");
	return 0;
}