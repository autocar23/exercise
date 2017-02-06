#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

struct Person
{
	std::string name() const { return this->name; }
	std::string adress() const { return this->adress; }
	std::string name;
	std::string adress;
};

int main()
{

}