#include <iostream>
#include <string>
#include <vector>

#include "Library.h"

// implement bool Book::operator==(const Book & b)
bool Book::operator ==(const Book & b)
{
	return title == b.title && author == b.author;
}

// implement
std::ostream & operator<<(std::ostream & os, const Book & b){
	os<<b.title<<"by"<<b.author<<std::endl;
	return 0s;
}

/**
	Zero argument constructor initializes a library with a shelf but no books.
*/
Library::Library() {
	std::vector<Book> tmp;
	shelf_ = tmp;  // initialize my shelf
}

void Library::Donate(Book b) {
	shelf_.push_back(b);
}

// implement
std::ostream & operator<<(std::ostream & os, const Library & l)
{
	for(Book b: shelf_)
	{
		os<<b.title<<"by"<<b.author<<std::endl;
	}
}

void Library::PrintBooks() {
	for (Book b : shelf_) {
		std::cout << b.title << " by " << b.author << std::endl;
	}
}
