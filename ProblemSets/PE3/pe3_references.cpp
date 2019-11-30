#include <iostream>

// Name: Oceane Andreis
// Problem Set 3
// 09/06/19

// Write any functions you need here!

using namespace std;
void func1(int *parameter)
{

}

void func2(int &parameter2)
{

}
void time3(const int &input, int *num)
{
  *num += input;
}

int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.

    // 1) Declare an int
    int x = 3;
    cout<<"Value of x: "<<x<<endl;
    // 2) Declare a pointer to that int
    int *y = &x;
    cout<<"Location of x: "<<y<<endl<<"Value of x(*y): "<<*y<<endl;

    // 3) Increment the int via the pointer
    ++*y;
    cout<<"Increment pointer: "<<*y<<endl<<"Increment the int: "<<x<<endl;

    // 4) Declare a reference to your int
    int &z= x;
    cout<<"Reference to my int: "<<z<<endl;

    // 5) Increment the int via the reference
    ++z;
    cout<<"Increment Reference: "<<"z = "<<z<<endl<<"x = "<<x<<endl;

    // 6) When you increment the int via the variable declared in #1, from which
    // variables can you see the changes?
    // Answer:
    ++x;
    cout<<"Problem 6: You can see changes from the x variable(that int)";

    // 7) When you increment the int via the pointer declared in #2, from which
    // variables can you see the changes?
    // Answer:
    cout<<"Problem 7: You can see changes from the y variable(that pointer)"<<endl;

    // 8) When you increment the int via the reference declared in #4, from which
    // variables can you see the changes?
    // Answer:
    cout<<"Problem 8: You can see changes from the z variable(that reference)"<<endl;

    // 9) Write a function that takes an int * parameter. How would you pass the
    // variable from #1 into this function? (write the function call below)
    // Answer:
    func1(&x);

    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer:
    //No
    //func1(&z)-Accessing its address;

    // 11) Write a function that takes an int & parameter. How would you pass the
    // variable from #1 into this function? (write the function call below)
    // Answer:
    func2(x);

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer:
    //no
    //func2(*y)-dereference;

    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer:
    func2(z);

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
    //Input parameter- "regular" info that you're giving to the functions
    //Output parameter- passed as a pointer(normally) in c++, value will be filled in by the function

    int val = 3;
    time3(1, &val);
    cout<<"Problem 14: "<< val<<endl;
    time3(1, &val);
    cout<<"Problem 14: "<<val<<endl;

    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer:


      //Output parameter passed as a pointer(normally) in c++, value will be filled in by the function.

      cout<<"Problem 8: A return value needs to be within a function that is not void. It can return one value. While an output parameter we can return multiple values. In #14, we changed the value val at a memory level. If the function wasn't void and that we were returning a value we would most likely use local variables. A return value is also more costing in c++ and if we wanted to optimize our code, an output parameter would be preferable."<<endl;
}
