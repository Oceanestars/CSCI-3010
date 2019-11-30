/**
Oceane Andreis
Homework 1
Date: September 12 2019

This program is my main.cpp.
I am including my header file and testing my maze.

*/

#include <iostream>
#include <vector>
#include "Player.h"
#include "Maze.h"


int main()
{

  Player *one= new Player("Oceane",true);
  Maze game = Maze();

  game.NewGame(one,1);

  std::cout<<game<<std::endl;
  Player *next = one;
  while(game.IsGameOver()==false)
  {
    game.TakeTurn(next);
    std::cout<<game<<std::endl;
    next = game.GetNextPlayer();
   }
  std::cout<<game.GenerateReport();
  std::cout<<game.IsGameOver();

return 0;

}
