#include <iostream>
#include "Sales_item.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_item total;
	if (cin >> total) {  //[ISBN号] [售出册数] [单价]
		Sales_item trans;
		while (cin >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans;
			} else {
				cout << total << endl; //[ISBN号] [售出册数] [销售额] [平均价格]
				total = trans;
			}
		}
		cout << total << endl;
	} else {
		std::cerr << "No data?" << endl;
		return -1;
	}
	return 0;
}