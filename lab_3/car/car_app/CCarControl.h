#pragma once
#include "CCar.h"
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <sstream>


using namespace std;


class CCarControl
{
public:
	CCarControl(CCar& car, istream& input, ostream& output);
	
	bool HandleCommand();

private:
	bool PrintCarInfo();
	bool StartEngine();
	bool StopEngine();
	bool SetGear(istream& args);
	bool SetSpeed(istream& args);

private:
	using Handler = function<bool(istream& args)>;

	using ActionMap = map<string, Handler>;

	CCar& m_car;
	istream& m_input;
	ostream& m_output;

	const ActionMap m_actionMap;
};

