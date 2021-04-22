#include "CRectangle.h"

CRectangle::CRectangle(
	CPoint const& leftTop,
	double const& width,
	double const& height,
	uint32_t const& outlineColor,
	uint32_t const& fillColor)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, CSolidShape(outlineColor, fillColor)
{
}

double CRectangle::GetArea() const
{
	double area = m_height * m_width;
	return area;
}

double CRectangle::GetPerimeter() const
{
	double perimeter = 2 * (m_height + m_width);
	return perimeter;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	CPoint rightBottom = { m_leftTop.x + m_width, m_leftTop.y + m_height };
	return rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

string CRectangle::ToString() const
{
	double perimeter = GetPerimeter();
	double area = GetArea();
	CPoint rightBottom = GetRightBottom();
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
		 << ">Rectangle:\n"
		 << "  leftTop(" << m_leftTop.x << ", " << m_leftTop.y << ")\n"
		 << "  rightBottom(" << rightBottom.x << ", " << rightBottom.y << ")\n"
		 << "  width: " << m_width << "\n"
		 << "  height: " << m_height << "\n"
		 << "  perimeter: " << strPerimeter << "\n"
		 << "  area: " << strArea << "\n"
		 << "  border color: " << hex << outlineColor << "\n"
		 << "  fill color: " << setfill('0') << setw(6) << hex << fillColor << "\n";

	string rectangleInfo = strm.str();
	return rectangleInfo;
}



