#pragma once
#include <sstream>
#include <iomanip>

#include "IShape.h"

class CShape
	: virtual public IShape 
{
public:
	CShape(uint32_t const& outlineColor);

	virtual uint32_t GetOutlineColor() const = 0;

	virtual ~CShape(){};

protected:
	uint32_t m_outlineColor;
};
