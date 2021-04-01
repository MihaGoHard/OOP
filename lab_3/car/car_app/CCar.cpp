#include "CCar.h"
#include "CarUtils.h"
using namespace std;

CCar::CCar()
{
}

bool CCar::StartEngine()
{
	if (!m_engineIsTurnedOn)
	{
		m_engineIsTurnedOn = true;
		return true;
	}
	return false;
}

bool CCar::StopEngine()
{
	if (m_engineIsTurnedOn && (m_gear == Gear::Neutral) && (m_speed == 0))
	{
		m_engineIsTurnedOn = false;
		return true;
	}
	return false;
}

bool CCar::EngineIsTurnedOn() const
{
	return m_engineIsTurnedOn;
}


bool CCar::SetGear(Gear gear)
{
	if (m_engineIsTurnedOn && GearInSpeedRange(gear, m_speed))
	{
		m_gear = gear;
		return true;
	}
	return false;
}

Gear CCar::GetGear() const
{
	return m_gear;
}


bool CCar::SetSpeed(int module_speed)
{
	int speed = module_speed;
	int negativeIndex = -1;
	Direction direction = CCar::GetDirection();
	if (direction == Direction::Back || (direction == Direction::OnPlace && m_gear == Gear::Reverse))
	{
		speed = speed * negativeIndex;
	}

	if (m_engineIsTurnedOn && IsRightGearDirection(m_gear, speed, m_speed, GetDirection()))
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
	if (m_speed < 0)
	{
		return Direction::Back;
	}
	if (m_speed > 0)
	{
		return Direction::Forward;
	}
	return Direction::OnPlace;
}
