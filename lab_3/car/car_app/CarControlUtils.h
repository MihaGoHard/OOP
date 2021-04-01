#pragma once
#include "CCarControl.h"


const map<Direction, string> directionTitles = {
	{ Direction::Back, "back" },
	{ Direction::Forward, "forward" },
	{ Direction::OnPlace, "on place" }
};

const map<Gear, string> gearTitles = {
	{ Gear::Reverse, "reverse" },
	{ Gear::Neutral, "neutral" },
	{ Gear::One, "first" },
	{ Gear::Two, "second" },
	{ Gear::Three, "third" },
	{ Gear::Four, "fourth" },
	{ Gear::Five, "fifth" },
};

const map<int, Gear> intGear = {
	{ -1, Gear::Reverse },
	{ 0, Gear::Neutral },
	{ 1, Gear::One },
	{ 2, Gear::Two },
	{ 3, Gear::Three },
	{ 4, Gear::Four },
	{ 5, Gear::Five },
};

string DirectionToString(Direction direction);
string GearToString(Gear gear);
bool GetGearFromArg(string inputStr, Gear& gear);
bool GetSpeedFromArg(string inputStr, int& speed, Direction direction);