#pragma once
#include "ISolidShape.h"

class CSolidShape
	: virtual public ISolidShape
{
public: 
	CSolidShape(uint32_t const& outlineColor, uint32_t const& fillColor);

	uint32_t GetOutlineColor() const;
	uint32_t GetFillColor() const;

	virtual ~CSolidShape(){};

private:
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};
