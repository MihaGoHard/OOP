#pragma once
#include "CCarControl.h"

string DirectionToString(Direction direction);
string GearToString(Gear gear);
bool GetGearFromArg(string inputStr, Gear& gear);
bool GetSpeedFromArg(string inputStr, int& in_speed);