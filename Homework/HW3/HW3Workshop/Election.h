#ifndef _ELECTION_H_
#define _ELECTION_H_

#include "ElectoralMap.h"
#include <iostream>
#include <string>
#include <vector>


/**
Oceane Andreis
Homework 3
Date: October 13 2019

This program is my Election.h.
I have my class candidate and my class election declared as well
as a subclass of election.

*/

using namespace std;

class Candidate {
public:
    Candidate(string name, Party party, int id);
    string get_name() const;
    Party get_party() const;
    int get_ids() const;
    string Tostringfy();

private:
    string name_;
    Party  party_;
    int id_;
};


class Election {
public:
    Election();
    void Display();
    void Campaigning(int district_id, Party party);
    void PrintCandidate();
    void get_vote();
    void Calculate(map<int, District *> district);
  ;
protected:
    ElectoralMap & electoral_map = ElectoralMap::GetInstance();
    int count=1;
    vector <Candidate> candidate;

};


 // inherits Election class
class RepresentativeElection : public Election {
public:
    RepresentativeElection():
    Election(){};
    void get_vote();
    void Calculate(map<int, District *> district);

};


#endif // _ELECTION_H_
