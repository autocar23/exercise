#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int i = 0, &r = i;
	auto a = r; //a为整数
	//auto一般会忽略顶层const，保留底层const
	const int const_i = i, &cr = const_i;
	auto b = const_i; 
	auto c = cr; 
	auto d = &i; 

	auto e = &const_i; //底层const
	const auto f = const_i;

	auto &g = const_i;//常量引用
	const auto &j = 42;
	auto k = const_i, &l = i;
	auto &m = const_i, *p = &const_i;
	return 0;
}