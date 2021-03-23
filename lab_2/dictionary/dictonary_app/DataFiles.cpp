#include "DataFiles.h"
#include "Parsing.h"

using namespace std;

bool OpenInStream(ifstream& input, Args& args)
{
	input.open(args.fileName);
	if (!input.is_open())
	{
		cout << "file not opened\n";
		return false;
	}

	return true;
}

bool OpenOutStream(ofstream& output, Args& args)
{
	output.open(args.fileName);
	if (!output.is_open())
	{
		cout << "Faild to open '" << args.fileName << "' for writing\n";
		return false;
	};
}


bool GetDictionaryFromFile(Dictionary& dictionary, ifstream& input)
{
	string line;
	while (getline(input, line))
	{
		DictionaryElem dictionaryElem = ParseLine(line);
		dictionary.insert(dictionaryElem);
	}
	return true;
}


void PutDictionaryToFile(Dictionary dictionary, ostream& output)
{
	for (auto [first, second] : dictionary)
	{
		string mapLine = "[" + first + "] " + second;
		for (auto ch : mapLine)
		{
			output.put(ch);
		}
		output.put('\n');
	}
}


bool CheckFileSaveDictioanry(bool noFile, const Dictionary& dictionary, Args &args, char* argv[])
{
	ofstream output;

	if (noFile)
	{
		ofstream newOfs(argv[1]);
	}

	if (!OpenOutStream(output, args))
	{
		return false;
	}

	PutDictionaryToFile(dictionary, output);
	
	return true;
}