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

	SECTION("Set channel, channel limits")
	{
		CTVSet tv;
		CHECK(tv.SetChannel(2) == false);
		CHECK(tv.SwitchOn() == true);
		CHECK(tv.SetChannel(0) == false);
		CHECK(tv.SetChannel(1) == false);
		CHECK(tv.SetChannel(2) == true);
		CHECK(tv.SetChannel(100) == false);
		CHECK(tv.SetChannel(99) == true);
		CHECK(tv.GetChannel() == 99);
		CHECK(tv.SetChannel(200) == false);
		CHECK(tv.GetChannel() == 99);
	}

	SECTION("Get channel with on/off TV")
	{
		CTVSet tv;
		CHECK(tv.GetChannel() == 0);
		CHECK(tv.SwitchOn() == true);
		CHECK(tv.GetChannel() == 1);
		CHECK(tv.SetChannel(2) == true);
		CHECK(tv.GetChannel() == 2);
		CHECK(tv.SwitchOff() == true);
		CHECK(tv.GetChannel() == 0);
		CHECK(tv.SwitchOn() == true);
		CHECK(tv.GetChannel() == 2);
	}

	SECTION("Select previous channel")
	{
		CTVSet tv;
		CHECK(tv.SetPreviousChannel() == false);
		CHECK(tv.SwitchOn() == true);
		CHECK(tv.SetPreviousChannel() == false);
		CHECK(tv.SetChannel(2) == true);
		CHECK(tv.SetPreviousChannel() == true);
		CHECK(tv.GetChannel() == 1);
		CHECK(tv.SetChannel(10) == true);
		CHECK(tv.SetChannel(15) == true);
		CHECK(tv.SwitchOff() == true);
		CHECK(tv.SetPreviousChannel() == false);
		CHECK(tv.SwitchOn() == true);
		CHECK(tv.GetChannel() == 15);
		CHECK(tv.SetPreviousChannel() == true);
		CHECK(tv.GetChannel() == 10);
		CHECK(tv.SetPreviousChannel() == false);
		CHECK(tv.GetChannel() == 10);
	}
}