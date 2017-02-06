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

