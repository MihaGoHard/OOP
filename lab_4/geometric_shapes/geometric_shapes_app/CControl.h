#pragma once
#include <string>
#include <vector>
#include <functional>
#include <map>
#include "CLineSegment.h"
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

private:
	bool AddShape(IShape &shape);
	/*void PrintErrorInfo(string error);
	void PrintSuccessInfo();
	bool GetMaxAreaShape() const;
	bool GetMinPerimeterShape() const;

	bool PrintInfo(ostream& output) const;*/

private:
	using Handler = function<bool(istream& args)>;
	using ActionMap = map<string, Handler>;

	istream& m_input;
	ostream& m_output;

	const ActionMap m_actionMap;

	vector<IShape> m_shapeList;
};
