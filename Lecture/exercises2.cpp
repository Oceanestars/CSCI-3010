#include <iostream>
#include <string>
#include <vector>

// Names:
//Zander Louie
//Oceane Andreis


// template <typename T>;
//example  T Add(T i1, T i2);
//Solve the problem of generalizing things in a statically typed language
//prevent a lot of copy & paste
//Template will allow new/custom objects
//templated class
//template <class T>
// class Name{
//
// }


// 6) implement a templated version of AddToValues, "AddToValues2".
 template <typename T>
 std::vector<T> AddToValues2(std::vector<T> v1, T v2) {
   for (size_t i = 0; i < v1.size(); i ++) {
     v1[i] = v1[i] + v2;
   }
   return v1;
 }

struct Classroom {
  int desks;
  int students;

  Classroom operator+(const Classroom &c2) {
    desks = desks + c2.desks;
    students = students + c2.students;
  }
};

int main() {
    // 7) call AddToValues2, passing in an int vector and another int.
  std::vector<int> v = {1, 2, 3};
  v = AddToValues2(v, 4);
    // 8) compile this file to object code (g++ -std=c++11 -Wall exercises2.cpp -o exercises2.o),
    // then run `nm -C exercises2.o`. How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here: 1
    // 0000000100000880 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int> >, int)
    //

    // 9) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements
    std::vector<std::string> v2 = {"hi", "bye", "Peace"};
    std::string add_string = " Felicia";
    v2 = AddToValues2(v2, add_string);

    // 10) compile this file to object code (g++ -std=c++11 -Wall exercises2.cpp -o exercises2.o),
    // then run `nm -C exercises2.o`. How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:

//     0000000100000f30 T std::__1::vector<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, std::__1::allocator<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > > > AddToValues2<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > >(std::__1::vector<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, std::__1::allocator<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > > >, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >)
// 0000000100000db0 T std::__1::vector<int, std::__1::allocator<int> > AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int> >, int)

    // 11) Experiment to find calls to this function that you would like to work but that do
    // not yet work. for each function call that doesn't work, comment about what type of
    // error is produced.
    // This doesn't work because it attempts to add values of different types which is unsupported.
    // std::vector<int> v3 = {2, 3, 4};
    // double n = 3.5;
    // double res = 0;
    // res = AddToValues2(v3, n);


    // 12) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.
    Classroom c;
    c.desks = 12;
    c.students = 14;

    Classroom c2;
    c2.desks = 51;
    c2.students = 100;

    std::vector<Classroom> classrooms = {c, c2};

    Classroom c3;
    c3.desks = 5000;
    c3.students = 1;

    // 13) Call AddToValues2 w/ the vector of structs and single struct from #12
    // Is there an error? If yes, what is it?
    //
    // Answer:

    classrooms = AddToValues2(classrooms, c3);


    // 14) If there was an error, attempt to fix it.
}
