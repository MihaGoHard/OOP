#pragma once
#include "ISolidShape.h"
#include "CShape.h"


class CSolidShape
	: public ISolidShape
	, public CShape
{
public: 
	CSolidShape(uint32_t const& outlineColor, uint32_t const& fillColor);
	uint32_t GetFillColor() const final;

	uint32_t GetOutlineColor() const override; 

	virtual ~CSolidShape(){};

private:
	uint32_t m_fillColor;
};
