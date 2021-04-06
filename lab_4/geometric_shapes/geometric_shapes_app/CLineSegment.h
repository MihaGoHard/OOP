#pragma once
#include "IShape.h"
using namespace std;

class CLineSegment
	: public IShape
{
public:
	CLineSegment(SPoint const& startPoint, SPoint const& endPoint, uint32_t const& outlineColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	uint32_t GetOutlineColor() const override;

	SPoint GetStartPoint() const;
	SPoint GetEndPoint() const;

private:
	SPoint m_startPoint;
	SPoint m_endPoint;
	uint32_t m_outlineColor;
};
