#include "CarControlUtils.h"

string DirectionToString(Direction direction)
{
	map<Direction, string> directionTitles = {
		{ Direction::Back, "back" },
		{ Direction::Forward, "forward" },
		{ Direction::OnPlace, "on place" }
	};

	return directionTitles[direction];
}

string GearToString(Gear gear)
{
	map<Gear, string> gearTitles = {
		{ Gear::Reverse, "reverse" },
		{ Gear::Neutral, "neutral" },
		{ Gear::One, "first" },
		{ Gear::Two, "second" },
		{ Gear::Three, "third" },
		{ Gear::Four, "fourth" },
		{ Gear::Five, "fifth" },
	};

	return gearTitles[gear];
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

	map<int, Gear> gearTitles = {
		{ -1, Gear::Reverse },
		{ 0, Gear::Neutral },
		{ 1, Gear::One },
		{ 2, Gear::Two },
		{ 3, Gear::Three },
		{ 4, Gear::Four },
		{ 5, Gear::Five },
	};

	if (gearTitles.find(inputNum) == gearTitles.end())
	{
		cout << "incorrect gear number\n";
		return false;
	}

	gear = gearTitles[inputNum];

	return true;
}

bool GetSpeedFromArg(string inputStr, int& speed)
{
	if (!GetNumberFromStr(inputStr, speed))
	{
		return false;
	};
	if (speed < zeroSpeed)
	{
		cout << "The speed cannot be negative\n";
		return false;
	}
	return true;
}
