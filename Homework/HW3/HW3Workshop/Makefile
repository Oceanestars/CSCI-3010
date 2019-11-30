CXX = g++ -g
CXXFLAGS	= -std=c++11 -Wall

all: ElectoralMap

clean:
	rm ElectoralMap ElectoralMap.o Election.o TextUI.o

ElectoralMap: main.cpp ElectoralMap.o Election.o TextUI.o
	$(CXX) $(CXXFLAGS) main.cpp ElectoralMap.o Election.o TextUI.o -o ElectoralMap

TextUI.o: TextUI.cpp
	$(CXX) $(CXXFLAGS) -c TextUI.cpp

ElectoralMap.o: ElectoralMap.cpp
	$(CXX) $(CXXFLAGS) -c ElectoralMap.cpp

Election.o: Election.cpp
	$(CXX) $(CXXFLAGS) -c Election.cpp
