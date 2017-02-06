#include <iostream>
#include <string>
using std::cin;

class Sales_data {
	friend std::istream& read(std::istream& in, Sales_data &data);
public:
	//���캯�� 1
	Sales_data(std::string s = " ") :bookNo(s) { }
	// 2
	Sales_data(const std::string &bookNo, const unsigned &units_sold, const double &price) :
		bookNo(bookNo), units_sold(units_sold), revenue(units_sold*price) {}
	//3
	Sales_data(std::istream &in) { read(in, *this); }
	// Ext 7.38 Sales_data(std::istream &in = cin) { read(in, *this); }
	// Ext 7.39 ���Ϸ��������ӻ��������Ĭ�Ϲ��캯�� 
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data first_item(cin); //���캯��3�� �������ݳ�Ա��ֵ���û�����
int main()
{
	Sales_data next; //���캯��1 bookNoΪ�գ�units_sold = 0 revenue = 0.0
	Sales_data last("9-999-99999-9"); // ���캯��1 ��bookNoΪ9-999-99999-9��units_sold = 0 revenue = 0.0
}