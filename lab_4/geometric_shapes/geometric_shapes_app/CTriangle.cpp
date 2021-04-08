#include "CTriangle.h"

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2,
	CPoint const& vertex3, uint32_t const& outlineColor, uint32_t const& fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, CSolidShape(outlineColor, fillColor)
{
}


CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

void CTriangle::GetSides(double &side1, double &side2, double &side3) const
{
	side1 = hypot(m_vertex1.x - m_vertex2.x, m_vertex1.y - m_vertex2.y);
	side2 = hypot(m_vertex2.x - m_vertex3.x, m_vertex2.y - m_vertex2.y);
	side3 = hypot(m_vertex3.x - m_vertex1.x, m_vertex3.y - m_vertex1.y);
}

double CTriangle::GetPerimeter() const
{
	double side1;
	double side2;
	double side3;
	GetSides(side1, side2, side3);
	double perimeter = side1 + side2 + side3;
	return perimeter;
}

double CTriangle::GetArea() const
{
	double side1;
	double side2;
	double side3;
	GetSides(side1, side2, side3);
	double perimeter = GetPerimeter();
	double area = sqrt(perimeter * (perimeter - side1) * (perimeter - side2) * (perimeter - side3));
	return area;
}


string CTriangle::ToString() const
{
	double perimeter = GetPerimeter();
	double area = GetArea();
	uint32_t outlineColor = GetOutlineColor();
	uint32_t fillColor = GetFillColor();

	ostringstream strm;
	strm << fixed << setprecision(2) << perimeter;
	string strPerimeter = strm.str();
	strm.str("");

	ostringstream strm2;
	strm2 << fixed << setprecision(2) << area;
	string strArea = strm2.str();

	strm << fixed << setprecision(2)
		 << "Triangle:\n"
		 << "vertex1(" << m_vertex1.x << ", " << m_vertex1.y << ")\n"
		 << "vertex2(" << m_vertex2.x << ", " << m_vertex2.y << ")\n"
		 << "vertex3(" << m_vertex3.x << ", " << m_vertex3.y << ")\n"
		 << "perimeter: " << strPerimeter << "\n"
		 << "area: " << strArea << "\n"
		 << "border color: " << hex << outlineColor << "\n"
		 << "fill color: " << hex << fillColor << "\n";

	string triangleInfo = strm.str();
	return triangleInfo;
}
