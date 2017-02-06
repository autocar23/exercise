#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Date {
public:
	Date();
	Date(int year, int month, int day);
	Date(int year, int month, int day, int hour, int minute, int second);
	Date(std::istream &is);
	Date(int year, int daysOfTheYear);
private:
	int _year = 0;
	int _month = 0;
	int _day = 0;
	int _hour = 0;
	int _minute = 0;
	int _second = 0;
};

Date::Date() :Date(0, 0, 0)
{

}

Date::Date(int year, int month, int day) : Date(year, month, day, 0, 0, 0)
{

}

Date::Date(std::istream &is) : Date()
{
	cin >> _hour >> _minute >> _second;
}

Date::Date(int year, int month, int day, int hour, int minute, int second) :
	_year(year), _month(month), _day(day), _hour(hour), _second(second)
{

}

Date::Date(int year, int daysOfTheYear)
{
	//..
}
