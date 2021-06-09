#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../fiandMaxApp/FindMax.h"

using namespace std;

TEST_CASE("FindMax")
{
	SECTION("empty arr")
	{
		vector<int> emptyArr = {};
		int maxElem = -1; 
		bool result = FindMax(emptyArr, maxElem);
		CHECK(!result);
		CHECK(maxElem == -1);
	}

	SECTION("int")
	{
		vector<int> arr = {0, 9, -2, 5, 9};
		int maxElem = -100;
		bool result = FindMax(arr, maxElem);
		CHECK(result);
		CHECK(maxElem == 9);
	}

	SECTION("double")
	{
		vector<double> emptyArr = { 0.12345, -0.12345, 0.12346, 0.12344, 0.12345 };
		double maxElem = 0;
		bool result = FindMax(emptyArr, maxElem);
		CHECK(result);
		CHECK(maxElem == 0.12346);
	}

	SECTION("string")
	{
		vector<string> arr = { "a", "", "ac", "ab", "Ab" };
		string maxElem = "";
		bool result = FindMax(arr, maxElem);
		CHECK(result);
		CHECK(maxElem == "ac");
	}
}

TEST_CASE("FindMax const char*")
{
	SECTION("const char*")
	{
		vector<const char*> arr = { "a", "", "ac", "ab", "Ab" };
		const char* maxElem = "";
		bool result = FindMax(arr, maxElem);
		CHECK(result);
		CHECK(maxElem == "ac");
	}
}