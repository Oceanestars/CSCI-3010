#include "Election.h"
#include "TextUI.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

/**
Oceane Andreis
Homework 3
Date: October 13 2019

This program is my Electionp.cpp.
I have included vector because I'm declaring vector, I have included map
so I can have access to the map library since I have maps.
I have included sstream so I can use stringstream

*/


/**
    Return nothing(constructor)

    @param name and id of candidate and access to party
    @return the id, name, and party.

*/
Candidate::Candidate(string name, Party party, int id)
{
    name_ = name;
    party_ = party;
    id_ = id;
}

//getters
string Candidate::get_name() const
{
    return name_;
}
Party Candidate::get_party() const
{
    return party_;
}
int Candidate::get_ids() const
{
    return id_;
}

/**
    Return a string

    @param nothing
    @return the id, name, and party into a sentence.

*/
string Candidate::Tostringfy() //example: 1: Oceane democrat
{
    stringstream s;
    s <<id_<<": "<<name_<<" "<<"["<<PartyStringify(party_)<<"]"<<endl;
    return s.str();
}

/**
    Return nothing.(Constructor)
    Adds candidate to a vector
    @param nothing.
    @return nothing.

*/
Election::Election(){
    string choice= "";
    cout<<"Do you want to register a candidate for party Republican (y or n )?";
    cin >> choice;

    while(choice != "n"){
        if(choice=="y"){
            cout<<"What is their name?";
            string name;
            cin>> name;

            Candidate temp(name, Party::Republican, count);
            count++;
            candidate.push_back(temp); //add candidate to vector
        }
        cout<<"Do you want to register a candidate for party Republican (y or n )?";
        cin>>choice;
    }
    string choice1= "";
    cout<<"Do you want to register a candidate for party Democrat (y or n )?";
    cin >> choice1;
    while(choice1 != "n"){
        if(choice1=="y"){
            cout<<"What is their name?";
            string name;
            cin>> name;
            Candidate temp(name, Party::Democrat, count);
            count++;
            candidate.push_back(temp); //add candidate to vector
        }
        cout<<"Do you want to register a candidate for party Democrat (y or n )?";
        cin>>choice1;
    }
  }



/**
    Return nothing.
    Prints out my electoral Map
    @param nothing
    @return nothing.

*/
void Election::Display(){
    cout<< electoral_map <<endl;
}


/**
    Return nothing

    @param district id and party object.
    @return nothing.

*/
void Election::Campaigning(int district_id, Party party){
    float p_success = 0.0;
    float p_extra = 0.0;

    map<int, District *> district = electoral_map.get_districts();


    District *d = district[district_id];

    map<Party, int> *constituent = d->get_voter();
    int total_Republican=0;
    int total_Democrat=0;

    for (map<Party, int>::iterator it = constituent->begin(); it!=constituent->end(); ++it){
        if(it->first==Party::Republican){
            total_Republican += it->second;
        }
        else if(it->first==Party::Democrat){
            total_Democrat += it->second;
        }
    }
    for (map<Party, int>::iterator it2 = constituent->begin(); it2!=constituent->end(); ++it2){
        if(it2->first==Party::Republican){
            float num = 0;
            num = ((it2->second) + 1) * 2;
            float denominator = 0;
            denominator = total_Democrat ;
            p_success += (num/denominator) * (num/d->get_area());
            p_extra += p_success * 0.1;
        }
        if(it2->first==Party::Democrat){
            float num = 0;
            num = ((it2->second) + 1) * 2;
            float denominator = 0;
            denominator = total_Republican ;
            p_success += (num/denominator) * (num/d->get_area());
            p_extra += p_success * 0.1;
        }

    }

    cout<<"Chances to convert:"<<p_success*100<<"%"<<endl;
    cout<<"Chances to convert from another party: "<< p_extra*100 << "%"<<endl;

    int random_num = rand()%100;
    float random_num2 = random_num/100;

    if(random_num2 < p_success)
    {
        if(constituent->at(Party::None) > 0){
                constituent->at(Party::None) -= 1;
                constituent->at(party) += 1;
                cout<<"Congratulations, you converted someone from None to "<<PartyStringify(party)<<endl;
        }
        else{
            cout<<"Sorry, no one in none to convert"<<endl;
        }
    }
    if(random_num2 < p_extra)
    {
        vector<Party> p = {Party::Republican,Party::Democrat};
        int index = rand()%3;
        Party other = p[index];
        if(other != party){
            if(constituent->at(other) > 0){
                constituent->at(other) -= 1;
                constituent->at(party) += 1;
                //cout<<"Congratulations, you converted someone from "<<PartyStringify(party)<<"to "<<PartyStringify(party)<<endl;
            }
        }
    }

  }



/**
    Return nothing
    prints our candidate and what's in our Tostringfy function
    @param vnothing
    @return nothing.

*/

void Election::PrintCandidate(){
    cout<<"---------------------"<<endl;

    for(int i=0; i<candidate.size(); i++){
        cout<<candidate[i].Tostringfy();
    }
    cout<<endl;
}

/**
    Return nothing
    get the votes from campaigning
    @param nothing
    @return nothing.

*/
void Election::get_vote(){
    vector <Candidate> candidate_voted;
    map <int, int>count_district_vote;
    string input_id;
    string name;
    int count2 =0;
    int party=-1;

    while(party !=0){
        cout<<"Which candidate is campaigning (id) (0 to stop) ?";
        cin>> input_id;
        party = stoi(input_id);

        for(int i=0; i< candidate.size(); i++){
            if(candidate[i].get_ids()==party){
                name = candidate[i].get_name();
                Display();
                int district_ids=-1;
                while(district_ids !=0){
                    cout<<"Where is this candidate campaigning (id) (0 to stop) ?";
                    string tmp_num_district;
                    cin >> tmp_num_district;
                    district_ids = stoi(tmp_num_district);
                    if(district_ids !=0){
                        count2++;
                        count_district_vote.insert(pair<int, int>(district_ids, count2));
                        Candidate temp(name, candidate[i].get_party(), district_ids);
                        candidate_voted.push_back(temp);
                        cout<<name<<" is campaigning in district "<<district_ids<<endl;

                        Campaigning(district_ids, candidate[i].get_party());
                        cout<<endl;

                        Display();
                    }
                    else if(district_ids==0){
                        PrintCandidate();
                    }
                }

            }
        }
    }
        int tmp = 0;
        map<int, District *> district = electoral_map.get_districts();
        for (map<int, District*>::iterator it = district.begin(); it!=district.end(); ++it){
            int track = 0;
            District *d = it->second;
            cout<<"District: "<<it->first<<endl;
            map<Party, int> *constituents = d->get_voter();
            map<Party, int>::iterator it1 = constituents->begin();
            Party p = it1->first;
            tmp = 0;
            for(int i = 0; i<candidate.size();i++){
                if(candidate[i].get_party()!=p){
                  track++;
                }
            }
            while (it1!=constituents->end()){
              if(track>0){
                for(int i=0; i<candidate.size(); i++){
                    if(candidate[i].get_party()==it1->first){
                        cout<<candidate[i].get_name()<<": ";
                        cout<<it1->second<<endl;
                    }
                }
                it1++;

            }
            else{
              tmp += it1->second;
              it1++;
            }
        }
        if (track == 0){
          cout<<candidate[0].get_name()<<": ";
          cout<< tmp<<endl;
        }
      }
        cout<<endl;
        Calculate(district);

}


/**
    Return nothing
    This calculates who wins the election
    @param map point to district
    @return nothing.

*/
void Election::Calculate(map<int, District *> district){

    map<string, int>result;
    string name;

    for (map<int, District*>::iterator it = district.begin(); it!=district.end(); ++it){
        District *d = it->second;

        map<Party, int> *constituents = d->get_voter();
        map<Party, int>::iterator it1 = constituents->begin();

        while (it1!=constituents->end()){

          for(int i =0; i<candidate.size();i++){
            int new_vote = 0.0;
            if(candidate[i].get_party()==it1->first){
              string name = candidate[i].get_name();
              new_vote+=it1->second;
              if(result.find(name) == result.end()){
                result.insert(pair<string, int>(name,new_vote));
              }
              else{
                result.at(name) += new_vote;
              }
             }
             if(candidate.size()==1){
              if(candidate[i].get_party()!=it1->first){
                string name = candidate[i].get_name();
                new_vote+=it1->second;
                if(result.find(name) == result.end()){
                  result.insert(pair<string, int>(name,new_vote));
                }
                else{
                  result.at(name) += new_vote;
                }
              }

            }
            //Tried other scenario

            // if((candidate.size()==2 || candidate.size()==3) && (candidate[i].get_party() == candidate[i+1].get_party())){
            //   if(candidate[i].get_party()!=it1->first){
            //     string name = candidate[i].get_name();
            //     new_vote+=it1->second;
            //     if(result.find(name) == result.end()){
            //       result.insert(pair<string, int>(name,new_vote));
            //     }
            //     else{
            //       result.at(name) += new_vote;
            //     }
            //   }
            //
            // }

          }
          it1++;
        }
    }
    int max_num = 0;
    string constituent;
    cout<<"Full results:"<<endl;
    for (map<string, int>::iterator it2 = result.begin(); it2!=result.end(); ++it2){

      cout<<it2->first<<": "<<it2->second<<endl;

        if(it2->second>max_num){
            max_num = it2->second;
            constituent = it2->first;
        }
    }
    cout<<"\n"<<"\n";
    cout<<"Congratulation, "<<constituent<<", you've won!"<<endl;
}

/**
    Return nothing
    Overriding get_vote so it works for representative
    @param nothing
    @return nothing.

*/
void RepresentativeElection::get_vote(){

    vector<float>district_vote;
    string candidate_id;
    string name;
    int count =0;
    int can_id=-1;

    while(can_id !=0){
        cout<<"Which candidate is campaigning (id) (0 to stop) ?";
        cin>> candidate_id;
        can_id = stoi(candidate_id);

        for(int i=0; i<candidate.size(); i++){
            if(candidate[i].get_ids() == can_id){
                name = candidate[i].get_name();
                Display();
                int district_ids=-1;
                while(district_ids !=0){
                    cout<<"Where is this candidate campaigning (id) (0 to stop) ?";
                    string tmp_num_district;
                    cin >> tmp_num_district;
                    district_ids = stoi(tmp_num_district);
                    if(district_ids != 0){
                        count++;
                        district_vote.push_back(electoral_map.get_districtvote(district_ids));
                        cout<<name<<" is campaigning in district "<<district_ids<<endl;

                        Campaigning(district_ids, candidate[i].get_party());
                        cout<<endl;

                        Display();
                    }
                }
                if(district_ids==0){
                    PrintCandidate();
                }
            }
        }
    }
    if(can_id==0){
        map<int, District *> district = electoral_map.get_districts();
        for (map<int, District*>::iterator it = district.begin(); it!=district.end(); ++it){
            int max_num = 0;

            Party p;
            int total_votes = 0;
            District *d = it->second;

            cout<<"District: "<<it->first<<endl;
            map<Party, int> *constituents = d->get_voter();
            map<Party, int>::iterator it1 = constituents->begin();

            while (it1!=constituents->end()){
                if (max_num < (it1->second) && it1->first != Party::None){
                    max_num = it1->second;
                    p = it1->first;
                }
                total_votes+=it1->second;
                it1++;
            }

            for(int i=0; i<candidate.size(); i++){
                if(candidate[i].get_party()==p){
                    cout<<candidate[i].get_name()<<": ";
                    cout<<total_votes<<endl;
                }
                else{
                    cout<<candidate[i].get_name()<<": ";
                    cout<<0<<endl;
                }
            }
        }
        cout<<endl;
    }
    Calculate(electoral_map.get_districts());
}


/**
    Return nothing
    calculate the result for a representative election vote(override calculate)
    @param map pointer to district
    @return nothing

*/
void RepresentativeElection::Calculate(map<int, District *> district){
    map<string, int>result;
    for (map<int, District*>::iterator it = district.begin(); it!=district.end(); ++it){
        int max_num = 0;
        Party p;
        Party current;

        District *d = it->second;
        map<Party, int> *constituents = d->get_voter();

        int total_votes = 0;
        map<Party, int>::iterator it1 = constituents->begin();
        while (it1!=constituents->end()){
            current = it1->first;
            if (max_num < (it1->second) && (current != Party::None)){
                max_num = it1->second;
                p = it1->first;
            }
            total_votes+=it1->second;
            it1++;
        }

        for(int i = 0; i < candidate.size(); i++){
            if(candidate[i].get_party()==p){
                string name = candidate[i].get_name();
                if ( result.find(name) == result.end() ) {
                    result.insert(pair<string, int>(name, total_votes));
                }
                else{
                    result.at(name) += total_votes;
                }
            }
            else{
                string name = candidate[i].get_name();
                result.insert(pair<string, int>(name, 0)); //add each result into map for loser
            }

        }
    }
    string constituent;
    string constituent2;
    cout<<"Full results: "<<endl;
    int max_num = 0;
    int first_num = 0;
    int second_num = 0;
    string original = result.begin()->first;
    string another;
    for (map<string, int>::iterator it2 = result.begin(); it2!=result.end(); ++it2){
        if(it2->first == original){
            first_num += it2->second;
        }
        else{
            another = it2->first;
            second_num += it2->second;
        }
        if(first_num>max_num){
            max_num = first_num;
            constituent = original;
            constituent2 = another;
        }
        else if(second_num>max_num){
            max_num = second_num;
            constituent = another;
            constituent2 = original;
        }
    }
    if(first_num == max_num){
        cout<<original<<": "<<max_num<<endl;
        cout<<another<<": "<<second_num<<endl;
    }
    else{
        cout<<another<<": "<<max_num<<endl;
        cout<<original<<": "<<first_num<<endl;
    }

    cout<<"\n"<<"\n";
    cout<<"Congratulations, "<<constituent<<", you've won!"<<endl;
}
