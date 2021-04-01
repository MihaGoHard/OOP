#include "CCarControl.h"
#include "CarControlUtils.h"

using namespace std;

CCarControl::CCarControl(CCar& car, std::istream& input, std::ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "Info", [this](istream& strm) {
			   return PrintCarInfo();
		   } },
		  { "EngineOn", [this](istream& strm) {
			   return StartEngine();
		   } },
		  { "EngineOff", [this](istream& strm) {
			   return StopEngine();
		   } },
		  { "SetGear", [this](istream& strm) {
			   return SetGear(strm);
		   } },
		  { "SetSpeed", [this](istream& strm) {
			   return SetSpeed(strm);
		   } },
	  })
{
}

bool CCarControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}


bool CCarControl::PrintCarInfo()
{
	if (m_car.EngineIsTurnedOn())
	{
		m_output << "Engine: turned on\n";
	}
	else
	{
		m_output << "Engine: turned off\n";
	}
	
	m_output << "Speed: " << m_car.GetSpeed() << "\n";
	m_output << "Direction: " << DirectionToString(m_car.GetDirection()) << "\n";
	m_output << "Gear: " << GearToString(m_car.GetGear()) << "\n";
	return true;
}

bool CCarControl::StartEngine()
{
	if (m_car.StartEngine())
	{
		m_output << "Engine started successfully\n";
	}
	else
	{
		m_output << "Engine is already running\n";
	}
	return true;
}

bool CCarControl::StopEngine()
{
	if (m_car.StopEngine())
	{
		m_output << "Engine stoped successfully\n";
	}
	else
	{
		m_output << "Cant stop the engine\n";
	}

	return true;
}


bool CCarControl::SetGear(istream& args)
{
	string inputStr;
	args >> inputStr;
	Gear gear = Gear::Neutral;

	if (GetGearFromArg(inputStr, gear))
	{
		if (m_car.SetGear(gear))
		{
			m_output << GearToString(gear) << " gear is selected\n";
		}
		else
		{
			m_output << "gear didn`t change\n";
		} 
	}
	
	return true;
}


bool CCarControl::SetSpeed(istream& args)
{
	string inputStr;
	args >> inputStr;
	int inSpeed = 0;
	Direction direction = m_car.GetDirection();
	if (GetSpeedFromArg(inputStr, inSpeed, direction))
	{
		if (m_car.SetSpeed(inSpeed))
		{
			m_output << inSpeed << " speed is selected\n";
		}
		else
		{
			m_output << "speed didn`t change\n";
		}
	}

	return true;
}