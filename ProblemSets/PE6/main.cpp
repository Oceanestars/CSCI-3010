#include <iostream>
#include "Society.h"

/**
Oceane Andreis
Problem Set 6
Date: September 30 2019

This is my main file. I asks the user to input the city id, the population number, and the city name.
The I ask them how much they want to grow the population.
*/

// Edit any of Society.h, Society.cpp and this file in your refactoring
// In addition to the refactoring tasks:
// When you are done, this program should be able to easily run for a different number
// of cities and you should be able to observe the growth in the cities for a given number of
// cycles of growth

using namespace std;
int main() {

    string city_name="";
    int population_num;
    int id;
    string choice;
    int num;
    Society s;
    bool end_choice=true;
    int keep_track=1;

while (end_choice == true) {
  cout<<"Do you want to enter a city? yes or no"<<endl;
  cin >> choice;
  if(choice == "yes" || choice =="Yes")
  {

        cout<<"Enter id of city: ";
        cin >> id;

        cout<<"Enter the population number: ";
        cin >> population_num;

        cout<<"Enter the city name: ";
        std::cin.ignore();
        getline(std::cin, city_name);

        s.AddCity(id, population_num, city_name);
        s.last_key = keep_track;
        keep_track++;

  }
  else{
    end_choice = false;
  }
}
    cout<<endl;
    cout<<"What do you want the growth number to be? "<<endl;
    cin >> num;
    cout<<s<<endl;

        for(int i=0; i<num; i++)
        {

          s.GrowCities();
          cout<<s<<endl;
        }

        cout<<endl;

    return 0;
}
