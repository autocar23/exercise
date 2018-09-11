#include <iostream>
#include <string>
#include "Person.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Person person("Jack", "main street");
	print(cout, person) << endl;
	return 0;
}