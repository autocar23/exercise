struct X
{
	//错误，初始化列表初始化顺序为成员变量定义顺序，该操作为未定义的
	X (int i, int j):base(i), rem(base % j){ } 
	//正确方式
	X(int i, int j) :base(i), rem(i % j) { }
	int rem, base;
};