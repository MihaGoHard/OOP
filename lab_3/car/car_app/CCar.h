#pragma once

#include <map>
#include <string>

using namespace std;

enum Direction
{
	Forward,
	Back,
	OnPlace
};


enum Gear
{
	Reverse = -1,
	Neutral = 0,
	One = 1,
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5
};

const pair<int, int> reverseSpeedLimits = { -20, 0 };
const int zeroSpeed = 0;
const pair<int, int> oneSpeedLimits = { 0, 30 };
const pair<int, int> twoSpeedLimits = { 20, 50 };
const pair<int, int> threeSpeedLimits = { 30, 60 };
const pair<int, int> fourSpeedLimits = { 40, 90 };
const pair<int, int> fiveSpeedLimits = { 50, 150 };

class CCar
{
public:
	CCar();
	~CCar() = default;

	bool StartEngine();
	bool StopEngine();
	bool EngineIsTurnedOn() const;

	bool SetGear(Gear gear);
	Gear GetGear();

	int GetSpeed() const;
	int SetSpeed(int speed);

	Direction GetDirection() const;

private:
	bool m_EngineIsTurnedOn = false;
	Gear m_gear = Gear::Neutral;

	int m_speed = 0;
};
