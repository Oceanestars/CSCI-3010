CXX = g++  # the compiler
CXXFLAGS = -std=c++11 -Wall  # flags for the compiler (use c++11 standards, turn on all optional warnings)
GDBINFO = -ggdb # include this to generate info needed to run gdb

all: main test

clean:
	rm test main TestTypes.o

main: main.cpp Counter.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

test: TestTypes.o test.cpp
		$(CXX) $(CXXFLAGS) test.cpp TestTypes.o -o test

TestTypes.o: TestTypes.cpp
	$(CXX) $(CXXFLAGS) -c TestTypes.cpp

# all: main
#
# clean:
# 	rm main
# main: main.cpp Counter.hpp
# 	$(CXX) $(CXXFLAGS) main.cpp -o main
