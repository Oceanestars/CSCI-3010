/**
Oceane Andreis,  Abby Nay
Homework 2
Date: October 1 2019

This program is my TestTypes.h
it includes vector because I'm also declaring vectors.
I have enums, struct, and class declared.

*/

// #ifndef _TESTTYPES_H_
// #define _TESTTYPES_H_

#include <vector>
#include <iostream>

using namespace std;


enum class SquareType { Wall, Exit, Empty, Human, Enemy, Treasure };
// inline ostream& operator<<(ostream& os, SquareType a){
//
//   switch (a) {
// 		case (SquareType::Human):
// 			os << "Human";
// 			break;
// 		case (SquareType::Wall):
// 			os << "Wall";
// 			break;
// 		case (SquareType::Exit):
// 			os << "Exit";
// 			break;
// 		case (SquareType::Empty):
// 			os << "Empty";
// 			break;
// 		case (SquareType::Treasure):
// 			os << "Treasure";
// 			break;
// 		case (SquareType::Enemy):
// 			os << "Enemy";
// 			break;
// 	}
//
//     return os;
// }


struct Book {
    std::string title;
    std::string author;
    int book_num;

    friend bool operator==(const Book& b1, const Book& b2){
        return (b1.title == b2.title && b1.author == b2.author);
    }
    friend ostream& operator<<(ostream& os, const Book &b1){
        os<<b1.title<<" by "<<b1.author;
        return os;
    }
    friend bool operator < (const Book &b1, const Book &b2){
        return (b1.title < b2.title || b1.author < b2.author);
    }
};

class Point {

public:
    Point();
    Point(int x, int y);
    friend bool operator < (const Point &p1, const Point &p2){
        return (p1.x_ < p2.x_ || p1.y_ < p2.y_);
    }
    friend bool operator <= (const Point &p1, const Point &p2){
        return (p1.x_ <= p2.x_ || p1.y_ <= p2.y_);
    }
    friend bool operator >= (const Point &p1, const Point &p2){
        return (p1.x_ >= p2.x_ || p1.y_ >= p2.y_);
    }
    friend bool operator== (const Point &p1, const Point &p2){
        return (p1.x_ == p2.x_ && p1.y_ == p2.y_);
    }
    int x_;
    int y_;

};
