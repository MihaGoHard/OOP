#include "RemoteControl.h"

using namespace std;

CRemoteControl::CRemoteControl(CTVSet& tv, istream& input, ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "Info", [this](istream& strm) {
			   return Info();
		   } },
		  { "Switch On", [this](istream& strm) {
			   return SwitchOn();
		   } },
		  { "Switch Off", [this](istream& strm) {
			   return SwitchOff();
		   } },
		  { "Set channel", [this](istream& strm) {
			   return SetChannel(strm);
		   } },
		  { "Set previous channel", [this](istream& strm) {
			   return SetPreviousChannel();
		   } }
	  })
{
}



bool CRemoteControl::HandleCommand()
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


bool CRemoteControl::Info() const
{
	if (m_tv.IsSwitchedOn())
	{
		m_output << "TV is switched on, channel is " << m_tv.GetChannel() << "\n";
	} 
	else 
	{
		m_output << "TV is switched off\n";
	}

	return true;
}

bool CRemoteControl::SwitchOn()
{
	return true;
}

bool CRemoteControl::SwitchOff()
{
	return true;
}

bool CRemoteControl::SetChannel(istream& args)
{
	return true;
}

bool CRemoteControl::SetPreviousChannel()
{
	return true;
}
