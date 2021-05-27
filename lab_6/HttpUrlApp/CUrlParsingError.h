#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class CUrlParsingError : public invalid_argument
{
public:
	CUrlParsingError(string const& exceptMsg);
};
