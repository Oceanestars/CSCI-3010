#include "TextUI.h"
#include "ElectoralMap.h"
#include "Election.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

/**
Oceane Andreis
Homework 3
Date: October 13 2019

This program is my TextUI.cpp.
This file includes my main menu and a route choice for the user

*/

using namespace std;

TextUI::TextUI() {

    main_menu.push_back("direct");
    main_menu.push_back("representative");
    main_menu.push_back("0");
}

/**
    Return a string
    Getting the prompt set up
    @param nothing
    @return a string

*/
std::string TextUI::MainMenu() {
    cout <<"What kind of election should we have (direct or representative, 0 to stop)?";
    string user_choice;
    cin >> user_choice;
    for(int i=0; i<main_menu.size(); i++){
        if(main_menu[i]==user_choice){
            return main_menu[i];
        }
    }
    if(user_choice != "direct" || user_choice != "representative" || "0" ){
        cout << "Enter direct or representative, 0 to stop " <<endl;
        cin >> user_choice;
        for(int i=0; i<main_menu.size(); i++){
            if(main_menu[i]==user_choice){
                return main_menu[i];
            }
        }
    }
    return "";
}


/**
    Return nothing
    decides between direct and representative
    @param user choice
    @return nothing

*/
void TextUI::RouteChoice(string choice)
{
    if(choice=="direct"){
        Election election;
        election.Display();
        election.PrintCandidate();
        election.get_vote();

    }
    else if(choice=="representative"){
        RepresentativeElection representative;
        representative.Display();
        representative.PrintCandidate();
        representative.get_vote();

    }


}
