#include "CControl.h"
#include <iostream>
#include <sstream>
using namespace std;

CControl::CControl(istream& input, ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "line", [this](istream& strm) {
			   CPoint startPoint;
			   CPoint endPoint;
			   uint32_t outlineColor;

			   strm >> startPoint.x;
			   strm >> startPoint.y;
			   strm >> endPoint.x;
			   strm >> endPoint.y;
			   strm >> outlineColor;
 
			   CLineSegment line(startPoint, endPoint, outlineColor);	
			   return AddShape(line);
		   } },
	})
{
}

bool CControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}


bool CControl::AddShape(IShape& shape)
{
	return true;
}