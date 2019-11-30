#include <iostream>
#include <vector>
#include "Library.h"

// Name(s):
//
// Complete numbered coding tasks.
// Answer the questions with "Answer: " in the comments in the comments.
// Turn in run_library.cpp on Canvas before the end of class. (only this file!)
using namespace std;
int main() {
    // 1) Instantiate a couple Books. Set their fields equal to some values.
    // Print out the values of the books' fields.
    Book one;
    Book two;
    one.title = "Le Petit Prince";
    one.author = "forgot the name";
    two.title = "The Alchemist";
    two.author ="Paulo cohelo";
    cout << one.title << " by " << one.author << endl;
    cout << two.title << " by " << two.author << endl;



    // 2) Instantiate a Library.
    Library bib;


    // 3) Add a void Donate(Book b) method to your Library class.
    // Your Library should store the new book at the end of its shelf.


    // 4) Donate one of the Books that you instantiated to your Library.
    bib.Donate(one);

    // 5) Print out the books in the Library (use the given PrintBooks method)
    bib.PrintBooks();

    // 6) Change the title and/or author of the book that you donated to
    // something different.
    // Print out the new book information, then print out the books in your
    // Library. Did changing the Book information change it in your Library?
    //
    // Answer (and your hypothesis for why/why not):
    one.title= "New Book";
    one.author="New author";
    cout << one.title << " by " << one.author << endl;

    bib.PrintBooks();



    // 7) Create two Books that are separate structs (not pointers or references)
    // but that have the same information.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:
    Book a;
    a.title = "little fires everywhere";
    a.author="Celeste Ng";
    Book c;
    c.title = "idk";
    c.author="idk2";
    // if (a == c){
    //   cout<<"They are the same"<<endl;
    //
    // }
    // else{
    //   cout<<"Not the same"<<endl;
    // }


    // 8) Create two Book references to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:



    Book *bp1 = &a;
    Book *bp2 = &c;
    if (bp1 ==bp2){
      cout<<"They are the same"<<endl;

    }
    else{
      cout<<"Not the same"<<endl;
    }

    // 9) Create two Book pointers to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:

    Book &bp3 = a;
    Book &bp4 = c;
    // if (bp3 ==bp4){
    //   cout<<"They are the same"<<endl;
    //
    // }
    // else{
    //   cout<<"Not the same"<<endl;
    // }

    // 10) (Given in lecture)
//Overload: multiple methods with the same name but different parameters
//overriding: when a func signature is the same as a base class/an abstract func

}
