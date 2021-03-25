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
	m_output << "Engine: " << ((m_car.EngineIsTurnedOn()) ? ("turned on\n") : ("turned off\n"));
	m_output << "Speed: " << m_car.GetSpeed() << "\n";
	m_output << "Direction: " << DirectionToString(m_car.GetDirection()) << "\n";
	m_output << "Gear: " << GearToString(m_car.GetGear()) << "\n";
	return true;
}

bool CCarControl::StartEngine()
{
	m_car.StartEngine() ? m_output << "Engine started successfully\n" : m_output << "Engine is already running\n";

	return true;
}

bool CCarControl::StopEngine()
{
	m_car.StopEngine() ? m_output << "Engine stoped successfully\n" : m_output << "Cant stop the engine\n";

	return true;
}


bool CCarControl::SetGear(istream& args)
{
	string inputStr;
	args >> inputStr;
	Gear gear;
	if (GetGearFromArg(inputStr, gear))
	{
		m_car.SetGear(gear) ? (m_output << gear << " gear is selected\n") : (m_output << "gear didn`t change\n"); 
	}
	
	return true;
}


bool CCarControl::SetSpeed(istream& args)
{
	string inputStr;
	args >> inputStr;
	int inSpeed = 0;
	if (GetSpeedFromArg(inputStr, inSpeed))
	{
		m_car.SetSpeed(inSpeed) ? (m_output << inSpeed << " speed is selected\n") : (m_output << "speed didn`t change\n");
	}

	return true;
}