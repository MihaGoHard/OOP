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
	return { 0, 0 };
}

double CCircle::GetRadius() const
{
	return 0 ;
}

double CCircle::GetArea() const
{
	return 0;
}

double CCircle::GetPerimeter() const
{
	return 0;
}

string CCircle::ToString() const
{
	return "";
}