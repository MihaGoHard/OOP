#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <sstream>

#include "../geometric_shapes_app/CLineSegment.h"

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

	string outString = "Line:\nstartPoint(6.00, 2.00)\nendPoint(3.00, 5.00)\nperimeter: " + strPerimeter + "\nborder color: " + strOutlineColor + " \n";

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
