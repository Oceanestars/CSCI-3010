/**
Oceane Andreis
Problem Set 2
Date: September 2 2019

This program is my Point.cpp.
Point.cpp holds my methods.
I have a method(distance)that calculates the euclidian distance between 2 points and
I have a method(translate) that changes the coordinate up a certain number(or down).
These functions will work regardless of the number of dimension provided.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include "Point.h"
//https://sciencing.com/radius-circle-midpoint-7867864.html
//http://www.cplusplus.com/reference/cmath/pow/

using namespace std;


//Constructor
//Initializing the variable to zero
Point::Point()
{
//    coordinatelist=0;
}


Point::Point(std::vector<int>n)
{
  coordinatelist = n;

}

//Deconstructor
Point::~Point()
{

}

//Getters & Setters
/**
    Return the list of coordinates.

    @param none.
    @return the list of coordinates.
*/
vector<int> Point::get_alln()
{
    return coordinatelist;
}


/**
    Return nothing.

    @param x point.
    @return nothing.
*/
void Point::set_n(int element,int newvalue)
{
     coordinatelist[element-1] = newvalue; //in main we could call set_n and change an element in the vector
     //the newvalue is the value we want to replace the current value by (element-1 is the position, it decides which element to change)
}

/**
    Return the size of our vector which holds our coordinates.

    @param  None.
    @return The number of our dimensions.
*/
int Point::ndimension()
{

  return coordinatelist.size();

}
// Distance & Translate Methods

/**
    Return the distance between two points by calculating the euclidean distance.

    @param  vector, list of coordinate.
    @return the distance between two points.
*/

int Point::distance(std::vector<int>coordinatelist2)
{
    // Subtract x,y,z coordinate from the first point to the second point
    int newcoordinate = 0;


    for (int i = 0; i<coordinatelist2.size(); i++)
    {
        newcoordinate += pow((coordinatelist2[i]-coordinatelist[i]),2);
        // type pow( type base,type exponent)
         //Square all the new coordinates and add them together
    }

   // take the square root

    double square = sqrt(newcoordinate);
    return square;

}

/**
    Return nothing, but it changes the coordinates by a positive number or then a negative number.

    @param number, the number I want to translate the coordinates by.
    @return nothing.
*/

void Point::translate(int change)
{
    for(int i = 0; i < coordinatelist.size(); i++)
    {
        coordinatelist[i] = coordinatelist[i]+change;
    }

}
