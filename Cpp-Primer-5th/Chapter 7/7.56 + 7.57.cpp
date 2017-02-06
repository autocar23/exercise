//7.56
//类的静态成员是类的成员，独立于类对象的存在，创建类的对象时不会为类的静态成员分配内存空间。
//7.57
#include "Person.h"
class Account {
public:
	Account(const std::string &name):_owner(name) { }
	Account(const std::string &name, const double &amount):
		_owner(name), _amount(amount) { }
	Account(const std::string &name, const double &amount, const int &type):
		_owner(name), _amount(amount), _type(type) { }
	void calculate();
	double amount();
	Person owner();
	Account& setAmount(const double&);
	Account& setType(const int&);
private:
	static double _rate;
	unsigned int _type = 0;
	Person _owner;
	double _amount = 0;
};

void Account::calculate()
{
	_amount += _amount * _rate;
}

double Account::amount()
{
	return _amount;
}

Account& Account::setAmount(const double &amount)
{
	_amount = amount;
	return *this;
}

Account& Account::setType(const int &type)
{
	_type = type;
	return *this;
}

Person Account::owner()
{
	return _owner;
}