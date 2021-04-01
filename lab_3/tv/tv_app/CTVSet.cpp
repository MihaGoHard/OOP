#include "CTVSet.h"

using namespace std;

bool CTVSet::IsSwitchedOn() const
{
	return m_tvIsOn;
}

bool CTVSet::SwitchOn()
{
	if (m_tvIsOn)
	{
		return false;
		cout << "TV is already on \n";
	}
	m_tvIsOn = true;
	return true;
}

bool CTVSet::SwitchOff()
{
	if (!m_tvIsOn)
	{
		return false;
		cout << "TV is already off \n";
	}
	m_tvIsOn = false;
	return true;
}

bool CTVSet::SetChannel(int channel) 
{
	return true;
}

int CTVSet::GetChannel() const
{
	return m_currentChannel;
}
