#pragma once
#include <sstream>
#include <iomanip>
#include "ISolidShape.h"

class CTriangle
	: public ISolidShape
{
public:
	CTriangle(CPoint const& vertex1, CPoint const& vertex2,
		CPoint const& vertex3, uint32_t const& outlineColor,
		uint32_t const& fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};
