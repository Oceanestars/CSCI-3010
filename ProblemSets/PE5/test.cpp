/**
Oceane Andreis
Problem Set 5
Date: September 25 2019

This program is my test.cpp.
*/


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Rectangle.h"


Point left_bottom = {0,0};
Point right_top = {3,5};

Point right_top2 = {3,6};
Point right_top3 = {4,9}; //Need this point to test the overlaps function

Point negative_bottom = {-4,-8};
Point negative_top = {-2,0};

Point small_bottom = {1,2};
Point small_top = {2,5};

Rectangle rect1(left_bottom,right_top);
Rectangle rect2(left_bottom,right_top2);
Rectangle rect3(right_top2,right_top3); //this won't overlap with rect
Rectangle rect4(negative_bottom,negative_top);
Rectangle rect5(small_bottom,small_top);

int value_holder= 0;
Point p1;
Point p2;
bool test_value;

TEST_CASE ( "Factorials are computed", "[factorial]") {
  REQUIRE( Factorial(0) == 1 ); //bug
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(7) == 5040 );
}

TEST_CASE ( "Constructor", "[rectangle]")
{

	SECTION( "Constructor" )
	{
		REQUIRE(p1.x == 0);
    REQUIRE(p1.y == 0);
	}
  SECTION("If left and right are correct")
  {
    //(0,0) & (3,5)
    REQUIRE(rect1.get_p1().x == 0);
    REQUIRE(rect1.get_p1().y == 0);
    REQUIRE(rect1.get_p2().x == 3);
    REQUIRE(rect1.get_p2().y == 5);
  }
  SECTION("If left and right are switch")
  {
    //(0,0) & (3,5)
    REQUIRE(rect1.get_p1().x == 3);
    REQUIRE(rect1.get_p1().y == 5);
    REQUIRE(rect1.get_p2().x == 0);
    REQUIRE(rect1.get_p2().y == 0);
  }
}

TEST_CASE ( "Test GetWidth function") {

  SECTION("Test correct coordinate"){

    value_holder= rect1.GetWidth();

    REQUIRE(value_holder== 3);

  }
}
TEST_CASE ( "Test GetHeight function") {

  SECTION("Test correct coordinate"){

    value_holder= rect1.GetHeight();

    REQUIRE(value_holder== 5);

  }
}

TEST_CASE ( "Test Overlap function") {

  SECTION("Test Overlap is true"){

    test_value = rect1.Overlaps(rect2);

    REQUIRE(test_value == true);

  }

  SECTION("Test Overlap is false"){

    test_value = rect1.Overlaps(rect3);

    REQUIRE(test_value == false);

  }
  SECTION("Test Overlap when one rectangle is inside"){

    test_value = rect2.Overlaps(rect5);

    REQUIRE(test_value == true);

  }
  // SECTION("Test Overlap when one rectangle is inside"){
  //
  //   test_value = rect5.Overlaps(rect2);
  //
  //   REQUIRE(test_value == true);
  //
  // }
}

TEST_CASE ( "Test CalculateArea function") {

  SECTION("Test Positive area"){

    value_holder= rect2.CalculateArea();

    REQUIRE(value_holder == 18);

  }
  SECTION("Test negative area"){

    value_holder= rect4.CalculateArea();

    REQUIRE(value_holder == 16);

  }
}

TEST_CASE ( "Test Expand function") {

  SECTION("Test Expand positive points"){
    //(0,0) & (3,6)
    rect2.Expand();
    p1 = rect2.get_p1();
    p2 = rect2.get_p2();

    REQUIRE(p1.x == -1);
    REQUIRE(p1.y == -1);
    REQUIRE(p2.x == 4);
    REQUIRE(p2.y == 7);

  }
  SECTION("Test Expand with negative points"){
    // (-4,-8) &(-2,0);
    rect4.Expand();
    p1 = rect4.get_p1();
    p2 = rect4.get_p2();

    REQUIRE(p1.x == -5);
    REQUIRE(p1.y == -9);
    REQUIRE(p2.x == -1);
    REQUIRE(p2.y == 1);

  }
}

TEST_CASE ( "Test shrink function") {

  SECTION("Test Shrink with positive points"){
    //(0,0) & (3,6)
    Rectangle rect21({0,0},{3,6});
    rect21.Shrink();
    p1 = rect21.get_p1();
    p2 = rect21.get_p2();

    REQUIRE(p1.x == 1);
    REQUIRE(p1.y == 1);
    REQUIRE(p2.x == 2);
    REQUIRE(p2.y == 5);

  }
  SECTION("Test Shrink with negative points"){
    // (-4,-8) &(-2,0);
    Rectangle rect41({-4,-8},{-2,0});
    rect41.Shrink();
    p1 = rect41.get_p1();
    p2 = rect41.get_p2();

    REQUIRE(p1.x == -3);
    REQUIRE(p1.y == -7);
    REQUIRE(p2.x == -3);
    REQUIRE(p2.y == -1);

  }

}
