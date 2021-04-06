#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <iostream>

#include "../geometric_shapes_app/CLineSegment.h"


using namespace std;

TEST_CASE("CLineSegment")
{
	SPoint startPoint{ 1, 2 };
	SPoint endPoint{ 3, 5 };
	uint32_t outlineColor = 20;
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
}