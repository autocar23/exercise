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

Sales_data add(const Sales_data &l, const Sales_data &r)
{
	Sales_data ret = l;
	ret.combine(r);
	return ret;
}

std::istream& read(std::istream& in, Sales_data &data)
{
	double price;
	in >> data.bookNo >> data.units_sold >> price;
	data.revenue = data.units_sold * price;
	return in;
}

std::ostream& print(std::ostream &out, Sales_data &data)
{
	out << data.isbn() << " " << data.units_sold
		<< " " << data.revenue << " " << data.avg_price();
	return out;
}

int main()
{
	Sales_data total;
	double price = 0;
	if (read(cin, total)) {  //[ISBN号] [售出册数] [单价]
		Sales_data trans;
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				print(cout, total); //[ISBN号] [售出册数] [销售额] [平均价格]
				cout << endl;
				total.bookNo = trans.bookNo;
				total.revenue = trans.revenue;
				total.units_sold = trans.units_sold;
			}
		}
		//cout << total << endl;
		print(cout, total);
		cout << endl;//[ISBN号] [售出册数] [销售额] [平均价格]
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
