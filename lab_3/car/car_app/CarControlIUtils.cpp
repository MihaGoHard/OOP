#include "CarControlUtils.h"

string DirectionToString(Direction direction)
{
	return directionTitles.at(direction);
}

string GearToString(Gear gear)
{
	return gearTitles.at(gear);
}

bool GetNumberFromStr(string inputStr, int& inputNum)
{
	try
	{
		inputNum = stoi(inputStr);
	}
	catch (exception& exception)
	{
		cout << "incorrect argument\n";
		cerr << exception.what() << "\n";
		return false;
	}

	return true;
}

bool GetGearFromArg(string inputStr, Gear& gear)
{
	int inputNum = 100;
	if (!GetNumberFromStr(inputStr, inputNum))
	{
		return false;
	}

	if (intGear.find(inputNum) == intGear.end())
	{
		cout << "incorrect gear number\n";
		return false;
	}

	gear = intGear.at(inputNum);

	return true;
}

bool GetSpeedFromArg(string inputStr, int& speed, Direction direction)
{
	if (!GetNumberFromStr(inputStr, speed))
	{
		return false;
	}
	if (speed < 0 && direction != Direction::Back)
	{
		cout << "The speed cannot be negative\n";
		return false;
	}
	speed = unsigned(speed);
	return true;
}
