#pragma once

#include <map>
#include <string>

using namespace std;

enum class Direction
{
	Forward,
	Back,
	OnPlace
};

enum class Gear
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
	Gear GetGear() const;

	int GetSpeed() const;
	bool SetSpeed(int speed);

	Direction GetDirection() const;

private:
	bool m_engineIsTurnedOn = false;
	Gear m_gear = Gear::Neutral;

	int m_speed = 0;
};


//show (-speed) +

//getGear const +

//class scoped enum +, 

//map (at, find) +  

//m_name  smallLetter +

//unsigned speed on reverse +

//GetDirection +

//zeroSpeed delete +

//вывод заменить на if else +

//types
