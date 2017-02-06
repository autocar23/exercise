#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int i, j;
	cout << "input two number: " << endl;
	cin >> i >> j;
	if (i > j) {
		int tmp = i;
		i = j;
		j = tmp;
	}
	while (i <= j) {
		cout << i << " ";
		i++;
	}
	return 0;
}