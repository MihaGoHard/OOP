#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments number \n";
		std::cout << "Usage: CopyFile.exe <input file name> <output file name>";
		return 1;
	}

	std::ifstream input;
	input.open(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Faild to open '" << argv[1] << "' for reading\n";
		return 1;
	}

	std::ofstream output;
	output.open(argv[2]);
	if (!output.is_open())
	{
		std::cout << "Faild to open '" << argv[2] << "' for writing\n";
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

	if (!output.flush())
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
