#include "CCircle.h"
using namespace std;

CCircle::CCircle(CPoint const& center,
	double const& radius,
	uint32_t const& outlineColor,
	uint32_t const& fillColor)
	: m_center(center)
	, m_radius(radius)
	, CSolidShape(outlineColor, fillColor)
{
}


CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

double CCircle::GetPerimeter() const
{
	const double PI = 3.14;
	double perimeter = 2 * PI * m_radius;
	return perimeter;
}

double CCircle::GetArea() const
{
	const double PI = 3.14;
	double area = pow(PI * m_radius, 2);
	return area;
}

string CCircle::ToString() const
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
		 << "Circle:\n"
		 << "center(" << m_center.x << ", " << m_center.y << ")\n"
		 << "radius: " << m_radius << "\n"
		 << "perimeter: " << strPerimeter << "\n"
		 << "area: " << strArea << "\n"
		 << "border color: " << hex << outlineColor << "\n"
		 << "fill color: " << hex << fillColor << "\n";

	string circleInfo = strm.str();
	return circleInfo;
}