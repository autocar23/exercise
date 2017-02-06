#include <iostream>
#include "Screen.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Window_mgr myWindow;
	myWindow.get(0).set('$');
	myWindow.clear(0);
	myWindow.get(0).display(cout);
	return 0;
}