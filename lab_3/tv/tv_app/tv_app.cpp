#include "CTVSet.h"
#include "RemoteControl.h"

using namespace std;

int main()
{
	CTVSet tv;
	CRemoteControl tvControl(tv, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!tvControl.HandleCommand())
		{
			cout << "Unknown command!\n";
		}
	}
	return 0;
}
