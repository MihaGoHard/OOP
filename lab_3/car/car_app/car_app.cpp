#include "CCarControl.h"
#include "CCar.h"

using namespace std;

int main()
{
	CCar car;
	CCarControl carControl(car, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!carControl.HandleCommand())
		{
			cout << "Unknown command!\n";
		}
	}
	return 0;
}

