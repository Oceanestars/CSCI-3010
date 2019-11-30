/**
Oceane Andreis , Abby Nay
Homework 2
Date: October 1 2019

This program is my test.cpp.
I have test cases for all my functions
*/
//insert, string, int, point, vector

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include "TestTypes.h"
#include "Counter.hpp"
#include "iostream"

using namespace std;

TEST_CASE("Increment", "[Increment]")
{

	SECTION("Increase the value by 1 (string)") {
		Counter<string> a;
		a.Insert("dog");
		a.Insert("dog");
		a.Insert("cat");
		string s = "dog";
		a.Increment(s, 5);
		map<std::string,int> m;
		m = a.GetMap();
		REQUIRE(m.find("dog")->second == 7);
		REQUIRE(m.find("cat")->second == 1);
}
  //
 	// SECTION("Increase the value by 1 (enum)") {
	// 	Counter<SquareType> b;
	// 	SquareType s = SquareType::Wall;
	// 	b.Increment(s);
	// 	map<SquareType,int> m;
	// 	m = c.GetMap();
	// 	REQUIRE(m.find(Wall)->second == 2);
	// 	REQUIRE(m.find(Human)->second == 1);
	// }

	SECTION("Increase the value by 5 (int)") {
		Counter<int> c;
		c.Insert(1);
		c.Insert(5);
		c.Insert(1);
		c.Insert(5);
		int i = 5;
		c.Increment(i);
		c.Increment(i, 4);
		map<int,int> m;
		m = c.GetMap();
		REQUIRE(m.find(5)->second == 7);
	}
  //
  //   SECTION("Increase the value by 1 (struct)") {
	// 	Book b1= {"Hunger Games", "Collins"};
	// 	Book b2 = {"Jane Eyre", "Bronte"};
	// 	Book b3 = {"Jane Eyre", "Bronte"};
	// 	Counter<Book> b;
	// 	b.Insert(b1);
	// 	b.Insert(b2);
	// 	b.Insert(b3);
	// 	map<Book,int> m;
	// 	m = b.GetMap();
	// 	b.Increment(b1);
	// 	REQUIRE(m.find(b1)->second==2);
	// 	REQUIRE(m.find(b2)->second==2);
  //
	// }

	SECTION( "Decrease the value by 1 (vector)"){
			vector<int> v = { 10, 20,20, 30 };
			Counter<int> cv(v);
			cv.Increment(10);
			map<int,int> m;
			m = cv.GetMap();
			REQUIRE(m.find(10)->second == 2);
			REQUIRE(m.find(20)->second == 2);
	}
}


TEST_CASE("Decrement", "[Decrement]")
{

	SECTION("Decreases the value by 1 (string)") {
		Counter<string> a;
		a.Insert("dog");
		a.Insert("dog");
		a.Insert("cat");
		string s = "dog";
		a.Decrement(s, 2);
		map<std::string,int> m;
		m = a.GetMap();
		REQUIRE(m.find("dog")->second == 0);
		REQUIRE(m.find("cat")->second == 1);
}

  //   SECTION("Decreases the value by 1 (enum)") {
	// 		Counter<SquareType> b;
	// 		SquareType s = SquareType::Wall;
	// 		b.Decrement(s);
	// 		map<SquareType,int> m;
	// 		m = c.GetMap();
	// 		REQUIRE(m.find(Wall)->second == 0);
	// 		REQUIRE(m.find(Human)->second == 1);
	// }

	SECTION("Decreases the value by 5 (int)") {
		Counter<int> c;
		c.Insert(1);
		c.Insert(5);
		c.Insert(1);
		c.Insert(5);
		c.Insert(5);
		c.Insert(5);
		int i = 5;
		c.Decrement(i);
		c.Increment(i, 2);
		map<int,int> m;
		m = c.GetMap();
		REQUIRE(m.find(5)->second == 5);
	}

	// SECTION("Decreases the value by 1 (struct)") {
	// 	Book b1= {"Hunger Games", "Collins"};
	// 	Book b2 = {"Jane Eyre", "Bronte"};
	// 	Book b3 = {"Jane Eyre", "Bronte"};
	// 	Counter<Book> b;
	// 	b.Insert(b1);
	// 	b.Insert(b2);
	// 	b.Insert(b3);
	// 	map<Book,int> m;
	// 	m = b.GetMap();
	// 	b.Decrement(b2);
	// 	REQUIRE(m.find(b1)->second==1);
	// 	// REQUIRE(m.find(b2)->second==1);
	// }

	SECTION( "Decrease the value by 1 (vector)"){
			vector<int> v = { 10, 20,20, 30 };
			Counter<int> cv(v);
			cv.Increment(10);
			cv.Decrement(20);
			map<int,int> m;
			m = cv.GetMap();
			REQUIRE(m.find(10)->second == 2);
			REQUIRE(m.find(20)->second == 1);
	}
}



TEST_CASE ( "Insert", "[Counter]")
{
	SECTION( "Insert strings" ){
        Counter<string> c;
        c.Insert("dog");
        c.Insert("dog");
        c.Insert("cat");
        map<std::string,int> m;
        m = c.GetMap();
        REQUIRE(m.find("dog")->second == 2);
        REQUIRE(m.find("cat")->second == 1);
	}
    SECTION( "Insert integers and initialize from a vector"){
        vector<int> v = { 10, 20, 30 };
        Counter<int> cv(v);
        cv.Insert(3);
        cv.Insert(20);
        map<int,int> m;
        m = cv.GetMap();
        REQUIRE(m.find(3)->second == 1);
        REQUIRE(m.find(20)->second == 2);
    }
    SECTION( "Insert Point Class"){
        Point p1(1,1);
        Point p2(2,3);
        Point p3(1,1);
        Counter<Point> p;
        p.Insert(p1);
        p.Insert(p2);
        p.Insert(p3);
        map<Point,int> m;
        m = p.GetMap();
        REQUIRE(m.find(p1)->second ==2);
        REQUIRE(m.find(p2)->second ==1);
    }
    // SECTION( "Insert Book Struct"){
    //     Book b1= {"Hunger Games", "Collins"};
    //     Book b2 = {"Jane Eyre", "Bronte"};
    //     Book b3 = {"Jane Eyre", "Bronte"};
    //     Counter<Book> b;
    //     b.Insert(b1);
    //     b.Insert(b2);
    //     b.Insert(b3);
    //     map<Book,int> m;
    //     m = b.GetMap();
    //     REQUIRE(m.find(b1)->second==1);
    //     REQUIRE(m.find(b2)->second==2);
    // }
}


TEST_CASE("Most Common", "[Most Common]"){

	SECTION("Integers"){
			Counter<int> c;
			c.Insert(1);
			c.Insert(5);
			c.Insert(1);
			c.Insert(5);
			c.Insert(5);
			map<int,int> m;
			m = c.MostCommon(1);
			REQUIRE(m.begin()->first == 5);
	}
	SECTION("String"){
			Counter<string> a;
			a.Insert("dog");
			a.Insert("dog");
			a.Insert("dog");
			a.Insert("cat");
			map<std::string,int> m;
			m = a.MostCommon(1);
			REQUIRE(m.begin()->first == "dog");
	}
	SECTION("Point class"){
			Point p2(2,3);
			Point p3(2,3);
			Point p4(1,1);
			Counter<Point> p;
			p.Insert(p2);
			p.Insert(p3);
			p.Insert(p4);
			map<Point,int> m;
			m = p.MostCommon(1);
			REQUIRE(m.begin()->first == p2);
	}
}


TEST_CASE("Normalize Weights", "[counter]"){
    SECTION("Normalize Strings"){
        Counter<string> a;
				a.Insert("dog");
				a.Insert("dog");
				        a.Insert("dog");
				a.Insert("cat");
				map<std::string,double> m;
				m = a.NormalizeWeights();
				REQUIRE(m.find("dog")->second == 0.75);
				REQUIRE(m.find("cat")->second == 0.25);
				    }
    SECTION("Normalize ints"){
        Counter<int> c;
				c.Insert(1);
				c.Insert(5);
				c.Insert(1);
				c.Insert(5);
				c.Insert(5);
				map<int,double> m;
				m = c.NormalizeWeights();
				REQUIRE(m.find(5)->second == 0.60);
        REQUIRE(m.find(1)->second == 0.40);
    }
    SECTION("Normalize class"){
        Point p1(1,1);
        Point p2(2,3);
        Point p3(2,3);
        Point p4(1,1);
        Counter<Point> p;
        p.Insert(p1);
        p.Insert(p2);
        p.Insert(p3);
        p.Insert(p4);
        map<Point,double> m;
        m = p.NormalizeWeights();
        REQUIRE(m.find(p1)->second ==0.5);
        REQUIRE(m.find(p2)->second ==0.5);
    }
}

TEST_CASE("TotalCount"){
    SECTION("Total count on integer Counter"){
        Counter<int> c;
				c.Insert(1);
				c.Insert(5);
				c.Insert(1);
				c.Insert(5);
				c.Insert(5);
        REQUIRE(c.TotalCount()==5);
    }
    SECTION("Total count on Point class"){
        Point p1(1,1);
        Point p2(2,3);
        Point p3(2,3);
        Point p4(1,1);
        Counter<Point> p;
        p.Insert(p1);
        p.Insert(p2);
        p.Insert(p3);
        p.Insert(p4);
        REQUIRE(p.TotalCount()==4);
    }
    SECTION("Total count on strings"){
        Counter<string> a;
				a.Insert("dog");
				a.Insert("dog");
        a.Insert("dog");
				a.Insert("cat");
        REQUIRE(a.TotalCount()==4);
    }
}

TEST_CASE("Remove function"){
    SECTION("Remove an integer"){
        Counter<int> c;
        c.Insert(1);
				c.Insert(5);
				c.Insert(1);
				c.Insert(5);
				c.Insert(5);
        c.Remove(5);
        REQUIRE(c.TotalCount()==2);
        c.Remove(1);
        REQUIRE(c.TotalCount()==0);
    }
    SECTION("Remove a string"){
        Counter<string> a;
				a.Insert("dog");
				a.Insert("dog");
        a.Insert("dog");
				a.Insert("cat");
        a.Remove("cat");
        REQUIRE(a.TotalCount()==3);
    }
    SECTION("Remove a class"){
        Point p1(1,1);
        Point p2(2,3);
        Point p3(2,3);
        Point p4(1,1);
        Counter<Point> p;
        p.Insert(p1);
        p.Insert(p2);
        p.Insert(p3);
        p.Insert(p4);
        p.Remove(p1);
        REQUIRE(p.TotalCount()==2);
    }
}

TEST_CASE("Range"){
    SECTION("Range (int)"){
        Counter<int> a;
        a.Insert(1);
        a.Insert(5);
        a.Insert(1);
        a.Insert(5);
        a.Insert(5);
REQUIRE(a.Range(0,5)==5);
    }
    SECTION("Range (string)"){
        Counter<string> a;
        a.Insert("dog");
        a.Insert("dog");
        a.Insert("dog");
        a.Insert("cat");
        REQUIRE(a.Range("cat","dog")==4);
    }
    SECTION("Range (class)"){
        Point p1(1,1);
        Point p2(2,3);
        Point p3(4,4);
        Point p4(1,1);
        Counter<Point> p;
        p.Insert(p1);
        p.Insert(p2);
        p.Insert(p3);
        p.Insert(p4);
        REQUIRE(p.Range(p1,p2)==3);
    }
}

TEST_CASE("Keys"){
    SECTION("String Keys"){
        Counter<string> a;
        a.Insert("cat");
        a.Insert("dog");
        a.Insert("dog");
        a.Insert("dog");
        std::vector<string> v;
        v=a.Keys();
        REQUIRE(v[0] =="cat");
    }
}

TEST_CASE("Values"){
    SECTION("Int Values"){
        Counter<string> a;
        a.Insert("cat");
        a.Insert("dog");
        a.Insert("dog");
        a.Insert("dog");
        std::vector<int> v;
        v=a.Values();
        REQUIRE(v[0] ==1);
    }
}
