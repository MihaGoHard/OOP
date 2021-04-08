#pragma once
#include "CSolidShape.h"

class CRectangle
	: public CSolidShape
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

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;

	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	double m_width;
	double m_height;
};
