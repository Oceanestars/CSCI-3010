/**
Oceane Andreis
Homework 2
Date: October 1 2019

This program is my test.cpp.
*/


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "TestTypes.h"
#include "Counter.hpp"

Counter<string> c;
vector<int> v = { 10, 20, 30 };
TEST_CASE ( "Insert", "[Counter]")
{

	SECTION( "Insert strings" )
	{

		REQUIRE(c.Insert("dog"); == 1);
    REQUIRE(c.Insert("cat"); == 1);
	}

}
