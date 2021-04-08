#include "CSolidShape.h"

CSolidShape::CSolidShape(uint32_t const& outlineColor, uint32_t const& fillColor)
	: m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{}

uint32_t CSolidShape::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CSolidShape::GetFillColor() const
{
	return m_fillColor;
}
