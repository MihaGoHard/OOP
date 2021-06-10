#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../myStackApp/CMyStack.h"

#include <iostream>


TEST_CASE("CStack")
{
	CMyStack<int> intStack;
	CMyStack<string> strStack;

	SECTION("empty stack ")
	{
		CHECK(intStack.isEmpty());
		CHECK_THROWS(intStack.GetTopElem());
	}

	SECTION("push")
	{
		intStack.Push(2);
		CHECK(!intStack.isEmpty());
		CHECK(intStack.GetTopElem() == 2);
		intStack.Push(5);
		intStack.Push(1);
		CHECK(intStack.GetTopElem() == 1);
	}

	SECTION("pop")
	{
		intStack.Pop();
		CHECK(!intStack.isEmpty());
		CHECK(intStack.GetTopElem() == 1);
		intStack.Pop();
		intStack.Pop();
		CHECK_THROWS(intStack.GetTopElem());
		CHECK(intStack.isEmpty());
	}

	SECTION("clear")
	{
		strStack.Push("2");
		strStack.Push("5");
		strStack.Push("3");
		CHECK(!intStack.isEmpty());
		strStack.Clear();
		CHECK(intStack.isEmpty());
	}
}
