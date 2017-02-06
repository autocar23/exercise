#include <iostream>
#include "Sales_item.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_item curItem, item;
	if (cin >> curItem) {
		while (cin >> item) {
			curItem += item;
		}
		cout << curItem << endl;
	} else {
		cout << "No Data input!" << endl;
	}
	return 0;
}