#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <sstream>

#include "../geometric_shapes_app/CLineSegment.h"
#include "../geometric_shapes_app/CTriangle.h"

using namespace std;

TEST_CASE("CLineSegment")
{
	CPoint startPoint{ 6, 2 };
	CPoint endPoint{ 3, 5 };
	double perimeter = hypot(endPoint.x - startPoint.x, endPoint.y - startPoint.y);
	ostringstream strm;
	strm << fixed << setprecision(2) << perimeter;
	string strPerimeter = strm.str();
	uint32_t outlineColor = 0xE9967A; 
	string strOutlineColor = "e9967a";

	string outString = "Line:\nstartPoint(6.00, 2.00)\nendPoint(3.00, 5.00)\nperimeter: " + strPerimeter + "\nborder color: " + strOutlineColor + "\n";

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

	uint32_t fillColor = 0xFF0000;
	uint32_t outlineColor = 0xFF00FF;

	double side1 = hypot(vertex1.x - vertex2.x, vertex1.y - vertex2.y);
	double side2 = hypot(vertex2.x - vertex3.x, vertex2.y - vertex2.y);
	double side3 = hypot(vertex3.x - vertex1.x, vertex3.y - vertex1.y);
	double perimeter = side1 + side2 + side3; 
	ostringstream strm;
	strm << fixed << setprecision(2) << perimeter;
	string strPerimeter = strm.str();
	strm.clear();

	double area = sqrt(perimeter * (perimeter - side1) * (perimeter - side2) * (perimeter - side3)); 
	strm << fixed << setprecision(2) << area;
	string strArea = strm.str();

	string outString = "Triangle:\nvertex1(2.00, 3.00)\nvertex2(6.00, 3.00)\nvertex3(3.00, 8.00)\nperimeter: " + strPerimeter + 
					    "\narea: " + strArea + "\nborder color: ff0000\nfill color: ff00ff";

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