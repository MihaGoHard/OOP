#pragma once
#include "CCar.h"
#include <iostream>

bool gearInSpeedRange(Gear gear, int speed);
bool isRightGearDirection(Gear gear, int in_speed, int m_speed, Direction direction);