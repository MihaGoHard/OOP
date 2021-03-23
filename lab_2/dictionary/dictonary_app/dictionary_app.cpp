#include <Windows.h>
#include <clocale>
#include "Parsing.h"
#include "DataFiles.h"
#include "ModifyByUser.h"

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	
	
	bool noFile = false;

	auto args = ParseArgs(argc, argv);
	if (!argc)
	{
		return 1;
	}

	Dictionary dictionary;

	ifstream input;
	if (!OpenInStream(input, *args))
	{
		noFile = true;
	}
	else if (!GetDictionaryFromFile(dictionary, input))// compare 2 nums 
	{
		return 1;
	}


	if (ModifyPrintDictionary(dictionary, cin, cout))
	{
		cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������. ��� ������ ������� ����� ������ ������";
		string userInput;
		cin >> userInput;

		if (userInput == "y" || userInput == "Y")
		{
			CheckFileSaveDictioanry(noFile, dictionary, *args, argv);
		}
	}
	
	return 0;
}
