#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int i = 0, &r = i;
	auto a = r; //aΪ����
	//autoһ�����Զ���const�������ײ�const
	const int const_i = i, &cr = const_i;
	auto b = const_i; 
	auto c = cr; 
	auto d = &i; 

	auto e = &const_i; //�ײ�const
	const auto f = const_i;

	auto &g = const_i;//��������
	const auto &j = 42;
	auto k = const_i, &l = i;
	auto &m = const_i, *p = &const_i;
	return 0;
}