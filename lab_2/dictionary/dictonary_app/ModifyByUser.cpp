#include "ModifyByUser.h"

using namespace std;

void PrintTranslation(const string& translation)
{
	for (auto str : translation)
	{
		cout << str;
	}
	cout << "\n";
}


void GetUserAnswerChangeDictionary(Dictionary& dictionary, DictionaryElem& dictionaryElem, istream& inStream, ostream& outStream, bool& modified)
{
	outStream << "����������� �����  \"" << dictionaryElem.first << "\". ������� ������� ��� ������ ������ ��� ������.\n>";
	getline(inStream, dictionaryElem.second);
	if (dictionaryElem.second.empty())
	{
		outStream << "����� \"" << dictionaryElem.first << "\" ���������������\n";
	}
	else
	{
		dictionary.insert(dictionaryElem);
		outStream << "����� \"" << dictionaryElem.first << "\" ��������� � ������� ��� \"" << dictionaryElem.second << "\".\n";
		modified = true;
	}
}


void DialogWithUser(Dictionary& dictionary, DictionaryElem& dictionaryElem, istream& inStream, ostream& outStream, bool& modified)
{
	outStream << "\n>";
	getline(inStream, dictionaryElem.first);

	if (dictionaryElem.first != "...")
	{

		if (dictionary.find(dictionaryElem.first) != dictionary.end())
		{
			PrintTranslation(dictionary[dictionaryElem.first]);
		}
		else
		{
			GetUserAnswerChangeDictionary(dictionary, dictionaryElem, inStream, outStream, modified);
		}
	};
}

bool ModifyPrintDictionary(Dictionary& dictionary, istream& inStream, ostream& outStream)
{
	DictionaryElem dictionaryElem;
	bool modified = false;
	const string ejectStr = "...";

	while (dictionaryElem.first != ejectStr)
	{
		DialogWithUser(dictionary, dictionaryElem, inStream, outStream, modified);
	}

	return modified;
}
