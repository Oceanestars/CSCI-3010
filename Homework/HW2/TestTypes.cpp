
/**
Oceane Andreis
Homework 2
Date: October 1 2019

This program is my TestTypes.cpp.
pair= like tuple
pair<T,string> p = {1,"hi"}
p.first(would equal 1)
map=
To implement my class in TestTypes.h
//when doing custom class when inserting in dictionary make sure it has a less than operator
//like bool asdf <

*/

#include "TestTypes.h"
#include <iostream>

using namespace std;

//Constructor

Point::Point()
{

}

//https://www.learncpp.com/cpp-tutorial/96-overloading-the-comparison-operators/
bool operator <(const &book, const &book2)
{
  return 0;
}


//Example
// bool operator== (const Car &c1, const Car &c2)
// {
//     return (c1.m_make== c2.m_make &&
//             c1.m_model== c2.m_model);
// }
