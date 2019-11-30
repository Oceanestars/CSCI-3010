/**
Oceane Andreis
Problem Set 2
Date: September 2 2019

This program is my Point.h.
Point.h is my header file.
I have my public section and my vector. In my public I have my methods, muttator, accessor, constructor, and deconstructor.
*/

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>

class Point
{

      std::vector<int> coordinatelist;

    public:

        //Constructor
        Point();

        Point(std::vector<int> list);

        //Deconstructor
        ~Point();

        //Getter
        std::vector<int> get_alln(); //function that returns a vector

        //Setter
        void set_n(int element, int newval);

        //Math Function
        int ndimension(); //prints out the number of dimension
        int distance(std::vector<int> coordinatelist2);
        void translate(int change);

};

#endif
