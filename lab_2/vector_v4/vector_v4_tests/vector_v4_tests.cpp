#include <iostream>

#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>

#include "../vector_v4_app/GetPrintVector.h"
#include "../vector_v4_app/TransformVector.h"



TEST_CASE("Transform vector checking")
{
	std::vector<double> numVector = { -2, 4.2, 6.7, 8.4, 8.4};

	SECTION("Empty vector")
	{
		std::vector<double> emptyVector = {};
		numVector.clear();
		TransformVector(numVector);
		CHECK(numVector == emptyVector);
	}

	SECTION("Devide every elem of vector on half of max-element")
	{
		std::vector<double> resultVector = { 2, -2.2, 0.6, -1.2, 0.8 };
		std::vector<double> vect = { 8, -8.8, 2.4, -4.8, 3.2};
		TransformVector(vect);
		CHECK(vect == resultVector);
	}
}

TEST_CASE("Sort vector checking")
{
	std::vector<double> numVector = { -2, 4.2, 6.7, 8.4, 8.4 };

	SECTION("Empty vector")  
	{
		std::vector<double> emptyVector = {};
		numVector.clear();
		SortVector(numVector);
		CHECK(numVector == emptyVector);
	}

	SECTION("Sort vector in ascending order")
	{
		std::vector<double> resultVector = { -8.8, -4.8, 0, 2.4, 3.2, 8 };
		std::vector<double> vect = { 8, -8.8, 2.4, -4.8, 3.2, 0 };
		SortVector(vect);
		CHECK(vect == resultVector);
	}
}
