#include "CInputHandler.h"
#include <iostream>

using namespace std;

int main()
{
	CInputHandler inputHandler(cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!inputHandler.command())
		{
			return 1;
		}
	}
	return 0;
}

