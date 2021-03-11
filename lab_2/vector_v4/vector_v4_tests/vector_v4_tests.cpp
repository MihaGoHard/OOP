#include <iostream>


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

#include "../vector_v4_app/GetPrintVector.cpp"
#include "../vector_v4_app/TransformVector.cpp"

TEST_CASE("Get vector checking")
{
	SECTION("Get vector from empty input")
	{
		std::istringstream input("");
		auto vector = GetVectorFromStream(input);
		CHECK(vector == std::nullopt);
	}

	SECTION("Get vector from invalid input")
	{
		std::istringstream input("e 5.4 r 8");
		auto vector = GetVectorFromStream(input);
		std::optional<std::vector<double>> resultVector = std::nullopt;
		CHECK(vector == std::nullopt);
	}

	SECTION("Get vector from valid input")
	{
		std::istringstream input("3  5 2  21  78");
		auto outOptVector = GetVectorFromStream(input);
		CHECK(outOptVector != std::nullopt);
	}
}
	


TEST_CASE("Transform vector checking")
{
	std::vector<double> numVector = { -2, 4.2, 6.7, 8.4, 8.4};

	SECTION("Empty vector")
	{
		numVector.clear();
		CHECK(TransformVector(numVector) == false);
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
		numVector.clear();
		CHECK(SortVector(numVector) == false);
	}

	SECTION("Sort vector in ascending order")
	{
		std::vector<double> resultVector = { -8.8, -4.8, 0, 2.4, 3.2, 8 };
		std::vector<double> vect = { 8, -8.8, 2.4, -4.8, 3.2, 0 };
		SortVector(vect);
		CHECK(vect == resultVector);
	}
}
