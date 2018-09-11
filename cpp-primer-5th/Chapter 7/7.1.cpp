#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data total;
	double price = 0;
	if (cin >> total.bookNo >> total.units_sold >> price) {  //[ISBN��] [�۳�����] [����]
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.units_sold * price;
			} else {
				cout << total.bookNo << " " << total.units_sold
					<< " " << total.revenue << " " << total.revenue / total.units_sold
					<< endl; //[ISBN��] [�۳�����] [���۶�] [ƽ���۸�]
				//total = trans;
				total.bookNo = trans.bookNo;
				total.revenue = trans.revenue;
				total.units_sold = trans.units_sold;
			}
		}
		//cout << total << endl;
		cout << total.bookNo << " " << total.units_sold
			<< " " << total.revenue << " " << total.revenue / total.units_sold
			<< endl;//[ISBN��] [�۳�����] [���۶�] [ƽ���۸�]
	} else {
		std::cerr << "No data?" << endl;
		return -1;
	}
	return 0;
}