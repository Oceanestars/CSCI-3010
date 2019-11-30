#include <iostream>
#include <string>

#include "Disease.h"

int Disease::counter_ = 0;

std::ostream& operator<<(std::ostream &os, const Disease &d) {
    os << d.get_name();
    // TODO: print out more information if you want to
    return os;
}
Disease* DiseaseFactory::GetFlu(){
  Disease *one = new Disease("flu",1,0,0,1,1,0.5,1,0.3,"lung");
  return one;

}
Disease* DiseaseFactory::GetCold(){
  Disease *two = new Disease("cold",1,0,1,0,1,0.5,1,0.1,"heart");
  return two;

}
Disease* DiseaseFactory::GetEbola(){
  Disease *two = new Disease("ebola",0,0,0,0,0,0,1,0.9,"hand");
  return two;

}
