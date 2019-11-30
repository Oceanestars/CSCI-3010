#ifndef _ELECTORALMAP_H_
#define _ELECTORALMAP_H_

#include <iostream>
#include <string>
#include <map>


/**
Oceane Andreis
Homework 3
Date: October 13 2019

This program is my ElectoralMap.h.
I have my class district, electoralmap declared here.

*/

using namespace std;


enum class Party { Republican, Democrat, None};

string PartyStringify(Party p);
vector<Party> Parties_vector();

class District {
public:
    District();

    int get_area() const{
      return area_;
    }
    int get_id(){
      return tmp_id;
    }

    map<Party, int> get_constituent() const
    {
        return constituents_;
    }
    map<Party, int> * get_voter()
   {
       return &constituents_;
   }


    friend std::ostream& operator<<(std::ostream& os, const District& d);

private:

    int tmp_id;
    static int count_id;
    int area_;
    map<Party, int> constituents_;


};

  //singleton
class ElectoralMap{
public:

    static ElectoralMap& GetInstance(){
        static ElectoralMap instance;
        return instance;
    }


    map<int, District*> get_districts() const{
        return district_map;
    };

    // District * get_district(const int id)
    // {
    //     return district_map[id];
    // };

    int get_districtvote(int id);

    friend std::ostream& operator<<(std::ostream& os, const ElectoralMap &map_election);

    ElectoralMap(ElectoralMap const&) = delete;
    void operator=(ElectoralMap consts) = delete;

private:
    ElectoralMap();
    map<int, District *> district_map;

    static const int num_district = 4; //earth example
};
#endif // _ELECTRALMAP_H_
