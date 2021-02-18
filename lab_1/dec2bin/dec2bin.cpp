
#include <iostream>
#include <optional>
#include <string>
#include <typeinfo>
#include <vector>
#include "dec2bin.h"

bool InputIsNotDecNumber(std::string inputStr)
{
	bool isNotDecNumber = false;
	int strLength = inputStr.length();
	if (inputStr[0] == '0' && strLength != 1)
	{
		isNotDecNumber = true;
	}
	for (int i = 0; i < strLength && !isNotDecNumber; ++i)
	{
		if (!isdigit(inputStr[i]))
		{
			isNotDecNumber = true;
		}
	}
	return isNotDecNumber;
}

struct Args
{
	unsigned int inputNum;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments number: " << argc - 1 << "\n";
		std::cout << "Usage: CopyFile.exe <number>\n";
		return std::nullopt;
	}

	std::string inputStr = argv[1];

	if (InputIsNotDecNumber(inputStr))
	{
		std::cout << "Invalid input\n";
		std::cout << "Usage: CopyFile.exe <decimal number>\n";
		return std::nullopt;
	}

	unsigned int maxInt = std::numeric_limits<unsigned int>::max();
	std::string maxIntString = std::to_string(maxInt);

	if (inputStr > maxIntString)
	{
		std::cout << "Invalid input number \n";
		std::cout << "Usage: input number is below, than max unsigned int\n";
		return std::nullopt;
	}

	Args args;
	args.inputNum = std::stoul(inputStr, nullptr, 0);
	return args;
}

void GetBinPerfomance(int digitsCount, unsigned int decNum)
{
	if (decNum == 0)
	{
		std::cout << 0;
	}
	for (int i = digitsCount - 1; i >= 0 ; --i)
	{
		if (decNum & (1 << i))
		{
			std::cout << 1;
		}
		else
		{
			std::cout << 0;
		}
	}
	std::cout << "\n";
}

void GetDigitsCount(unsigned int decNum, int& digitsCount)
{
	for (unsigned int decNumCount = decNum; decNumCount;)
	{
		decNumCount >>= 1;
		++digitsCount;
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		return 1;
	}

	unsigned int decNum = args->inputNum;

	int digitsCount = 0;

	GetDigitsCount(decNum, digitsCount);

	GetBinPerfomance(digitsCount, decNum);

	return 0;
}
