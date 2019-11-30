/**
Oceane Andreis
Homework 2
Date: October 1 2019

This program is my TestTypes.h


*/
//
// #ifndef _TESTTYPES_H_
// #define _TESTTYPES_H_

#include <vector>
#include <iostream>


enum class SquareType { Wall, Exit, Empty, Human, Enemy, Treasure };

struct Book {
    std::string title;
    std::string author;
    int book_num;
};

class Point {

public:
   Point();
   friend bool operator < (const Counter c, const Counter c);

 private:

};
