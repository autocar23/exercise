#include <iostream> //���Ա�׼���ͷ�ļ���<>��Χ
#include "Sales_item.h" //�����ڱ�׼���ͷ�ļ���""��Χ
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_item item;
	while (cin >> item) { //[ISBN��] [�۳�����] [���ۼ۸�]
		cout << item;  
	}
	return 0;
}