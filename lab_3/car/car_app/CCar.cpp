#include "CCar.h"
#include "CarUtils.h"
using namespace std;

CCar::CCar()
{
}

bool CCar::StartEngine()
{
	if (!m_EngineIsTurnedOn)
	{
		m_EngineIsTurnedOn = true;
		return true;
	}
	return false;
}

bool CCar::StopEngine()
{
	if (m_EngineIsTurnedOn && (m_gear == Gear::Neutral) && (m_speed == zeroSpeed))
	{
		m_EngineIsTurnedOn = false;
		return true;
	}
	return false;
}

bool CCar::EngineIsTurnedOn() const
{
	return m_EngineIsTurnedOn;
}


bool CCar::SetGear(Gear gear)
{
	if (m_EngineIsTurnedOn && gearInSpeedRange(gear, m_speed))
	{
		m_gear = gear;
		return true;
	}
	return false;
}

Gear CCar::GetGear()
{
	return m_gear;
}


int CCar::SetSpeed(int module_speed)
{
	int speed = module_speed;
	int negativeIndex = -1;
	Direction direction = CCar::GetDirection();
	if (direction == Direction::Back || (direction == Direction::OnPlace && m_gear == Gear::Reverse))
	{
		speed = speed * negativeIndex;
	}

	if (m_EngineIsTurnedOn && isRightGearDirection(m_gear, speed, m_speed, GetDirection()))
	{
		m_speed = speed;
		return true;
	}
	return false;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

Direction CCar::GetDirection() const
{
	if (m_speed < zeroSpeed)
	{
		return Direction::Back;
	}
	if (m_speed > zeroSpeed)
	{
		return Direction::Forward;
	}
	return Direction::OnPlace;
}
