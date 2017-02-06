#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	//1.9
	int sum = 0;
	for (int i = 50; i <= 100; i++) {
		sum += i;
	}
	cout << sum << endl;
	//1.10
	for (int i = 10; i >= 0; i--) {
		cout << i << " ";
	}
	//1.11
	int i, j;
	cout << "input two number: " << endl;
	cin >> i >> j;
	for (; i <= j; i++) {
		cout << i << " ";
	}
	return 0;
}