#include "CarUtils.h"
#include "CCar.h"
using namespace std;

bool InSpeedLimit(int speed, pair<int, int> limits)
{
	return (speed >= limits.first && speed <= limits.second);
}

bool GearInSpeedRange(Gear gear, int speed)
{
	switch (gear)
	{
	case Gear::Reverse:
		return (speed == zeroSpeed);

	case Gear::One:
		return InSpeedLimit(speed, oneSpeedLimits);

	case Gear::Two:
		return InSpeedLimit(speed, twoSpeedLimits);

	case Gear::Three:
		return InSpeedLimit(speed, threeSpeedLimits);
		
	case Gear::Four:
		return InSpeedLimit(speed, fourSpeedLimits);

	case Gear::Five:
		return InSpeedLimit(speed, fiveSpeedLimits);

	default:
		return true;
	}
}

bool IsRightGearDirection(Gear gear, int in_speed, int m_speed, Direction direction)
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
		return InSpeedLimit(in_speed, reverseSpeedLimits);

	default:
		return (GearInSpeedRange(gear, in_speed));
	}

	return true;
}