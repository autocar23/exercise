#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

struct Sales_data;
std::istream& read(std::istream& in, Sales_data &data);

struct Sales_data
{
	Sales_data(const std::string &bookNo, const unsigned &units_sold, const double &price):
				bookNo(bookNo), units_sold(units_sold), revenue(units_sold*price){}
	Sales_data(const std::string &bookNo) :bookNo(bookNo) {}
	Sales_data(std::istream &in) 
	{
		read(in, *this);
	}
	Sales_data(){}
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
	Sales_data data1; //Sales_data()
	Sales_data data2("1-5545-567"); //Sales_data(const std::string &bookNo)
	Sales_data data3(cin); //Sales_data(std::istream &in) 
	// Sales_data(const std::string &bookNo, const unsigned &units_sold, const double &price)
	Sales_data data4("1-5545-567", 2, 59.9); 	
	return 0;
}