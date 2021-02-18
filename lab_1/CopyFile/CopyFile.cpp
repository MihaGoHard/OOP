#include <fstream>
#include <iostream>
#include <optional>
#include <string>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[]) // возвращает либо объект с аргуметами либо nullopt
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
			break; // выход из цикла
		}
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!argc)
	{
		return 1;
	}

	std::ifstream input;			 // открыть поток input
	input.open(args->inputFileName); // через стрелку обращение к значению объекта(убедиться, что объект не пуст)
	if (!input.is_open())
	{
		std::cout << "Faild to open '" << args->inputFileName << "' for reading\n";
		return 1;
	}

	std::ofstream output;

	output.open(args->outputFileName);
	if (!output.is_open())
	{
		std::cout << "Faild to open '" << args->outputFileName << "' for writing\n";
		return 1;
	}

	CopyStreams(input, output);

	if (input.bad())
	{
		std::cout << "Faild to read data from input file\n";
		return 1;
	}

	if (!output.flush()) // connect with buffer and disc
	{
		std::cout << "faild to write data to otput file\n";
		return 1;
	}

	return 0;
}
