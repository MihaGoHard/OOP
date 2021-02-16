#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
#include <optional>


bool inputIsNotNumber(std::string inputStr) 
{
	bool isNotNumber = false;
	for (int i = 0; i < inputStr.length(); ++i)
	{
		if (!isdigit(inputStr[i]))
		{
			isNotNumber = true;
		}
	}
	return isNotNumber;
}


struct Args
{
	unsigned int inputNum;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments number \n";
		std::cout << "Usage: CopyFile.exe <input file name> <output file name>";
		return std::nullopt;
	}
	
	std::string inputStr = argv[1];

	if (inputIsNotNumber(inputStr))
	{
		std::cout << "Invalid input \n";
		std::cout << "Usage: CopyFile.exe <number> ";
		return std::nullopt;
	}

	unsigned int maxInt = std::numeric_limits<unsigned int>::max();
	std::string maxIntString = std::to_string(maxInt);

	if (inputStr > maxIntString)
	{
		std::cout << "Invalid input number \n";
		std::cout << "Usage: input number is below, than max unsigned int";
		return std::nullopt;
	}

	Args args;
	args.inputNum = std::stoul(inputStr, nullptr, 0);
	return args;
}




int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!argc)
	{
		return 1;
	}

	unsigned int inputNum = args->inputNum;

	std::cout << inputNum << std::endl;


	unsigned int decNum = inputNum;
	int binIndex = 2;
	int remain = 0;
	int quotient = 0; 
	int digitNum = 1;

	while (quotient != 1)
	{
		quotient = decNum / binIndex;
		remain = decNum - quotient * binIndex;
		decNum = quotient;
		++digitNum;
	}
	
	decNum = inputNum;

	std::vector<int> digitVector = {};

	for (int i = 0; i < digitNum; i++)
	{
		digitVector.push_back(decNum & 1);
		decNum >>= 1;
	}

	for (int i = digitNum - 1; i >= 0; --i)
	{
		std::cout << digitVector[i] << " ";
	}
	
	std::cout << std::endl;
}
