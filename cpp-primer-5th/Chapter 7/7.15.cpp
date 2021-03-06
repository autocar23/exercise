#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

struct Person
{
	Person(const std::string &name, const std::string &adress):
			_name(name), _adress(adress){}
	std::string name() const { return _name; }
	std::string adress() const { return _adress; }
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