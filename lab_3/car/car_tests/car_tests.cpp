#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <iostream>

#include "../car_app/CCar.h"
#include "../car_app/CarUtils.h"
#include "../car_app/CCarControl.h"
#include "../car_app/CarControlUtils.h"

using namespace std;

TEST_CASE("Ccar")
{
	
	SECTION("Object creation")
	{
		CCar car;
		CHECK(car.GetSpeed() == 0);
		CHECK(car.GetDirection() == Direction::OnPlace);
		CHECK(car.GetGear() == Gear::Neutral);
		CHECK(car.EngineIsTurnedOn() == false);
	}

	SECTION("Methods do not change the state with not working engine")
	{
		CCar car;
		CHECK(car.StopEngine() == false);
		CHECK(car.SetGear(Gear::One) == false);
		CHECK(car.SetGear(Gear::Reverse) == false);
		CHECK(car.SetGear(Gear::Neutral) == false);
		CHECK(car.SetGear(Gear::Four) == false);
		CHECK(car.SetSpeed(10) == false);
		CHECK(car.SetSpeed(0) == false);
		CHECK(car.GetSpeed() == 0);
		CHECK(car.GetDirection() == Direction::OnPlace);
		CHECK(car.GetGear() == Gear::Neutral);
		CHECK(car.EngineIsTurnedOn() == false);
	}

	SECTION("start/stop engine on place")
	{
		CCar car;
		CHECK(car.EngineIsTurnedOn() == false);
		CHECK(car.StopEngine() == false);
		CHECK(car.StartEngine() == true);
		CHECK(car.EngineIsTurnedOn() == true);
		CHECK(car.StartEngine() == false);
		CHECK(car.StopEngine() == true);
		CHECK(car.EngineIsTurnedOn() == false);
	}

	SECTION("gears selection on place with working engine and zero speed")
	{
		CCar car;
		CHECK(car.StartEngine() == true);
		CHECK(car.SetGear(Gear::Reverse) == true);
		CHECK(car.SetGear(Gear::One) == true);
		CHECK(car.SetGear(Gear::Neutral) == true);
		CHECK(car.SetSpeed(2) == false);
		CHECK(car.SetGear(Gear::One) == true);
		CHECK(car.SetGear(Gear::Two) == false);
		

		CHECK(car.EngineIsTurnedOn() == true);
		CHECK(car.GetSpeed() == 0);
		CHECK(car.GetGear() == Gear::One);
		CHECK(car.GetDirection() == Direction::OnPlace);
	}

	SECTION("check gears and speed limits")
	{
		CCar car;
		CHECK(car.StartEngine() == true);

		CHECK(car.SetGear(Gear::Reverse) == true);
		CHECK(car.SetSpeed(21) == false);
		CHECK(car.SetSpeed(20) == true);
		CHECK(car.SetGear(Gear::One) == false);
		CHECK(car.SetGear(Gear::Neutral) == true);
		CHECK(car.SetGear(Gear::One) == false);
		CHECK(car.SetSpeed(0) == true);

		CHECK(car.SetGear(Gear::One) == true);
		CHECK(car.SetSpeed(1) == true);
		CHECK(car.SetGear(Gear::Reverse) == false);

		CHECK(car.SetSpeed(-10) == false);
		CHECK(car.SetSpeed(31) == false);
		CHECK(car.SetSpeed(30) == true);
		CHECK(car.SetSpeed(-1) == false);
		CHECK(car.SetSpeed(0) == true);
		CHECK(car.SetSpeed(19) == true);
		CHECK(car.SetGear(Gear::Two) == false);
		CHECK(car.SetSpeed(20) == true);

		CHECK(car.SetGear(Gear::Two) == true);
		CHECK(car.SetSpeed(51) == false);
		CHECK(car.SetSpeed(50) == true);
		CHECK(car.SetSpeed(29) == true);
		CHECK(car.SetGear(Gear::Three) == false);
		CHECK(car.SetSpeed(30) == true);

		CHECK(car.SetGear(Gear::Three) == true);
		CHECK(car.SetSpeed(61) == false);
		CHECK(car.SetSpeed(60) == true);
		CHECK(car.SetSpeed(39) == true);
		CHECK(car.SetGear(Gear::Four) == false);
		CHECK(car.SetSpeed(40) == true);

		CHECK(car.SetGear(Gear::Four) == true);
		CHECK(car.SetSpeed(91) == false);
		CHECK(car.SetSpeed(90) == true);
		CHECK(car.SetSpeed(49) == true);
		CHECK(car.SetGear(Gear::Five) == false);
		CHECK(car.SetSpeed(50) == true);

		CHECK(car.SetGear(Gear::Five) == true);
		CHECK(car.SetSpeed(151) == false);
		CHECK(car.SetSpeed(150) == true);
		CHECK(car.SetGear(Gear::Four) == false);
		CHECK(car.SetGear(Gear::Two) == false);
		CHECK(car.SetGear(Gear::Reverse) == false);
		CHECK(car.SetGear(Gear::Neutral) == true);


		CHECK(car.EngineIsTurnedOn() == true);
		CHECK(car.GetSpeed() == 150);
		CHECK(car.GetGear() == Gear::Neutral);
		CHECK(car.GetDirection() == Direction::Forward);
	}

	SECTION("start/stop engine on reverse gear")
	{
		CCar car;
		CHECK(car.StartEngine() == true);
		CHECK(car.SetGear(Gear::Reverse) == true);
		CHECK(car.SetSpeed(10) == true);
		CHECK(car.StartEngine() == false);
		CHECK(car.StopEngine() == false);
		CHECK(car.SetGear(Gear::Neutral) == true);
		CHECK(car.StartEngine() == false);
		CHECK(car.StopEngine() == false);

		CHECK(car.SetGear(Gear::Reverse) == false);

		CHECK(car.SetSpeed(0) == true);
		CHECK(car.StartEngine() == false);
		CHECK(car.StopEngine() == true);


		CHECK(car.EngineIsTurnedOn() == false);
		CHECK(car.GetSpeed() == 0);
		CHECK(car.GetGear() == Gear::Neutral);
		CHECK(car.GetDirection() == Direction::OnPlace);
	}

	SECTION("start/stop engine on forward gear")
	{
		CCar car;
		CHECK(car.StartEngine() == true);
		CHECK(car.SetGear(Gear::One) == true);
		CHECK(car.SetSpeed(10) == true);
		CHECK(car.StartEngine() == false);
		CHECK(car.StopEngine() == false);
		CHECK(car.SetGear(Gear::Neutral) == true);
		CHECK(car.StartEngine() == false);
		CHECK(car.StopEngine() == false);
		CHECK(car.SetGear(Gear::One) == true);
		CHECK(car.SetSpeed(0) == true);
		CHECK(car.StartEngine() == false);
		CHECK(car.StopEngine() == false);
		CHECK(car.SetGear(Gear::Neutral) == true);
		CHECK(car.StartEngine() == false);
		CHECK(car.StopEngine() == true);


		CHECK(car.EngineIsTurnedOn() == false);
		CHECK(car.GetSpeed() == 0);
		CHECK(car.GetGear() == Gear::Neutral);
		CHECK(car.GetDirection() == Direction::OnPlace);
	}

	SECTION("braking on neutral")
	{
		CCar car;
		CHECK(car.StartEngine() == true);
		CHECK(car.SetGear(Gear::Reverse) == true);
		CHECK(car.SetSpeed(10) == true);
		CHECK(car.SetGear(Gear::Neutral) == true);
		CHECK(car.SetSpeed(11) == false);
		CHECK(car.SetSpeed(9) == true);
		CHECK(car.SetSpeed(0) == true);
		CHECK(car.SetGear(Gear::One) == true);
		CHECK(car.SetSpeed(30) == true);
		CHECK(car.SetGear(Gear::Two) == true);
		CHECK(car.SetSpeed(40) == true);
		CHECK(car.SetGear(Gear::Neutral) == true);
		CHECK(car.SetSpeed(41) == false);
		CHECK(car.SetSpeed(39) == true);

		CHECK(car.EngineIsTurnedOn() == true);
		CHECK(car.GetSpeed() == 39);
		CHECK(car.GetGear() == Gear::Neutral);
		CHECK(car.GetDirection() == Direction::Forward);
	}
}

TEST_CASE("CCarControl")
{

	SECTION("test Info")
	{
		CCar car;
		string inStr = "Info\n";
		string outStr = "Engine: turned off\nSpeed: 0\nDirection: on place\nGear: neutral\n";

		istringstream input(inStr);
		ostringstream output;

		CCarControl carControl(car, input, output);

		carControl.HandleCommand();

		CHECK(outStr == output.str());
	}

	SECTION("test start/stop engine")
	{
		CCar car;
		string inStr = "EngineOn\nEngineOff\n";

		istringstream input(inStr);
		ostringstream output;

		CCarControl carControl(car, input, output);

		carControl.HandleCommand();

		CHECK(car.EngineIsTurnedOn() == true);
		CHECK(car.GetSpeed() == 0);
		CHECK(car.GetGear() == Gear::Neutral);
		CHECK(car.GetDirection() == Direction::OnPlace);

		carControl.HandleCommand();

		CHECK(car.EngineIsTurnedOn() == false);
		CHECK(car.GetSpeed() == 0);
		CHECK(car.GetGear() == Gear::Neutral);
		CHECK(car.GetDirection() == Direction::OnPlace);
	}

	SECTION("test setGear, setSpeed")
	{
		CCar car;
		string inStr = "EngineOn\nSetGear 1\nSetSpeed 20\nSetGear 2\n";
		
		istringstream input(inStr);
		ostringstream output;

		CCarControl carControl(car, input, output);
		
		carControl.HandleCommand();
		carControl.HandleCommand();
		carControl.HandleCommand();
		carControl.HandleCommand();

		CHECK(car.EngineIsTurnedOn() == true);
		CHECK(car.GetSpeed() == 20);
		CHECK(car.GetGear() == Gear::Two);
		CHECK(car.GetDirection() == Direction::Forward);
	}
}