#include "CLineSegment.h"
using namespace std;

CLineSegment::CLineSegment(CPoint const& startPoint, CPoint const& endPoint, uint32_t const& outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, CShape(outlineColor)
{
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetPerimeter() const
{
	double perimeter = hypot(m_endPoint.x - m_startPoint.x, m_endPoint.y - m_startPoint.y);
	return perimeter;
}

string CLineSegment::ToString() const
{
	auto perimeter = GetPerimeter();
	auto area = GetArea();
	auto outlineColor = GetOutlineColor();
	string startPoint = to_string(m_startPoint.x);
	ostringstream strm;
	strm << fixed << setprecision(2) 
		 << ">Line:\n"
		 << "  startPoint(" << m_startPoint.x << ", " << m_startPoint.y << ")\n"
		 << "  endPoint(" << m_endPoint.x << ", " << m_endPoint.y << ")\n"
		 << "  perimeter: " << perimeter << "\n"
		 << "  area: " << area << "\n"
		 << "  border color: " << setfill('0') << setw(6) << hex << outlineColor << "\n";

	string lineInfo = strm.str();
	return lineInfo;
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}