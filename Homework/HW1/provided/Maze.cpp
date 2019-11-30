/**
Oceane Andreis
Homework 1
Date: September 12 2019

This program is my maze.cpp
https://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
https://stackoverflow.com/questions/5019393/random-number-generator-c
http://www.cplusplus.com/reference/sstream/stringstream/str/
http://www.cplusplus.com/reference/ostream/ostream/operator-free/

I am including  the <string> so I can use to_string. I am using <vector> so I can use vectors.
I am including <cstdlib> and <ctime> to generate my random number(srand & rand)

*/

#include <iostream>
#include <vector>
#include "Player.h"
#include "Maze.h"
#include<cstdlib>
#include<ctime>
#include <string> //to_string


// using namespace std;


/**
    Return the unicode emojis.

    @param the SquareType enums.
    @return emojis which represent an element in the enum
*/
std::string SquareTypeStringify(SquareType sq){
  if(sq==SquareType::Wall){

    return "⚫️";

  }
  else if(sq==SquareType::Exit){

    return "🚪";

  }
  else if(sq==SquareType::Human){

    return "😃";

  }
  else if(sq==SquareType::Empty){

    return "⚪️";

  }
  else if(sq==SquareType::Enemy){

    return "😡";

  }
  else if(sq==SquareType::Treasure){

    return "🍣";

  }
  return "Didn't work";
}
// 1) Here are the rules for the board lay out:
// The rules for board layout are as follows:
// -  The player always starts in the upper left corner
// -  The exit is always in the lower right corner
// -  Walls appear with a 20% chance in the spaces
// that are not the beginning space or the exit
// -  Treasures appear with a 10% chance in spaces
// that are not walls, the beginning space, or the exit
// -  You can decide where the enemies start, so long
// as they do not start on a wall or the exit.
// 2) enemies based on user input unless you are implementing the extra credit



/**
    Constructor
    Here is where we want to set the position(randomly of the objects except human and exit)

    @param nothing
    @return nothing
*/

Board::Board(){

  std::srand(std::time(NULL));
  //I want to traverse through the array
  int random_num ;
  for (int i = 0; i < 4; i++){

    for (int j = 0; j < 4; j++){

      random_num = std::rand()%100+1;
      arr_[i][j] = SquareType::Empty;
      arr_[i][j] = SquareType::Empty;

      if (random_num <= 30 && random_num >10){

        arr_[i][j] = SquareType::Wall;

      }
      if (random_num <= 10 && arr_[i][j] == SquareType::Empty){

        arr_[i][j] = SquareType::Treasure;

      }

    }
  }

  arr_[0][2] = SquareType::Enemy;
  arr_[0][0] = SquareType::Human;
  arr_[3][3] = SquareType::Exit;
}

/**
    Return the current position.

    @param Position pos.
    @return the position.
*/
SquareType Board::get_square_value(Position pos) const{

  return arr_[pos.row][pos.col];

}

/**
    Return nothing.

    @param Position pos and SquareType value(access to the enum)
    @return nothing.
*/
void Board::SetSquareValue(Position pos, SquareType value){
  //similar as the getter above but we want to set the value so we equal the position to the value given
  arr_[pos.row][pos.col] = value;

}


/**
    Return vector of possible moves.

    @param Player *p
    @return vector of possible moves.
*/

// get the possible Positions that a Player could move to
// (not off the board or into a wall) (vector of position)
std::vector<Position> Board::GetMoves(Player *p){

  std::vector<Position> possible_move; //vector of the posible places our player can move
	Position var;
	var = p->get_position(); //to get current position
	var.row = var.row + 1; //to check the row below our current player
	if(p->get_position().row < 3 && get_square_value(var) != SquareType::Wall && get_square_value(var) != SquareType::Enemy){

		possible_move.push_back(var);

	}

	var = p->get_position();
	var.row = var.row - 1; // to check the row above our current player
	if(p->get_position().row > 0 && get_square_value(var) != SquareType::Wall && get_square_value(var) != SquareType::Enemy){

		possible_move.push_back(var);

	}

	var = p->get_position();
	var.col = var.col +1; //to check the column to the right of our player
	if(p->get_position().col < 3 && get_square_value(var) != SquareType::Wall && get_square_value(var) != SquareType::Enemy){

		possible_move.push_back(var);

	}

	var = p->get_position();
	var.col = var.col - 1; //to check the column to the left of our player
	if(p->get_position().col > 0 && get_square_value(var) != SquareType::Wall && get_square_value(var) != SquareType::Enemy){

		possible_move.push_back(var);

	}

	return possible_move;

}



  //------------------------------ <3
//   std::vector<Position> possibleMove;
//   Position var;
//   //Position possible_position;
//   var = p->get_position();
//   var.row = var.row+1;
//
//
//   if((p->get_position().row < 3 )&& (get_square_value(var) == SquareType::Empty || get_square_value(var) == SquareType::Treasure))
//   {
//     // possible_position.row = var.row+1;
//     // possible_position.col = var.col;
//     possibleMove.push_back(var); //down
//   }
//   var = p->get_position();
//   var.row = var.row-1;
//   if ((p->get_position().row > 0) && (get_square_value(var) == SquareType::Empty || get_square_value(var) == SquareType::Treasure))
//   {
//     // possible_position.row = var.row;
//     // possible_position.col = var.col+1;
//     possibleMove.push_back(var); //right
//   }
//   var = p->get_position();
//   var.col = var.col+1;
//   if ((p->get_position().col < 3) && (get_square_value(var) == SquareType::Empty|| get_square_value(var) == SquareType::Treasure))
//   {
//     // possible_position.row = var.row-1;
//     // possible_position.col = var.col;
//     possibleMove.push_back(var); //left
//   }
//   var = p->get_position();
//   var.col = var.col-1;
//   if ((p->get_position().col > 0 ) && (get_square_value(var) == SquareType::Empty|| get_square_value(var) == SquareType::Treasure))
//   {
//     // possible_position.row = var.row;
//     // possible_position.col = var.col-1;
//      possibleMove.push_back(var); //up
//   }
//
//   return possibleMove;
// }
//-------------------------------

/**
    Return true or false depending if the player moved.

    @param Player *p and Position Pos.
    @return .
*/
//	// Move a player to a new position on the board. Return
//	// true if they moved successfully, false otherwise.
//update board when the player moves
bool Board::MovePlayer(Player *p, Position pos){
// //
//   Position previous_pos;
//   previous_pos = p->get_position();
//
//   if(arr_[previous_pos.row][previous_pos.col] == SquareType::Exit && p->is_human()){
//       p->SetPosition(pos);
//       SetSquareValue(pos, SquareType::Human);
//       SetSquareValue(previous_pos, SquareType::Empty);
//       std::cout<<"CONGRATS! You got out!"<<std::endl;
//       p->ChangePoints(1);
//
//       return false;
//   }
//   if((arr_[pos.row][pos.col] == SquareType::Wall || arr_[pos.row][pos.col] == SquareType::Enemy) && (p->is_human())){
//           p->SetPosition(pos);
//           SetSquareValue(pos, SquareType::Human);
//           SetSquareValue(previous_pos, SquareType::Empty);
//           std::cout<<"GAME OVER"<<std::endl;
//           // p->ChangePoints(1);
//
//           return false;
//   }
//
//   if((arr_[pos.row][pos.col+1] == SquareType::Empty) || (arr_[pos.row][pos.col+1] == SquareType::Treasure)){
//
//     p->SetPosition(pos);
//     SetSquareValue(pos, SquareType::Human);
//     SetSquareValue(previous_pos, SquareType::Empty);
//     if(arr_[pos.row][pos.col+1] == SquareType::Treasure)
//     {
//         p->ChangePoints(100);
//     }
//     return true;
//
//   }
//
//   // LEFT
//
//   if((arr_[pos.row][pos.col-1] == SquareType::Empty) || (arr_[pos.row][pos.col-1] == SquareType::Treasure))
//   {
//     p->SetPosition(pos);
//     SetSquareValue(pos, SquareType::Human);
//     SetSquareValue(previous_pos, SquareType::Empty);
//     if(arr_[pos.row][pos.col-1] == SquareType::Treasure)
//     {
//         p->ChangePoints(100);
//     }
//     return true;
//
//   }
//
//   // DOWN
//
//   if((arr_[pos.row+1][pos.col] == SquareType::Empty) || (arr_[pos.row+1][pos.col] == SquareType::Treasure))
//   {
//     p->SetPosition(pos);
//     SetSquareValue(pos, SquareType::Human);
//     SetSquareValue(previous_pos, SquareType::Empty);
//     if(arr_[pos.row+1][pos.col] == SquareType::Treasure)
//     {
//         p->ChangePoints(100);
//     }
//     return true;
//
//   }
//
//
//   // UP
//
//   if((arr_[pos.row-1][pos.col] == SquareType::Empty) || (arr_[pos.row-1][pos.col] == SquareType::Treasure))
//   {
//     p->SetPosition(pos);
//     SetSquareValue(pos, SquareType::Human);
//     SetSquareValue(previous_pos, SquareType::Empty);
//     if(arr_[pos.row-1][pos.col] == SquareType::Treasure)
//     {
//         p->ChangePoints(100);
//     }
//     return true;
//
//   }
//
//   else
//   {
//   //std::cout << "try again" << std::endl;
//   return false;
//
//   }
// }

//--
//

    std::vector<Position> possible;
    possible = GetMoves(p);
    Position last = p->get_position();
    if(arr_[pos.row][pos.col] == SquareType::Exit && p->is_human()){
        p->SetPosition(pos);
        SetSquareValue(pos, SquareType::Human);
        SetSquareValue(last, SquareType::Empty);
        p->ChangePoints(1);
        return false;
    }
    else if((p->get_position().col <= get_cols() -1) && (p->get_position().col >= 0)
		&& (p->get_position().row <= get_rows() -1) && (p->get_position().row >= 0)
		&& (arr_[pos.row][pos.col] != SquareType::Wall))
	{
        int len = possible.size();
        for(int i = 0; i<len; i++){
            if (possible.at(i) == pos){
                p->SetPosition(pos);
                if(p->is_human()){
                    if(arr_[pos.row][pos.col] == SquareType::Empty || arr_[pos.row][pos.col] == SquareType::Treasure){
                        if(arr_[pos.row][pos.col] == SquareType::Treasure){
                            p->ChangePoints(100);
                        }
                        SetSquareValue(pos, SquareType::Human);
                        SetSquareValue(last, SquareType::Empty);
                        return true;
                    }
                }
                else if(arr_[pos.row][pos.col] != SquareType::Wall && !p->is_human()){
                    if(arr_[last.row][last.col] != SquareType::Exit){
                        if(arr_[pos.row][pos.col] == SquareType::Treasure){
                            p->ChangePoints(100);
                        }
                        SetSquareValue(pos, SquareType::Enemy);
                        SetSquareValue(last, SquareType::Empty);
                        return true;
                    }
                    else if(arr_[last.row][last.col] != SquareType::Exit){
                        SetSquareValue(last, SquareType::Empty);
                        return true;
                    }
                    else{
                        SetSquareValue(pos, SquareType::Enemy);
                        return true;
                    }
                }
                return false;
            }
        }
	}
	else
	{
		return false;
	}
    return false;
}

//---

  // arr_[p->get_position().row][p->get_position().col]=SquareType::Empty; //setting the position where the human was to empty
  // p->SetPosition(pos);
  // arr_[p->get_position().row][p->get_position().col]=SquareType::Human; //setting his new position to human
  	//return true;


/**
    Return exit.

    @param nothing
    @return exit.
*/
SquareType Board::GetExitOccupant(){

  return arr_[3][3];

}

/**
    Return the board.

    @param ostream and the board
    @return the board
*/
//print out our board
//friend there exist this func outside the class that is allowed to access private date and
//we don't need to include friend at the front of the function.
std::ostream& operator<<(std::ostream& os, const Board &b){
   //os is a string buffer

  for(int i = 0; i < 4; i++){

    for(int j = 0; j < 4; j++){

      os<<SquareTypeStringify(b.arr_[i][j]);
    }

    os<<std::endl;

  }

return os;

}

/**
    Return the board.

    @param
    @return the board
*/
Maze::Maze(){
//make a board_
  turn_count_ = 0;
  movesuccess_ = true;
  board_ = new Board();

}

/**
    Return the board.

    @param
    @return the board

*/
//	// initialize a new game, given one human player and
//	// a number of enemies to generate
//+++++++++++++++++
// void Maze::NewGame(Player *human, const int enemies){
//
//   Board b;
//   board_ = &b;
//   std::vector<Player*> newplayer;
//   newplayer.push_back(human);
//
//     for (int i = 0; i < enemies; i++)
//     {
//       std::stringstream s;
//       s <<"enemies ";
//       s << std::to_string(i);
//
//       Player *p = new Player(s.str(), false); //how to declare a new pointer, calls constructor and gets a pointer to new player object
//       newplayer.push_back(p);
//     }
//   players_ = newplayer;
// }

//+++++++++++++++++
/**
    Return nothing.

    @param Pointer to player and number of enemies)
    @return nothing.
*/
void Maze::NewGame(Player *human, const int enemies){

  Position newPlayer = {0,0};
	human->SetPosition(newPlayer); //set position for human
	players_.push_back(human);		//add player to vector

	int k =0;
	int randomCol;
	int randomRow;
	board_ = new Board();

	while(k < enemies){
    randomRow = (rand() % board_->get_rows()); //get random for row
		randomCol = (rand() % board_->get_cols()); //get random for column
		Position randomPos = {randomRow, randomCol}; //initialize the position struct with the random row and column values

//to check if the space on the board is empty, because we don't want to put an enemy where the player is
  if(board_->get_square_value(randomPos) == SquareType::Empty){

    std::string enemy ="enemy";
    enemy+=std::to_string(k);
		Player * newEnemy = new Player(enemy, false); //create player for enemy
		newEnemy->SetPosition(randomPos); //set random position in board
		board_->SetSquareValue(randomPos, SquareType::Enemy); //set enemy on empty square
		players_.push_back(newEnemy); //add enemy to vector player
		k++;	//increment
		}
	}
}

/**
    Return Nothing

    @param Point player
    @return Nothing

*/
// have the given Player take their turn
void Maze::TakeTurn(Player *p){

  std::vector<Position> possible;
  possible = board_->GetMoves(p);
  std::cout<<p->get_name()<<" can go: ";

  int x = possible.size();
  for(int i = 0; i < x; i++){
    std::cout<<p->ToRelativePosition(possible.at(i))<<" ";
  }
  std::cout<<std::endl;
  std::  cout<<"Please enter your choice: ";
  std::string choice;                  //Get the user's choice for where they want to move next.
  std::cin>>choice;
  std::string choice2 ="";
  int y = choice.length();
  bool init = false;
  for (int i = 0; i < y; ++i)
      choice2 += std::toupper(choice[i]);
  for(int i = 0; i < x; i++){
      if (choice2 == p->ToRelativePosition(possible.at(i))){
          movesuccess_=board_->MovePlayer(p, possible.at(i));
          init = true;
          turn_count_++;
      }
  }
  if(init == false){
    movesuccess_=false;
  }
}
  //------
  //
  // std::string choice;
  //
  // std::vector<Position> correct_choices = board_->GetMoves(p);
  // std::cout<<"You can go: ";
  // for(int i = 0; i < correct_choices.size(); i++)
  // {
  //
  //   std::cout<<p->ToRelativePosition(correct_choices.at(i))<<" ";
  // }
  // std::endl;
  // std::cout<<"Please enter your choice: ";
  // std::cin>>choice;
  //
  //
  //   for(int i = 0; i < correct_choices.size(); i++)
  //   {
  //
  //     if(choice == p->ToRelativePosition(correct_choices.at(i)))
  //   		{
  //   			//new_pos = correct_choices[i];
  //         board_->MovePlayer(p, correct_choices.at(i));
  //   		}
  //     }

  //--------
  //Position new_pos;
  //Position new_pos = p->get_position();;

  //board_->MovePlayer(p, correct_choices.at(i));
  //std::string choice;
  // std::cout<<"Please enter your choice: ";
  // std::cin>>choice;


  // if(board_->get_square_value(new_pos)== SquareType::Treasure)
  // {
  //   std::cout<<"Bish2"<<std::endl;
  //   p->ChangePoints(100);
  //   board_->MovePlayer(p, correct_choices.at(i));
  // }
  // // else if(board_->get_square_value(new_pos)== SquareType::Enemy)
  // // {
  // //     //call something?
  // // }
  // else if(board_->get_square_value(new_pos)==SquareType::Exit)
  // {
  // 	board_->MovePlayer(p, correct_choices.at(i));
  // }

  //std::string choice;

//-------------
  //   if(choice == "RIGHT")
	// {
	// 	if((board_->arr_[new_pos.row][new_pos.col+1] == SquareType::Empty) || (board_->arr_[new_pos.row][new_pos.col+1] == SquareType::Exit) || (arr_[new_pos.row][new_pos.col+1] == SquareType::Treasure))
	// 	{
	// 		new_pos.col = new_pos.col+1;
	// 		board_->SetSquareValue(new_pos,SquareType::Human);
	// 		arr_[new_pos.row][new_pos.col-1] = SquareType::Empty;
	// 		std::cout << "player successesfully moved" << std::endl;
	// 		p->SetPosition(new_pos);
  //
	// 	}
	// }
	// // LEFT
	// if(choice == "LEFT")
	// {
	// 	if((arr_[new_pos.row][new_pos.col-1] == SquareType::Empty) || (arr_[new_pos.row][new_pos.col-1] == SquareType::Treasure))
	// 	{
	// 		new_pos.col = new_pos.col-1;
	// 		board_->SetSquareValue(pos,SquareType::Human);
	// 		arr_[new_pos.row][new_pos.col+1] = SquareType::Empty;
	// 		std::cout << "player successesfully moved" << std::endl;
	// 		p->SetPosition(new_pos);
  //
	// 	}
	// }
	// // DOWN
	// if(choice == "DOWN")
	// {
	// 	if((arr_[new_pos.row+1][new_pos.col] == SquareType::Empty) || (arr_[new_pos.row+1][new_pos.col] == SquareType::Exit) || (arr_[new_pos.row+1][new_pos.col] == SquareType::Treasure))
	// 	{
	// 		new_pos.row = new_pos.row+1;
	// 		board_->SetSquareValue(new_pos,SquareType::Human);
	// 		arr_[new_pos.row-1][new_pos.col] = SquareType::Empty;
	// 		std::cout << "player successesfully moved" << std::endl;
	// 		p->SetPosition(new_pos);
  //
	// 	}
	// }
  //
	// // UP
	// if(choice == "UP")
	// {
	// 	if((arr_[new_pos.row-1][new_pos.col] == SquareType::Empty) || (arr_[new_pos.row-1][new_pos.col] == SquareType::Treasure))
	// 	{
	// 		new_pos.row = new_pos.row-1;
	// 		board_->SetSquareValue(new_pos,SquareType::Human);
	// 		arr_[new_pos.row+1][new_pos.col] = SquareType::Empty;
	// 		std::cout << "player successesfully moved" << std::endl;
	// 		p->SetPosition(new_pos);
  //
	// 	}
	// }
  //
	// else
	// {
	// 	std::cout << "try again" << std::endl;
  //
	// }


  //}

  /**
      Return the next player.

      @param nothing
      @return the next player.
  */
	Player * Maze::GetNextPlayer(){
    //std::cout<<players_.size();
    Player * next = players_[turn_count_];
    // std::cout<<players_.size();
    if (turn_count_ == 2){

        turn_count_ = 0;

    }
    else{

      turn_count_++;

    }
      return next;
    // return players_.at(turn_count_ % players_.size());
  }

/**
    Return true if the game is over.

    @param Nothing
    @return false if the game is not over

*/
bool Maze::IsGameOver(){

  if(board_->GetExitOccupant() == SquareType::Human){
    return true;
  }
  return false;
}

/**
    Return the name and number of point.

    @param Nothing.
    @return the name and number of point.

*/
std::string Maze::GenerateReport(){

  for(int i=0; i<players_.size(); i++){

		std::cout<<players_[i]->get_name() <<" has ";
		std::cout<<players_[i]->get_points()<<" points."<<std::endl;

	}
}

/**
    Return the maze.

    @param ostream and maze
    @return the maze.
*/
std::ostream& operator<<(std::ostream& os, const Maze &m){

  for(int i=0; i<4; i++){

		for(int j=0; j<4; j++){

			Position temp;
			temp.row = i;
			temp.col = j;
			std::string a = SquareTypeStringify(m.board_->get_square_value(temp));
			os << a <<" ";

		}
		os << std::endl;
	}
	return os;
}
