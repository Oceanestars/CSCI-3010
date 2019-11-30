#ifndef _TEXT_UI_H_
#define _TEXT_UI_H_
#include "Election.h"
#include <iostream>
#include <vector>

/**
Oceane Andreis
Homework 3
Date: October 13 2019

This program is my TextUI.h.

*/

using namespace std;

class TextUI {
public:

  TextUI();
  string MainMenu();
  void RouteChoice(string choice);

private:
  vector<string> main_menu;
};

#endif  // _TEXT_UI_H_
