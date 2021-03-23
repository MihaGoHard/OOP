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
	outStream << "Неизвестное слово  \"" << dictionaryElem.first << "\". Введите перевод или пустую строку для отказа.\n>";
	getline(inStream, dictionaryElem.second);
	if (dictionaryElem.second.empty())
	{
		outStream << "Слово \"" << dictionaryElem.first << "\" проигнорировано\n";
	}
	else
	{
		dictionary.insert(dictionaryElem);
		outStream << "Слово \"" << dictionaryElem.first << "\" сохранено в словаре как \"" << dictionaryElem.second << "\".\n";
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
