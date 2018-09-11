#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int i = 5;
	int j = 6;
	int *p = &i;
	p = &j;
	*p = 5;
	cout << j << endl;
	return 0;
}