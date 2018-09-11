#include <iostream>
#include <string>
using std::cin;

class Sales_data {
	friend std::istream& read(std::istream& in, Sales_data &data);
public:
	//构造函数 1
	Sales_data(std::string s = " ") :bookNo(s) { }
	// 2
	Sales_data(const std::string &bookNo, const unsigned &units_sold, const double &price) :
		bookNo(bookNo), units_sold(units_sold), revenue(units_sold*price) {}
	//3
	Sales_data(std::istream &in) { read(in, *this); }
	// Ext 7.38 Sales_data(std::istream &in = cin) { read(in, *this); }
	// Ext 7.39 不合法，这样子会出现两个默认构造函数 
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data first_item(cin); //构造函数3， 所有数据成员的值由用户输入
int main()
{
	Sales_data next; //构造函数1 bookNo为空，units_sold = 0 revenue = 0.0
	Sales_data last("9-999-99999-9"); // 构造函数1 ，bookNo为9-999-99999-9，units_sold = 0 revenue = 0.0
}