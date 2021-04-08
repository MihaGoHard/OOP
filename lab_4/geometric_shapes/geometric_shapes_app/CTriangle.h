#pragma once
#include <sstream>
#include <iomanip>
#include <math.h>
#include "CSolidShape.h"

class CTriangle
	: public CSolidShape
{
public:
	CTriangle(CPoint const& vertex1, CPoint const& vertex2,
		CPoint const& vertex3, uint32_t const& outlineColor,
		uint32_t const& fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;


	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	void GetSides(double &side1, double &side2, double &side3) const;
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
