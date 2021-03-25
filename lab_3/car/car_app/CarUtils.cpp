#include "CarUtils.h"
#include "CCar.h"
using namespace std;

bool inSpeedLimit(int speed, pair<int, int> limits)
{
	return (speed >= limits.first && speed <= limits.second);
}

bool gearInSpeedRange(Gear gear, int speed)
{
	switch (gear)
	{
	case Gear::Reverse:
		return (speed == zeroSpeed);

	case Gear::One:
		return inSpeedLimit(speed, oneSpeedLimits);

	case Gear::Two:
		return inSpeedLimit(speed, twoSpeedLimits);

	case Gear::Three:
		return inSpeedLimit(speed, threeSpeedLimits);
		
	case Gear::Four:
		return inSpeedLimit(speed, fourSpeedLimits);

	case Gear::Five:
		return inSpeedLimit(speed, fiveSpeedLimits);

	default:
		return true;
	}
}

bool isRightGearDirection(Gear gear, int in_speed, int m_speed, Direction direction)
{
	switch (gear)
	{
	case Gear::Neutral:
		switch (direction)
		{
		case Direction::Back:
			return (in_speed >= m_speed && in_speed <= zeroSpeed);
		case Direction::Forward: 
			return (in_speed <= m_speed && in_speed >= zeroSpeed);
		default:
			return false;
		}

	case Gear::Reverse:
		return inSpeedLimit(in_speed, reverseSpeedLimits);

	default:
		return (gearInSpeedRange(gear, in_speed));
	}

	return true;
}