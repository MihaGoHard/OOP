#pragma once
#include <map>
#include <iostream>

using namespace std;

const pair<int, int> channelLimits = { 1, 99 };

const map<int, string> chanelNames;

class CTVSet
{
public:
	bool SwitchOn();
	bool SwitchOff();
	bool SetChannel(int channel);
	bool SetPreviousChannel();
	int GetChannel() const;
	bool IsSwitchedOn() const;

	bool SetChannelName(int channel, string name);
	string GetChannelName(int channel);

private:
	bool m_tvIsOn = false;
	int m_previousChannel = 0;
	int m_currentChannel = 1;
};

// mistake
// select 
// записаться на английский
// видео о тестировании
// блочное тестирование

