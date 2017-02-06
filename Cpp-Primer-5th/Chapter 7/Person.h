#pragma once
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class Person
{
	friend std::istream& read(std::istream&, Person &);
	friend std::ostream& print(std::ostream&, const Person &);
public:
	Person(const std::string &name, const std::string &adress) :
		_name(name), _adress(adress) {}
	Person(const std::string &name) :
		_name(name), _adress("") { }
	std::string name() const { return _name; }
	std::string adress() const { return _adress; }
private:
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