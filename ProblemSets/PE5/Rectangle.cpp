



/**
Oceane Andreis
Partner: Mikayla Pickett
Problem Set 5
Date: September 25 2019

This program is my rectangle.cpp.
*/

#include "Rectangle.h"
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;


/**
    Return nothing.

    @param two points.
    @return nothing.

		p1 is the lower left corner
	  p2 is the upper right corner
		Bug: this didn't work if the left and right point were reversed
*/
Rectangle::Rectangle(Point p1, Point p2){

	if((p1.x < p2.x) && (p1.y < p2.y)){
        p1_ = p1;
        p2_ = p2;
    }
	else if((p1.x > p2.x) && (p1.y > p2.y)){
        p1_ = p2;
        p2_ = p1;
    }
}


/**
    Return the width.

    @param nothing.
    @return the width.

		get the width of the rectangle
		between p1.x and p2.x
*/
int Rectangle::GetWidth(){

	return p2_.x - p1_.x;
}

/**
    Return the height of the rectangle.

    @param nothing.
    @return the height.

		get the height of the rectangle
		between p2.y and p2.y
*/
int Rectangle::GetHeight(){

	return p2_.y - p1_.y;
}


/**
    Return true or false if the rectangle overlap.

    @param a rectangle.
    @return nothing.

		returns true iff this rectangle shares any points with the other one
		Bug: if a small rectangle was inside a big rectangle it wouldn't work
*/
bool Rectangle::Overlaps(Rectangle& other){

         if(((other.p1_.x > p1_.x) && (other.p2_.x > p2_.x)) && (((other.p1_.y < p1_.y) && (other.p2_.y < p2_.y))||((other.p1_.y > p1_.y) && (other.p2_.y > p2_.y))||((other.p1_.y == p1_.y) && (other.p2_.y == p2_.y))))
	{
		return false;
	}
        if(((other.p1_.x < p1_.x) && (other.p2_.x < p2_.x)) && (((other.p1_.y < p1_.y) && (other.p2_.y < p2_.y))||((other.p1_.y > p1_.y) && (other.p2_.y > p2_.y))||((other.p1_.y == p1_.y) && (other.p2_.y == p2_.y))))
	{
		return false;
	}
      if(((other.p1_.x == p1_.x) && (other.p2_.x == p2_.x)) && (((other.p1_.y > p1_.y) && (other.p2_.y > p2_.y))||((other.p1_.y < p1_.y) && (other.p2_.y < p2_.y))))
	{
		return false;
	}

	else
	{
		return true;
	}
}

/**
    Return the area of this rectangle.

    @param nothing.
    @return the area.
*/
int Rectangle::CalculateArea()
{
	int width = GetWidth();
	int height = GetHeight();
	int area = width * height;
	return area;
}

/**
    Return nothing.

    @param nothing..
    @return nothing.

		moves the bottom left coordinate down one and to the left one
		moves the upper right coordinate up one and to the right one
*/
void Rectangle::Expand()
{
	p1_.y = p1_.y - 1;
	p1_.x = p1_.x - 1;

	p2_.y = p2_.y + 1;
	p2_.x = p2_.x + 1;


}

/**
    Return nothing.

    @param nothing.
    @return nothing.

		moves the bottom left coordinate up one and to the right one
		moves the upper right coordinate down one and to the left one

*/
void Rectangle::Shrink()
{
	p1_.y = p1_.y + 1;
	p1_.x = p1_.x + 1;

	p2_.y = p2_.y - 1;
	p2_.x = p2_.x - 1;
}

/**
    Return nothing.

    @param x point.
    @return nothing.
*/
unsigned int Factorial( unsigned int number ){
	int sum = number;
	if (number == 0 || number == 1){
		return 1;
	}

	else {
		while (number > 1){
			sum = sum * (number - 1);
			cout << sum << endl;
			number--;
		}
		return sum;
	}
}
