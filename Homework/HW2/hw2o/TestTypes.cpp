
/**
Oceane Andreis,  Abby Nay
Homework 2
Date: October 1 2019

This program is my TestTypes.cpp.
I have my point constructors and my overload function.
//https://www.learncpp.com/cpp-tutorial/96-overloading-the-comparison-operators/


*/

#include "TestTypes.h"
#include <iostream>

using namespace std;

//Constructor
Point::Point(){

}

/**
    Return nothing.(Constructor)

    @param x and y.
    @return nothing.

*/
Point::Point(int x, int y)
{
    x_ = x;
    y_ = y;
}

/**
    Return os.

    @param ostream and Point.
    @return os.

*/
ostream& operator<<(ostream& os, const Point &p1){
    os<<"("<<p1.x_<<","<<p1.y_<<")";
    return os;
}
