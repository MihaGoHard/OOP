#include "parse_print.h"
#include <string>

using namespace std;

uint32_t ParseBytes(const std::string& inputStr)
{
	int maxValue = 100000000;
	auto value = stoull(inputStr);
	if (value < 0 || value > maxValue)
	{
		throw std::out_of_range("Usage: prime_numbers_app.exe (<unsigned int number> <= 100000000)");
	}
	return static_cast<uint32_t>(value);
}

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments number: " << argc - 1 << "\n";
		std::cout << "Usage: prime_numbers_app.exe (<unsigned int number> <= 100000000) \n";
		return std::nullopt;
	}

	std::string inputStr = argv[1];

	Args args;

	try
	{
		args.inputNum = ParseBytes(inputStr);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return std::nullopt;
	}

	return args;
}

void PrintSet(set<int>& numsSet)
{
	for (auto it = numsSet.begin(); it != numsSet.end(); ++it)
	{
		cout << *it << " ";
	}
}
