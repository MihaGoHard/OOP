#include <fstream>
#include <iostream>
#include <optional>
#include <string>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[]) // ���������� ���� ������ � ���������� ���� nullopt
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments number \n";
		std::cout << "Usage: CopyFile.exe <input file name> <output file name>";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

void CopyStreams(std::ifstream& input, std::ofstream& output)
{
	char ch;
	while (input.get(ch))
	{
		if (!output.put(ch))
		{
			break; // ����� �� �����
		}
	}
}

bool OpenStreams(std::ifstream& input, std::ofstream &output, Args &args)
{
	input.open(args.inputFileName);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" << args.inputFileName << "' for reading\n";
		return false;
	}

	output.open(args.outputFileName);
	if (!output.is_open())
	{
		std::cout << "Faild to open '" << args.outputFileName << "' for writing\n";
		return false;
	}

	return true;
}

bool CopyIsSucced(std::ifstream& input, std::ofstream& output)
{
	if (input.bad())
	{
		std::cout << "Faild to read data from input file\n";
		return false;
	}

	if (!output.flush()) // connect with buffer and disc
	{
		std::cout << "faild to write data to otput file\n";
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!argc)
	{
		return 1;
	}

	std::ifstream input;			 
	std::ofstream output;

	if(!OpenStreams(input, output, *args))
	{
		return 1;
	}

	CopyStreams(input, output);

	if (!CopyIsSucced(input, output))
	{
		return 1;
	}

	return 0;
}
