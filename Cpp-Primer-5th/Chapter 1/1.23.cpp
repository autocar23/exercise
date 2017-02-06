#include <iostream>
#include "Sales_item.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_item curItem, item;
	if (cin >> curItem) {
		int cnt = 1;
		while (cin >> item) {
			if (curItem.isbn() == item.isbn()) {
				cnt++;
			} else {
				cout << "The Book which ISBN is \"" << curItem.isbn()
					<< "\" Sales " << cnt << " times" << endl;
				curItem = item;
				cnt = 1;
			}
		}
		cout << "The Book which ISBN is \"" << curItem.isbn()
			<< "\" Sales " << cnt << " times" << endl;
	} else {
		cout << "No Data input!" << endl;
	}
	return 0;
}