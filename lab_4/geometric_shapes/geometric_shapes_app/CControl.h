#pragma once
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "IShape.h"
#include "CCircle.h"

using namespace std;

enum class CShapeTypes 
{
	Line,
	Triangle,
	Rectangle,
	Circle
};

class CControl
{
public:
	CControl(istream& input, ostream& output);
	bool HandleCommand();

	bool PrintShapeMinPerimeter() const;
	bool PrintShapeMaxArea() const;
	bool PrintInfo() const;

private:
	using Handler = function<bool(istream& args)>;
	using ActionMap = map<string, Handler>;
	bool IsValidHexColor(string& str) const;

	bool GetInputStrVector(istream& strm);
	bool CheckLineArgs();
	bool CheckTriangleArgs();
	bool CheckRectangleArgs();
	bool CheckCircleArgs();

	bool AddLine();
	bool AddTriangle();
	bool AddRectangle();
	bool AddCircle();

	vector<string> m_inputStrVector;

	istream& m_input;
	ostream& m_output;

	const ActionMap m_actionMap;

	vector<shared_ptr<IShape>> m_shapesList;
};
