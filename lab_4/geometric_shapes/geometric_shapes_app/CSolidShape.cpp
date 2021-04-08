#include "CSolidShape.h"

CSolidShape::CSolidShape(uint32_t const& outlineColor, uint32_t const& fillColor)
	: m_fillColor(fillColor)
	, CShape(outlineColor)
{}


uint32_t CSolidShape::GetFillColor() const
{
	return m_fillColor;
}
