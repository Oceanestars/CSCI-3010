CXX = g++  # the compiler
CXXFLAGS = -std=c++11 -Wall  # flags for the compiler (use c++11 standards, turn on all optional warnings)
GDBINFO = -ggdb # include this to generate info needed to run gdb

all: main

clean:
	rm main
main: main.cpp Counter.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o main


#
# clean:
# 	rm TestTypes.o main test
#
test: main.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp main.o -o test
#
# main: Counter.hpp main.cpp
# 	$(CXX) $(CXXFLAGS) main.cpp TestTypes.o -o main
