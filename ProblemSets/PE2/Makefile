#Oceane Andreis
#Makefile
#To run file do make and then ./Point

CXX = g++  # the compiler
CXXFLAGS = -std=c++11 -Wall  # flags for the compiler (use c++11 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

# runs for "make all"
all: Point

clean:
	rm Point

Point:
	$(CXX) $(CXXFLAGS) Point.cpp main.cpp -o Point
