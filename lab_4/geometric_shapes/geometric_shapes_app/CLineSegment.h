#pragma once
#include "IShape.h"
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <cstdint>
using namespace std;

class CLineSegment
	: public IShape
{
public:
	CLineSegment(CPoint const& startPoint, CPoint const& endPoint, uint32_t const& outlineColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	uint32_t GetOutlineColor() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
	uint32_t m_outlineColor;
};
