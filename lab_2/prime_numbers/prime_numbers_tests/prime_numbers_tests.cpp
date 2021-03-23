#define CATCH_CONFIG_MAIN

#include "../prime_numbers_app/get_primes_set.h"
#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("Sieve vector filling")
{
	const int offsetIndex = 1;
	int upperBound = 0;

	SECTION("upperBound is 0")
	{
		vector<bool> modelVector = { 0 };

		vector<bool> outVector(upperBound + offsetIndex, 1);

		FillSieve(outVector);

		CHECK(outVector == modelVector);
	}

	SECTION("upperBound is 1")
	{
		vector<bool> modelVector = { 0, 0 };

		upperBound = 1;
		vector<bool> outVector(upperBound + offsetIndex, 1);

		FillSieve(outVector);

		CHECK(outVector == modelVector);
	}

	SECTION("upperBound is 11")
	{
		vector<bool> modelVector = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1 };

		upperBound = 11;
		vector<bool> outVector(upperBound + offsetIndex, 1);

		FillSieve(outVector);

		CHECK(outVector == modelVector);
	}

	SECTION("upperBound is 100000000")
	{
		upperBound = 100000000;

		int modelCount = 5761455;
		int outCount = 0;

		vector<bool> outVector(upperBound + offsetIndex, 1);

		FillSieve(outVector);

		for (auto i : outVector)
		{
			if (i)
			{
				++outCount;
			}
		}
		CHECK(outCount == modelCount);
	}
}

TEST_CASE("Set filling from sieve-vector")
{
	vector<bool> sieveVector = { 0, 0 };

	SECTION("So prime numbers")
	{
		set<int> emptySet;

		set<int> outSet;

		FillSetFromSiev(sieveVector, outSet);

		CHECK(emptySet == outSet);
	}

	SECTION("Some prime numbers")
	{
		sieveVector = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0 };

		set<int> modelSet = { 2, 3, 5, 7, 11, 13 };

		set<int> outSet;

		FillSetFromSiev(sieveVector, outSet);

		CHECK(modelSet == outSet);
	}
}

TEST_CASE("Generate prime-number set ")
{
	int upperBound = 15;
	int offsetIndex = 1;

	SECTION("So prime numbers")
	{
		set<int> modelSet = { 2, 3, 5, 7, 11, 13 };

		set<int> outSet = GeneratePrimeNumbersSet(upperBound);

		CHECK(modelSet == outSet);
	}

	SECTION("UpperBound is 100000000")
	{
		upperBound = 100000000;

		int modelCount = 5761455;
		int outCount = 0;

		set<int> outSet = GeneratePrimeNumbersSet(upperBound);

		for (auto i : outSet)
		{
			++outCount;
		}

		CHECK(outCount == modelCount);
	}
}
