#include "CControl.h"

using namespace std;

bool CControl::IsValidHexColor(string& str) const
{
	if (str.length() != 6)
	{
		return false;
	}
	for (auto ch : str)
	{
		if (!isdigit(ch) && ch > 'f' )
		{
			return false;
		}
	}
	return true;
}

bool CControl::CheckLineArgs()
{
	if (m_inputStrVector.size() != 5)
	{
		return false;
	}

	try
	{
		stod(m_inputStrVector[0]);
		stod(m_inputStrVector[1]);
		stod(m_inputStrVector[2]);
		stod(m_inputStrVector[3]);
		if (!IsValidHexColor(m_inputStrVector[4]))
		{
			throw out_of_range("Invalid hex color");
		}
	}
	catch (const exception& ex)
	{
		cerr << ex.what() << endl;
		return false;
	}
	return true;
}

bool CControl::CheckTriangleArgs()
{
	if (m_inputStrVector.size() != 8)
	{
		return false;
	}

	try
	{
		stod(m_inputStrVector[0]);
		stod(m_inputStrVector[1]);
		stod(m_inputStrVector[2]);
		stod(m_inputStrVector[3]);
		stod(m_inputStrVector[4]);
		stod(m_inputStrVector[5]);
		if (!IsValidHexColor(m_inputStrVector[6]) || !IsValidHexColor(m_inputStrVector[7]))
		{
			throw out_of_range("Invalid hex color");
		}
	}
	catch (const exception& ex)
	{
		cerr << ex.what() << endl;
		return false;
	}
	return true;
}

bool CControl::CheckRectangleArgs()
{
	if (m_inputStrVector.size() != 6)
	{
		return false;
	}

	try
	{
		stod(m_inputStrVector[0]);
		stod(m_inputStrVector[1]);
		stod(m_inputStrVector[2]);
		stod(m_inputStrVector[3]);
		if (!IsValidHexColor(m_inputStrVector[4]) || !IsValidHexColor(m_inputStrVector[5]))
		{
			throw out_of_range("Invalid hex color");
		}
	}
	catch (const exception& ex)
	{
		cerr << ex.what() << endl;
		return false;
	}
	return true;
}

bool CControl::CheckCircleArgs()
{
	if (m_inputStrVector.size() != 5)
	{
		return false;
	}

	try
	{
		stod(m_inputStrVector[0]);
		stod(m_inputStrVector[1]);
		stod(m_inputStrVector[2]);
		if (!IsValidHexColor(m_inputStrVector[3]) || !IsValidHexColor(m_inputStrVector[4]))
		{
			throw out_of_range("Invalid hex color");
		}
	}
	catch (const exception& ex)
	{
		cerr << ex.what() << endl;
		return false;
	}
	return true;
}
