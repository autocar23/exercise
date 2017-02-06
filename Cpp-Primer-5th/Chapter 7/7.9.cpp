#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

struct Person
{
	std::string name() const { return this->_name; }
	std::string adress() const { return this->_adress; }
	std::string _name;
	std::string _adress;
};

std::istream& read(std::istream& in, Person &person)
{
	in >> person._name >> person._adress;
	return in;
}

std::ostream& print(std::ostream& out, const Person &person)
{
	out << person._name << " " << person._adress;
	return out;
}

int main()
{

}