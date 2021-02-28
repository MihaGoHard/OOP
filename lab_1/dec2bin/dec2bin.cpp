#include <iostream>
#include <cassert>
#include <optional>
#include <string>
#include <typeinfo>


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

uint32_t ParseBytes(const std::string& inputStr)
{
	auto value = std::stoull(inputStr);
	if (value < 0 || value > UINT32_MAX)
	{
		throw std::out_of_range("Invalid input number \nUsage: input number is unsigned int");
	}
	return static_cast<uint32_t>(value);
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



void PrintNumberInBinaryNotation(unsigned int inputNumber)
{
	int bitsQuantity = 31;
	bool printDigits = false;
	
	for (int bitNumber = bitsQuantity; bitNumber >= 0; --bitNumber)
	{
		if (((inputNumber >> bitNumber) != 0) || (!printDigits && (bitNumber == 0)))
		{
			printDigits = true;
		}
		if (printDigits)
		{
			std::cout << ((inputNumber >> bitNumber) & 1);
		}
	}

	std::cout << "\n";
}



int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		return 1;
	}

	unsigned int inputNumber = args->inputNum;
	PrintNumberInBinaryNotation(inputNumber);
	return 0;
}
