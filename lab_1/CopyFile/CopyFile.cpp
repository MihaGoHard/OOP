#include <iostream>
#include <fstream>

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

	char ch;
	while (input.get(ch))
	{
		std::cout.put(ch);
	}

	/*std::cout << argc << "\n";
    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    }*/
    return 0;
}
