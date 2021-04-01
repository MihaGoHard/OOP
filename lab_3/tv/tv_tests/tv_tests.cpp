#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../tv_app/CTVSet.h"
#include <iostream>


using namespace std;

TEST_CASE("CTVSet")
{
	SECTION("Object creation, on/off tv")
	{
		CTVSet tv;
		CHECK(tv.SwitchOff() == false);
		CHECK(tv.IsSwitchedOn() == false);
		CHECK(tv.SwitchOn() == true);
		CHECK(tv.IsSwitchedOn() == true);
		CHECK(tv.GetChannel() == 1);
		CHECK(tv.IsSwitchedOn() == true);
		CHECK(tv.SwitchOn() == false);
		CHECK(tv.SwitchOff() == true);
	}

	SECTION("Set channel")
	{
		CTVSet tv;
		CHECK(tv.SwitchOn() == true);
		CHECK(tv.SetChannel(2) == true);
		CHECK(tv.SetChannel(0) == false);
		CHECK(tv.SetChannel(1) == false);
		CHECK(tv.SetChannel(100) == false);
		CHECK(tv.SetChannel(2) == true);
		CHECK(tv.GetChannel() == 2);
	}
}