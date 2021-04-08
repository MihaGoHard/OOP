#include <iostream>
#include "CControl.h"

using namespace std;

int main()
{
	CControl control(cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!control.HandleCommand())
		{
			cout << "Unknown shape!\n";
		}
	}
	return 0;
    
}

