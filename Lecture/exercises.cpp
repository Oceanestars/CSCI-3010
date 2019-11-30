#include <iostream>
#include <string>
#include <vector>

// Names:
//Zander Louie
//Oceane Andreis


// 1) implement two functions, AddToValues(std::vector<int> v1, int v2)
// and AddToValues(std::vector<double> v1, double v2)

std::vector<int> AddToValues(std::vector<int> v1, int v2) {
  for (size_t i = 0; i < v1.size(); i ++) {
    v1[i] += v2;
  }
  return v1;
}

std::vector<double> AddToValues(std::vector<double> v1, double v2) {
  for (size_t i = 0; i < v1.size(); i ++) {
    v1[i] += v2;
  }
  return v1;
}
// 2) Do your AddToValues functions have return values? why/ why not?
// Answer: Yes they do, because the vector is not pass by reference, it
// needs to return something to report the result.


int main() {
    // 3) Instantiate an int vector
    std::vector<int> v = {1, 2, 3};

    // 4) call AddToValues, passing in your int vector and another int.
    v = AddToValues(v, 4);

    // 5) compile this file to object code (g++ -std=c++11 -Wall exercises.cpp -o exercises.o),
    // then run `nm -C exercises.o`. How many versions of the AddToValues function are in the
    // compiled object code? Copy + paste the relevant lines here: 2

    //0000000100001460 T AddToValues(std::__1::vector<double, std::__1::allocator<double> >, double)
    //0000000100001350 T AddToValues(std::__1::vector<int, std::__1::allocator<int> >, int)
    //
    // To making searching through the output easier, you can pipe the output of nm to grep
    // `nm -C exercises.o | grep "TextToFindHere"`
    //
    // If the -C flag isn't working, you can omit it and still complete the exercise--this flag
    // makes the output easier to read but isn't strictly necessary
}
