#include <string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()): // ����Ĭ��ֵ= =��
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr&);
private:
	std::string *ps;
	int i;
};

HasPtr::HasPtr(const HasPtr& hasptr):
	ps(new std::string(*hasptr.ps)), i(hasptr.i) { }

int main()
{
	return 0;
}