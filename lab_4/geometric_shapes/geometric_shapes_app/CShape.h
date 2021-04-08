#pragma once
#include <sstream>
#include <iomanip>

#include "IShape.h"

class CShape
	: virtual public IShape 
{
public:
	CShape(uint32_t const& outlineColor);
	uint32_t GetOutlineColor() const;

	virtual ~CShape(){};

private:
	uint32_t m_outlineColor;
};
