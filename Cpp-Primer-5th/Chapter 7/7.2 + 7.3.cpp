#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

struct Sales_data
{
	Sales_data& combine(const Sales_data &rhs);
	std::string isbn() const { return bookNo; }
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data total;
	double price = 0;
	if (cin >> total.bookNo >> total.units_sold >> price) {  //[ISBN号] [售出册数] [单价]
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				cout << total.bookNo << " " << total.units_sold
					<< " " << total.revenue << " " << total.avg_price()
					<< endl; //[ISBN号] [售出册数] [销售额] [平均价格]
							 //total = trans;
				total.bookNo = trans.bookNo;
				total.revenue = trans.revenue;
				total.units_sold = trans.units_sold;
			}
		}
		//cout << total << endl;
		cout << total.bookNo << " " << total.units_sold
			<< " " << total.revenue << " " << total.avg_price()
			<< endl;//[ISBN号] [售出册数] [销售额] [平均价格]
	} else {
		std::cerr << "No data?" << endl;
		return -1;
	}
	return 0;
}

Sales_data & Sales_data::combine(const Sales_data & rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const
{
	return revenue / units_sold;
}
