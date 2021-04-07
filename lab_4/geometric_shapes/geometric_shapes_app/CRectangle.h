#pragma once
#include "ISolidShape.h"

class CRectangle
	: public ISolidShape
{
public:
	CRectangle(CPoint const& leftTop,
		double const& width,
		double const& height,
		uint32_t const& outlineColor,
		uint32_t const& fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;

	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	double m_width;
	double m_height;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};
