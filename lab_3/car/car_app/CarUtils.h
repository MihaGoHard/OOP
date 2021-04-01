#pragma once
#include "CCar.h"
#include <iostream>

bool GearInSpeedRange(Gear gear, int speed);
bool IsRightGearDirection(Gear gear, int in_speed, int m_speed, Direction direction);