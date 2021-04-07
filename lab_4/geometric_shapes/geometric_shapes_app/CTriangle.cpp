#include "CTriangle.h"

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2,
	CPoint const& vertex3, uint32_t const& outlineColor,
	uint32_t const& fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(m_vertex2)
	, m_vertex3(m_vertex3)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

CPoint CTriangle::GetVertex1() const
{
	return { 0, 0 };
}

CPoint CTriangle::GetVertex2() const
{
	return { 0, 0 };
}

CPoint CTriangle::GetVertex3() const
{
	return { 0, 0 };
}

double CTriangle::GetArea() const
{
	return 0;
}

double CTriangle::GetPerimeter() const
{
	return 0;
}

uint32_t CTriangle::GetOutlineColor() const
{
	return 0x000000;
}

uint32_t CTriangle::GetFillColor() const
{
	return 0x000000;
}

string CTriangle::ToString() const
{
	double perimeter = 0;
	uint32_t outlineColor = 0x000000;
	uint32_t fillColor = 0x000000;
	ostringstream strm;
	strm << fixed << setprecision(2)
		 << "Line:\n"
		 << "vertex1(" << m_vertex1.x << ", " << m_vertex1.y << ")\n"
		 << "vertex2(" << m_vertex2.x << ", " << m_vertex2.y << ")\n"
		 << "vertex3(" << m_vertex3.x << ", " << m_vertex3.y << ")\n"
		 << "perimeter: " << perimeter << "\n"
		 << "border color: " << hex << outlineColor << "\n"
		 << "fill color: " << hex << fillColor << "\n";

	string lineInfo = strm.str();
	return lineInfo;
}
