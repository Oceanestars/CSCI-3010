#include "ElectoralMap.h"
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
Oceane Andreis
Homework 3
Date: October 13 2019

This program is my ElectoralMap.cpp.
I include map because I need to be able to have the map library.
I include Iterator because I use Iterator to iterate my map.
In this file, I set up my district and I set a random area to them.
I included math/h so I could use floor

*/

using namespace std;

int District::count_id = 1;


/**
    Return the right party

    @param enum of party
    @return the right party.

*/
string PartyStringify(Party p) //tested and working
{
    if (p == Party::Republican){

         return "Republican";
    }
    if (p == Party::Democrat){

         return "Democrat";
    }
    if (p == Party::None){

         return "None";
    }
		return "";
}

/**
    Return vector full of party
    we put enums into a vector
    @param nothing
    @return vector.

*/
vector<Party> Parties_vector()
{
    vector<Party> vec_party = {Party::Republican, Party::Democrat, Party::None};
    return vec_party;
}


/**
    Return nothing.(Constructor)
    This sets the area of each district to be a random number between 5-29
    and for the number of constituent to be random between the number 0-9
    @param nothing.
    @return nothing.

*/
District::District()
{
	  // srand(time(NULL));
	tmp_id = count_id;
	count_id +=1;
	area_ = (rand()% 25)+5; //5-29

	for(auto p : Parties_vector()){
 					 int r = (rand() % 9);
 					 constituents_[p] = r; //for each party we are giving it a random number between 0-9
 				 }

}

/**
    Return ostream

    @param District.
    @return ostream.

*/
std::ostream& operator<<(std::ostream& os, const District& temp){

	  map<Party, int> constituents = temp.get_constituent();
    string sentence = "Square mile: "+ to_string(temp.get_area()) + "\n";
    string sentence2="";
		for(map<Party, int>::iterator it = constituents.begin(); it != constituents.end(); it++){
			sentence2 += "[Party: "+PartyStringify(it->first)+"] : "+ to_string(it->second)+"\t";
		}
    os << sentence<<sentence2<<endl;

    return os;
}

/**
    Return nothing.(Constructor)

    @param nothing.
    @return nothing.

*/
ElectoralMap::ElectoralMap(){

   for(int i = 0; i < num_district ; i++){
       District* pointer = new District();
       district_map.insert(std::pair<int,District*>(pointer->get_id(),pointer));
   }

}

/**
    Return ostream

    @param ElectoralMap.
    @return ostream.

*/
std::ostream& operator<<(std::ostream& os, const ElectoralMap &map_election){
  map<int, District *> district = map_election.get_districts();

  for(map<int, District *>::iterator it = district.begin(); it != district.end(); it++){
      District *temp = it->second;
      os << "District "<< to_string(it->first) << ":\n";
      os << *(temp);
      os << endl;
  }
  return os;
}

/**
    Return an int
    Getting the district vote
    @param id
    @return an int.

*/
int ElectoralMap::get_districtvote(int id){

    float total_district_voters =0.0;
    float sum_district = 0.0;
    float votes_per_district =0.0;
    float total_district_votes = 5*num_district;

    vector<int> constituent_top;
    map<int, District *> district = get_districts();

    for(map<int, District *>::iterator it = district.begin(); it!=district.end(); ++it){
        District *d = it->second;
        map<Party, int> *constituent = d->get_voter();

        for (map<Party, int>::iterator it = constituent->begin(); it!=constituent->end(); ++it){
            sum_district += it->second;
            constituent_top.push_back(sum_district);
        }
    }
    int size = constituent_top.size();

    for(int i = 1; i < size; i++){
        total_district_voters +=constituent_top[i];
        if(id==i){
        	votes_per_district = ((constituent_top[i]* 1.0)/total_district_voters) * total_district_votes;
        }
    }
    return floor(votes_per_district);
}
