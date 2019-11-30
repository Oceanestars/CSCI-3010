#include "ElectoralMap.h"
#include "Election.h"
#include "TextUI.h"
#include <iostream>
#include <vector>


/**
Oceane Andreis
Homework 3
Date: October 13 2019

This program is my main.cpp.
Used pe7 main as a resource to help me with TextUI & main

*/

using namespace std;


int main(int argc, char *argv[])
{
    srand(time(NULL));
    //Testing purposes:
    // ElectoralMap &one = ElectoralMap::GetInstance();
    // cout<<one<<endl;

    TextUI main_Menu; //create TextUI object;
    string choice; //declare the string for choice
    while(choice!= "0")
    {
        choice = main_Menu.MainMenu();
        main_Menu.RouteChoice(choice); 

    }
    return 0;

}
