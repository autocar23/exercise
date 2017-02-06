#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
class Sales_data
{
	friend Sales_data add(const Sales_data &l, const Sales_data &r);
	friend std::istream& read(std::istream& in, Sales_data &data);
	friend std::ostream& print(std::ostream &out, Sales_data &data);
public:
	Sales_data(const std::string &bookNo, const unsigned &units_sold, const double &price) :
		bookNo(bookNo), units_sold(units_sold), revenue(units_sold*price) 
		{ cout << "Sales_data(string, unsigned, double)" << endl; }
	Sales_data() : Sales_data("", 0, 0) 
		{ cout << "Sales_data()" << endl; }
	Sales_data(std::string s) :Sales_data(s, 0, 0) 
		{ cout << "Sales_data(string)" <<endl; }
	Sales_data(std::istream &in) :Sales_data() 
	{
		read(in, *this);
		cout << "Sales_data(istream)" << endl;
	}

	Sales_data& combine(const Sales_data &rhs);
	std::string isbn() const { return bookNo; }
private:
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

inline double Sales_data::avg_price() const
{
	return revenue / units_sold;
}

int main()
{
	Sales_data data1;
	cout << endl;
	Sales_data data2(cin);
	cout << endl;
	Sales_data("9-999-9999-9", 5, 2);
	//委托构造函数的调用类似stack
	return 0;
}