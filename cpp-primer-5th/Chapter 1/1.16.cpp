#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0;
	int num;
	while (cin >> num) {
		sum += num;
	}
	cout << sum << endl;
	return 0;
}