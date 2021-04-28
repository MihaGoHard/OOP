#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <sstream>
#include <iostream>

#include "../rational_numbers_app/CRational.h"
using namespace std;

TEST_CASE("CRational constructors")
{
	SECTION("CRational 0/1")
	{
		CRational rational;
		CHECK(rational.GetNumerator() == 0);
		CHECK(rational.GetDenominator() == 1);
		CHECK(rational.ToDouble() == 0.00);
	}

	SECTION("CRational value/1")
	{
		CRational rational(2);
		CHECK(rational.GetNumerator() == 2);
		CHECK(rational.GetDenominator() == 1);
		CHECK(rational.ToDouble() == 2.00);
	}

	SECTION("CRational numerator/denominator")
	{
		SECTION("numerator: positive; denominator: positive")
		{
			CRational rational(2, 3);
			CHECK(rational.GetNumerator() == 2);
			CHECK(rational.GetDenominator() == 3);
			CHECK(rational.ToDouble() == Approx(0.6666666667));
		}

		SECTION("numerator: negative; denominator: positive")
		{
			CRational rational(-4, 6);
			CHECK(rational.GetNumerator() == -2);
			CHECK(rational.GetDenominator() == 3);
			CHECK(rational.ToDouble() == Approx(-0.6666666667));
		}

		SECTION("numerator: positive; denominator: negative")
		{
			CRational rational(4, -6);
			CHECK(rational.GetNumerator() == -2);
			CHECK(rational.GetDenominator() == 3);
			CHECK(rational.ToDouble() == Approx(-0.6666666667));
		}

		SECTION("numerator: negative; denominator: negative")
		{
			CRational rational(-4, -6);
			CHECK(rational.GetNumerator() == 2);
			CHECK(rational.GetDenominator() == 3);
			CHECK(rational.ToDouble() == Approx(0.6666666667));
		}

		SECTION("numerator: positive; denominator: 0")
		{
			CRational rational(2, 0);
			CHECK(rational.GetNumerator() == 0);
			CHECK(rational.GetDenominator() == 1);
			CHECK(rational.ToDouble() == 0);
		}
	}
}