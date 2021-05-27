#pragma once
#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class CInputHandler
{
public:
	CInputHandler(istream& input, ostream& output);
	bool command();

private:
	vector<string> GetInputStrVector(const string& line) const;

	istream& m_input;
	ostream& m_output;
};
