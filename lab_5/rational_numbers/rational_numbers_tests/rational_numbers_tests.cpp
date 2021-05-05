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

TEST_CASE("Unar operators")
{
	SECTION("-")
	{
		CRational rational(4, 6);
		auto resultRational = -rational;
		CHECK(resultRational.GetNumerator() == -2);
		CHECK(resultRational.GetDenominator() == 3);
	}

	SECTION("+")
	{
		CRational rational(4, 6);
		auto resultRational = +rational;
		CHECK(resultRational.GetNumerator() == 2);
		CHECK(resultRational.GetDenominator() == 3);
	}
}

TEST_CASE("Binar operators +|-")
{
	SECTION("-")
	{
		CRational leftOperand(4, 6);
		CRational rightOperand(-3, 2);
		auto resultRational = leftOperand - rightOperand;
		CHECK(resultRational.GetNumerator() == 13);
		CHECK(resultRational.GetDenominator() == 6);
	}

	SECTION("+")
	{
		CRational leftOperand(4, 6);
		CRational rightOperand(-3, 2);
		auto resultRational = leftOperand + rightOperand;
		CHECK(resultRational.GetNumerator() == -5);
		CHECK(resultRational.GetDenominator() == 6);
	}
}

TEST_CASE("Binar operators *|/")
{
	SECTION("/")
	{
		CRational leftOperand(4, 6);
		CRational rightOperand(-3, 2);
		auto resultRational = leftOperand - rightOperand;
		CHECK(resultRational.GetNumerator() == -4);
		CHECK(resultRational.GetDenominator() == 9);
	}

	SECTION("*")
	{
		CRational leftOperand(4, 6);
		CRational rightOperand(-3, 2);
		auto resultRational = leftOperand + rightOperand;
		CHECK(resultRational.GetNumerator() == -1);
		CHECK(resultRational.GetDenominator() == 1);
	}
}

























