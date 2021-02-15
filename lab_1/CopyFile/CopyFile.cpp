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
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}


int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!argc)
	{
		std::cout << "Invalid arguments number \n";
		std::cout << "Usage: CopyFile.exe <input file name> <output file name>";
		return 1;
	}

	std::ifstream input;
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

	char ch;
	while (input.get(ch))
	{
		if (!output.put(ch))
		{
			break;  // выход из цикла
		}
	}

	if (input.bad())   
	{
		std::cout << "Faild to read data from input file\n"; 
		return 1;
	}

	if (!output.flush())  // connect with buffer and disc 
	{
		std::cout << "faild to write data to otput file\n";
		return 1;
	}

	/*std::cout << argc << "\n";
    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    }*/
	return 0;
}
