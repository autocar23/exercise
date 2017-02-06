//7.43
class NoDefault {
public:
	NoDefault(int){}
};

class C {
public:
	C() :x(0) {};
	NoDefault x;
};
//7.44
//不合法，vector<NoDefault> vec(10) 对于每个容器内的值都会调用不存在的NoDefault类的默认构造函数
//7.44
//合法，因为C存在默认构造函数
//7.45
//a.错误，并不必须要提供默认构造函数
//b.正确
//c.错误，如果一个类提供了构造函数，则最好也应提供默认构造函数
//d.错误，编译器无法为任何类都合成默认构造函数