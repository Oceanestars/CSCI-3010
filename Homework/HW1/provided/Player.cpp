/**
Oceane Andreis
Homework 1
Date: September 12 2019

This program is my player.cpp

*/
// The arrow operator (->) is a dereference operator that is used exclusively with pointers to objects that have members.
// This operator serves to access the member of an object directly from its address.

#include <iostream>
#include <vector>
#include "Player.h"
#include "Maze.h"
#include <string> //to_string


/**
    Return nothing.

    @param name of the character and if it's human or not.
    @return nothing but sets the parameter equal to the private variable of the class Player.
*/
Player::Player(const std::string name, const bool is_human){

    name_ = name;
    is_human_= is_human;
    points_ = 0;

}
/**
    Return nothing.

    @param x point.
    @return nothing but add one to point.
*/
void Player::ChangePoints(const int x){
  
    points_ += x;
}

/**
    Return nothing.

    @param Position class objects.
    @return nothing but .
*/
void Player::SetPosition(Position pos){

    pos_.row = pos.row;
  	pos_.col = pos.col;

}

//	// You may want to implement these functions as well
//	// ToRelativePosition is a function we used to translate positions
//	// into directions relative to the player (up, down, etc)

/**
    Return the choices given to the user.

    @param Position class objects.
    @return choice.
*/

std::string Player::ToRelativePosition(Position other){

  Position current = pos_;
  if(current.row == other.row){
      if(other.col == current.col + 1){
          return "Right";
      }
      else{
          return "Left";
      }
    }
  else{
      if(other.row<=current.row){
          return "Up";
      }
      else{
          return "Down";
      }
  }
  return "failed";
}

/**
    Return a string.

    @param nothing.
    @return a string with the name of the player and the number of points they have.
*/

  std::string Player::Stringify(){

    std::string sentence = name_ +" has "+ std::to_string(points_)+" points.";

    return sentence;

	}
