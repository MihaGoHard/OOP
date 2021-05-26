#pragma once

#include <string>
#include <stdexcept>

using namespace std;

class CUrlParsingError : public invalid_argument
{
public:
	CUrlParsingError(string const& exceptMsg);
};
