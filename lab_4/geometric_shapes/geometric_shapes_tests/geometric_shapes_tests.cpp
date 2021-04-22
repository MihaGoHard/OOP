#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <sstream>
#include <iostream>

#include "../geometric_shapes_app/CShape.h"
#include "../geometric_shapes_app/CSolidShape.h"
#include "../geometric_shapes_app/CLineSegment.h"
#include "../geometric_shapes_app/CTriangle.h"
#include "../geometric_shapes_app/CRectangle.h"
#include "../geometric_shapes_app/CCircle.h"
#include "../geometric_shapes_app/CControl.h"

using namespace std;

uint32_t fillColor = 0xFF0000;
uint32_t outlineColor = 0xFF00FF;


TEST_CASE("CLineSegment")
{
	CPoint startPoint{ 6, 2 };
	CPoint endPoint{ 3, 5 };
	double perimeter = hypot(endPoint.x - startPoint.x, endPoint.y - startPoint.y);
	ostringstream strm;
	strm << fixed << setprecision(2) << perimeter;
	string strPerimeter = strm.str();

	string outString = ">Line:\n  startPoint(6.00, 2.00)\n  endPoint(3.00, 5.00)\n  perimeter: " + strPerimeter + "\n  area: 0.00\n  border color: ff00ff\n";

	CLineSegment line(startPoint, endPoint, outlineColor);

	SECTION("check line.GetStartPoint()")
	{
		CHECK(line.GetStartPoint().x == startPoint.x);
		CHECK(line.GetStartPoint().y == startPoint.y);
	}

	SECTION("check line.GetEndPoint()")
	{
		CHECK(line.GetEndPoint().x == endPoint.x);
		CHECK(line.GetEndPoint().y == endPoint.y);
	}

	SECTION("check line.GetEndPerimeter()")
	{
		CHECK(line.GetPerimeter() == perimeter);
	}

	SECTION("check line.GetArea")
	{
		CHECK(line.GetArea() == 0.0);
	}

	SECTION("check line.GetOutlineColor")
	{
		CHECK(line.GetOutlineColor() == outlineColor);
	}

	SECTION("check line.ToString")
	{
		CHECK(line.ToString() == outString);
	}
}

TEST_CASE("CTriangle")
{
	CPoint vertex1{ 2, 3 };
	CPoint vertex2{ 6, 3 };
	CPoint vertex3{ 3, 8 };

	double side1 = hypot(vertex1.x - vertex2.x, vertex1.y - vertex2.y);
	double side2 = hypot(vertex2.x - vertex3.x, vertex2.y - vertex2.y);
	double side3 = hypot(vertex3.x - vertex1.x, vertex3.y - vertex1.y);
	double perimeter = side1 + side2 + side3;

	ostringstream strm;
	strm << fixed << setprecision(2) << perimeter;
	string strPerimeter = strm.str();

	double area = sqrt(perimeter * (perimeter - side1) * (perimeter - side2) * (perimeter - side3));
	
	ostringstream strm2;
	strm2 << fixed << setprecision(2) << area;
	string strArea = strm2.str();

	string outString = ">Triangle:\n  vertex1(2.00, 3.00)\n  vertex2(6.00, 3.00)\n  vertex3(3.00, 8.00)\n  perimeter: " + 
		strPerimeter + "\n  area: " + 
		strArea + "\n  border color: ff00ff\n  fill color: ff0000\n";

	CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);

	SECTION("check triangle.GetVertexe1()")
	{
		CHECK(triangle.GetVertex1().x == vertex1.x);
		CHECK(triangle.GetVertex1().y == vertex1.y);
	}

	SECTION("check triangle.GetVertexe2()")
	{
		CHECK(triangle.GetVertex2().x == vertex2.x);
		CHECK(triangle.GetVertex2().y == vertex2.y);
	}

	SECTION("check triangle.GetVertexe3()")
	{
		CHECK(triangle.GetVertex3().x == vertex3.x);
		CHECK(triangle.GetVertex3().y == vertex3.y);
	}

	SECTION("check triangle.GetPerimetert()")
	{
		CHECK(triangle.GetPerimeter() == perimeter);
	}

	SECTION("check triangle.GetArea()")
	{
		CHECK(triangle.GetArea() == area);
	}

	SECTION("check triangle.GetOutlineColor()")
	{
		CHECK(triangle.GetOutlineColor() == outlineColor);
	}

	SECTION("check triangle.GetFillColor()")
	{
		CHECK(triangle.GetFillColor() == fillColor);
	}

	SECTION("check triangle.ToString()")
	{
		CHECK(triangle.ToString() == outString);
	}
}

TEST_CASE("CRectangle")
{
	double width = 10.5;
	double height = 5.5;
	CPoint leftTop{ 2, 3 };
	CPoint rightBottom{ leftTop.x + width, leftTop.y + height };
	double perimeter = 2 * (width + height);
	double area = width * height;

	ostringstream strm;
	strm << fixed << setprecision(2) << perimeter;
	string strPerimeter = strm.str();

	ostringstream strm2;
	strm2 << fixed << setprecision(2) << area;
	string strArea = strm2.str();

	string outString = ">Rectangle:\n  leftTop(2.00, 3.00)\n  rightBottom(12.50, 8.50)\n  width: 10.50\n  height: 5.50\n  perimeter: " + 
		strPerimeter + "\n  area: " + strArea + 
		"\n  border color: ff00ff\n  fill color: ff0000\n";

	CRectangle rectangle(leftTop, width, height, outlineColor, fillColor);

	SECTION("check rectangle.GetLeftTop")
	{
		CHECK(rectangle.GetLeftTop().x == leftTop.x);
		CHECK(rectangle.GetLeftTop().y == leftTop.y);
	}

	SECTION("check rectangle.GetWidth")
	{
		CHECK(rectangle.GetWidth() == width);
	}

	SECTION("check rectangle.GetHeight")
	{
		CHECK(rectangle.GetHeight() == height);
	}

	SECTION("check rectangle.GetRightTop")
	{
		CHECK(rectangle.GetRightBottom().x == rightBottom.x);
		CHECK(rectangle.GetRightBottom().y == rightBottom.y);
	}

	SECTION("check rectangle.GetPerimeter")
	{
		CHECK(rectangle.GetPerimeter() == perimeter);
	}

	SECTION("check rectangle.GetArea")
	{
		CHECK(rectangle.GetArea() == area);
	}

	SECTION("check rectangle.GetFillColor()")
	{
		CHECK(rectangle.GetFillColor() == fillColor);
	}

	SECTION("check rectangle.GetOutlineColor()")
	{
		CHECK(rectangle.GetOutlineColor() == outlineColor);
	}

	SECTION("check triangle.ToString()")
	{
		CHECK(rectangle.ToString() == outString);
	}
}


TEST_CASE("CCircle")
{
	CPoint center = { 15, 15 };
	double radius = 10;
	const double PI = 3.14;

	double perimeter = 2 * PI * radius;
	double area = pow(PI * radius, 2);

	ostringstream strm;
	strm << fixed << setprecision(2) << perimeter;
	string strPerimeter = strm.str();

	ostringstream strm2;
	strm2 << fixed << setprecision(2) << area;
	string strArea = strm2.str();

	string outString = ">Circle:\n  center(15.00, 15.00)\n  radius: 10.00\n  perimeter: " + strPerimeter + "\n  area: " + strArea + "\n  border color: ff00ff\n  fill color: ff0000\n";

	CCircle circle(center, radius, outlineColor, fillColor);
	
	SECTION("check circle.GetCenter()")
	{
		CHECK(circle.GetCenter().x == center.x);
		CHECK(circle.GetCenter().y == center.y);
	}

	SECTION("check circle.GetRadius()")
	{
		CHECK(circle.GetRadius() == radius);
	}

	SECTION("check circle.GetPerimeter()")
	{
		CHECK(circle.GetPerimeter() == perimeter);
	}

	SECTION("check circle.GetArea()")
	{
		CHECK(circle.GetArea() == area);
	}

	SECTION("check circle.GetFillColor()")
	{
		CHECK(circle.GetFillColor() == fillColor);
	}

	SECTION("check circle.GetOutlineColor()")
	{
		CHECK(circle.GetOutlineColor() == outlineColor);
	}

	SECTION("check circle.ToString()")
	{
		CHECK(circle.ToString() == outString);
	}
}


TEST_CASE("CControl")
{
	SECTION("add line to shape list")
	{
		string inStr = "line 10 10 15 20 ff00ee\ninfo\n";

		string outStr = ">Line:\n  startPoint(10.00, 10.00)\n  endPoint(15.00, 20.00)\n  perimeter: 11.18\n  area: 0.00\n  border color: ff00ee\n\n";

		istringstream input(inStr);
		ostringstream output;

		CControl control(input, output);
		control.HandleCommand();
		control.HandleCommand();

		CHECK(outStr == output.str());
	}
}























