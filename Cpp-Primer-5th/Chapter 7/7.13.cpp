#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

struct Sales_data
{
	Sales_data(const std::string &bookNo, const unsigned &units_sold, const double &price) :
		bookNo(bookNo), units_sold(units_sold), revenue(units_sold*price) {}
	Sales_data(const std::string &bookNo) :bookNo(bookNo) {}
	Sales_data(std::istream &in)
	{
		read(in, *this);
	}
	Sales_data() {}
	Sales_data& combine(const Sales_data &rhs);
	std::string isbn() const { return bookNo; }
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data & Sales_data::combine(const Sales_data & rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

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

double Sales_data::avg_price() const
{
	return revenue / units_sold;
}


int main()
{
	Sales_data total(cin);
	if (!total.isbn().empty()) {
		std::istream &is = std::cin;
		while (is) {
			Sales_data trans(is);
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	} else {
		std::cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}