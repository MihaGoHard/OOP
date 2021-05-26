#include "CUrlParsingError.h"

CUrlParsingError::CUrlParsingError(string const& exceptMsg = "Some unknown error")
	: invalid_argument(exceptMsg)
{
}
