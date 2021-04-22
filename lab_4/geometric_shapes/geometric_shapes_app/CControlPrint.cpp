#include "CControl.h"

using namespace std;

bool CControl::PrintShapeMinPerimeter() const
{
	if (m_shapesList.size() == 0)
	{
		m_output << "\nNo shapes in list\n";
		return false;
	}

	auto shapeMinPerimeter = min_element(m_shapesList.cbegin(), m_shapesList.cend(),
		[](const auto& shape1, const auto& shape2) {
			return shape1->GetPerimeter() < shape2->GetPerimeter();
		});

	m_output << "\nShape with min perimeter: \n"
			 << (*shapeMinPerimeter)->ToString() << "\n";

	return true;
}

bool CControl::PrintShapeMaxArea() const
{
	if (m_shapesList.size() == 0)
	{
		m_output << "\nNo shapes in list\n";
		return false;
	}



	auto shapeMaxArea = max_element(m_shapesList.cbegin(), m_shapesList.cend(),
		[](const auto& shape1, const auto& shape2) {
			return shape1->GetArea() < shape2->GetArea();
		});

	m_output << "\n\nShape with max area \n"
			 << (*shapeMaxArea)->ToString() << "\n";
	return true;
}

bool CControl::PrintInfo() const
{
	if (m_shapesList.size() == 0)
	{
		m_output << "\nEmpty shape list, add at least one shape\n";
		return false;
	}

	cout << "\nShapes in list:\n";
	for (auto shape : m_shapesList)
	{
		m_output << shape->ToString() << "\n";
	}
	return true;
}
