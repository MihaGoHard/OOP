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
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CRectangle::GetArea() const
{
	return 0;
}

double CRectangle::GetPerimeter() const
{
	return 0;
}

uint32_t CRectangle::GetOutlineColor() const
{
	return 0x000000;
}

uint32_t CRectangle::GetFillColor() const
{
	return 0x000000;
}

CPoint CRectangle::GetLeftTop() const
{
	return { 0, 0 };
}

CPoint CRectangle::GetRightBottom() const
{
	return { 0, 0 };
}

double CRectangle::GetWidth() const
{
	return 0;
}

double CRectangle::GetHeight() const
{
	return 0;
}

string CRectangle::ToString() const
{
	string triangleInfo = "";
	return triangleInfo;
}





