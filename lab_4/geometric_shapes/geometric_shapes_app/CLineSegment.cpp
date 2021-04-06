#include "CLineSegment.h"


CLineSegment::CLineSegment(SPoint const& startPoint, SPoint const& endPoint, uint32_t const& outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(outlineColor)
{
}

SPoint CLineSegment::GetStartPoint() const
{
	return { 0, 0 };
}

SPoint CLineSegment::GetEndPoint() const
{
	return { 0, 0 };
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return 0.0;
}

string CLineSegment::ToString() const
{
	return "";
}

double CLineSegment::GetArea() const
{
	return 0.0;
}