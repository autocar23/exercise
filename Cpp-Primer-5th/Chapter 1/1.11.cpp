#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int i, j;
	cout << "input two number: " << endl;
	cin >> i >> j;
	while (i <= j) {
		cout << i << " ";
		i++;
	}
	return 0;
}