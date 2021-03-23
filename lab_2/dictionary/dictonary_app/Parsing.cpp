#include "Parsing.h"

using namespace std;

DictionaryElem ParseLine(const string& line)
{
	DictionaryElem dictionaryElem;

	int wordCharOffest = 1;
	int translateCharOffest = 3;

	int posOpen = line.find("[") + wordCharOffest;
	int posClose = line.find("]") - wordCharOffest;
	int posTranslate = posClose + translateCharOffest;

	dictionaryElem.first = line.substr(posOpen, posClose);

	dictionaryElem.second = line.substr(posTranslate, line.length());

	return dictionaryElem;
}

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments number \n";
		cout << "Usage: CopyFile.exe <input file name> ";
		return std::nullopt;
	}
	Args args;
	args.fileName = argv[1];
	return args;
}