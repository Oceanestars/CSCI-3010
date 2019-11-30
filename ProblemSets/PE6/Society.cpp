#include <iostream>
#include <string>
#include <map>
#include "Society.h"

/**
Oceane Andreis
Problem Set 6
Date: September 30 2019
I have include <map> because I am using map in this program.
This .cpp file takes care of growing the population from the user input's population.
It also grow and shrink the population accordingly to be used in GrowCities.
*/


/**
    Return true or false.

    @param nothing.
    @return true or fals.
*/
bool City::IsBig() const {
    if (population_ > 100000) {
        return true;
    } else if (population_ <= 100000) {
        return false;
    }
    return false;
}

/**
    Return nothing.

    @param int const of number of people .
    @return nothing.
*/
void City::Grow(int const num_people) {
    if (num_people >= 0 ) {
        population_ += num_people;
        percent_change_ = (1.0 * num_people) / population_;
    }
}

/**
    Return nothing.

    @param int const of number of people .
    @return nothing.
*/
void City::Shrink(int const num_people) {
    if (num_people >= 0 ) {
        population_ -= num_people;
    }
}

/**
    Return nothing.

    @param nothing .
    @return nothing.
*/
void Society::GrowCities() {
    City * biggest;
    City * c;
    double ratio;
    double percent_change;
    int prev;

    for(std::map<int, City *>::iterator it = cities_.begin(); it != cities_.end(); it++)
      {
        int key = it->first;
        c = cities_.at(key);
        if (c->get_population() > biggest->get_population()) {
            biggest = c;
          }
        }

        for(int i = 1; i <= last_key; i++)
          {
            c = cities_.at(i);
            ratio = (1.0 * c->get_population()) / biggest->get_population();
            prev = c->get_population();

        if (!c->IsBig()){

            c->Grow((int) ratio * .3 * c->get_population());

        }

        else {
            prev = c->get_population();
            c->Grow((int) ratio * c->get_population());

        }

        c->Shrink((int) c->get_population() * .1);
        percent_change = (1.0 * c->get_population() - prev) / prev;
        c->set_percent_change(percent_change);
    }
}

/**
    Return a string of info.

    @param has access to the ostream and to City .
    @return a string of info.
*/
std::ostream& operator<<(std::ostream &os, const City &c) {
    os << c.name_ << ": " << c.population_  << " (" << c.percent_change_ << "% change)";
    return os;
}

/**
    Return a string of info.

    @param has access to the ostream and to Society .
    @return a string of info.
*/
std::ostream& operator<<(std::ostream &os, const Society &s) {
  for(std::map<int, City *>::const_iterator it =s.cities_.begin(); it != s.cities_.end(); it++)
    {

      os << *(s.cities_.at(it->first)) << std::endl;

    }

return os;
}
