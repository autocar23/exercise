#include <iostream> //来自标准库的头文件用<>包围
#include "Sales_item.h" //不属于标准库的头文件用""包围
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_item item;
	while (cin >> item) { //[ISBN号] [售出册数] [销售价格]
		cout << item;  
	}
	return 0;
}