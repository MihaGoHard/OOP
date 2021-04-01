#pragma once

#include "CTVSet.h"
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

class CRemoteControl
{
public:
	CRemoteControl(CTVSet& tv, istream& input, ostream& output);

	bool HandleCommand();

private:
	bool SwitchOn();
	bool SwitchOff();
	bool SetChannel(istream& args);
	bool SetPreviousChannel();
	bool Info() const;

private:
	using Handler = function<bool(istream& args)>;

	using ActionMap = map<string, Handler>;

	CTVSet& m_tv;
	istream& m_input;
	ostream& m_output;

	const ActionMap m_actionMap;
};
