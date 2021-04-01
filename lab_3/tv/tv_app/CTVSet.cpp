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
	if (!m_tvIsOn)
	{
		return false;
	}
	if ((channel < channelLimits.first) || (channel > channelLimits.second) || (channel == m_currentChannel))
	{
		return false;
	}
	m_previousChannel = m_currentChannel;
	m_currentChannel = channel;
	return true;
}

bool CTVSet::SetPreviousChannel()
{
	if (m_previousChannel == 0 || m_previousChannel == m_currentChannel || !m_tvIsOn)
	{
		return false;
	}
	m_currentChannel = m_previousChannel;
	return true;
}

int CTVSet::GetChannel() const
{
	if (!m_tvIsOn)
	{
		return 0;
	}
	return m_currentChannel;
}
