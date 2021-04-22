#include "CControl.h"

using namespace std;

bool CControl::AddLine()
{
	CPoint startPoint = { stod(m_inputStrVector[0]), stod(m_inputStrVector[1]) };
	CPoint endPoint = { stod(m_inputStrVector[2]), stod(m_inputStrVector[3]) };
	uint32_t outlineColor = stoul(m_inputStrVector[4], nullptr, 16);
	m_inputStrVector.clear();
	shared_ptr<IShape> line = make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
	m_shapesList.push_back(line);
	return true;
}

bool CControl::AddTriangle()
{
	CPoint vertex1 = { stod(m_inputStrVector[0]), stod(m_inputStrVector[1]) };
	CPoint vertex2 = { stod(m_inputStrVector[2]), stod(m_inputStrVector[3]) };
	CPoint vertex3 = { stod(m_inputStrVector[4]), stod(m_inputStrVector[5]) };
	uint32_t outlineColor = stoul(m_inputStrVector[6], nullptr, 16);
	uint32_t fillColor = stoul(m_inputStrVector[7], nullptr, 16);
	m_inputStrVector.clear();
	shared_ptr<IShape> triangle = make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
	m_shapesList.push_back(triangle);
	return true;
}

bool CControl::AddRectangle()
{
	CPoint leftTop = { stod(m_inputStrVector[0]), stod(m_inputStrVector[1]) };
	double width = stod(m_inputStrVector[2]);
	double height = stod(m_inputStrVector[3]);
	uint32_t outlineColor = stoul(m_inputStrVector[4], nullptr, 16);
	uint32_t fillColor = stoul(m_inputStrVector[5], nullptr, 16);
	m_inputStrVector.clear();
	shared_ptr<IShape> rectangle = make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor);
	m_shapesList.push_back(rectangle);
	return true;
}

bool CControl::AddCircle()
{
	CPoint center = { stod(m_inputStrVector[0]), stod(m_inputStrVector[1]) };
	double radius = stod(m_inputStrVector[2]);
	uint32_t outlineColor = stoul(m_inputStrVector[3], nullptr, 16);
	uint32_t fillColor = stoul(m_inputStrVector[4], nullptr, 16);
	m_inputStrVector.clear();
	shared_ptr<IShape> circle = make_shared<CCircle>(center, radius, outlineColor, fillColor);
	m_shapesList.push_back(circle);
	return true;
}
