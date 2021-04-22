#include <iostream>
#include "CControl.h"

using namespace std;

int main()
{
	CControl control(cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		control.HandleCommand();
	}
	control.PrintShapeMinPerimeter();
	control.PrintShapeMaxArea();
	return 0;   
}

