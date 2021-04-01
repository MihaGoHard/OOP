#pragma once
#include <map>
#include <iostream>

using namespace std;

const pair<int, int> channelLimits = { 1, 99 };

class CTVSet
{
public:
	bool SwitchOn();
	bool SwitchOff();
	bool SetChannel(int channel);
	int GetChannel() const;
	bool IsSwitchedOn() const;

private:
	bool m_tvIsOn = false;
	int m_currentChannel = 1;
};