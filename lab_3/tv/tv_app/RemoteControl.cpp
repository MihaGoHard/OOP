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
		  { "SwitchOn", [this](istream& strm) {
			   return SwitchOn();
		   } },
		  { "SwitchOff", [this](istream& strm) {
			   return SwitchOff();
		   } },
		  { "SetChannel", [this](istream& strm) {
			   return SetChannel(strm);
		   } },
		  { "SetPreviousChannel", [this](istream& strm) {
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
	if (!m_tv.SwitchOn())
	{
		m_output << " TV is already switched on\n";
	}
	else
	{
		Info();
	}
	return true;
}

bool CRemoteControl::SwitchOff()
{
	if (!m_tv.SwitchOff())
	{
		m_output << " TV is already switched off\n";
	}
	else
	{
		Info();
	}
	return true;
}

bool GetNumberFromStr(string inputStr, int& inputNum)
{
	try
	{
		inputNum = stoi(inputStr);
	}
	catch (exception& exception)
	{
		cout << "incorrect argument\n";
		cerr << exception.what() << "\n";
		return false;
	}

	return true;
}


bool CRemoteControl::SetChannel(istream& args)
{	
	int channel = -1;
	string inputStr;
	args >> inputStr;

	if (GetNumberFromStr(inputStr, channel))
	{
		if (m_tv.SetChannel(channel))
		{
			m_output << "Channel " << m_tv.GetChannel() << " is seted\n";
		}
		else
		{
			m_output << "Channel selection mistace\n";
		}
	}

	return true;
}

bool CRemoteControl::SetPreviousChannel()
{
	if (m_tv.SetPreviousChannel())
	{
		m_output << "Channel " << m_tv.GetChannel() << " is seted\n";
	}
	else
	{
		m_output << "cant set previous channel\n";
	}
	return true;
}
