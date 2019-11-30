#include <iostream>
#include "Earth.h"

// Names: Oceane Andreis
//
using namespace std;

int main(int argc, char **argv){
    // 0) Implement your Earth's constructor in Earth.cpp

    // 1) Get an instance of your earth object
				Earth &alive = Earth::GetInstance();
				// alive.GetInstance();

    // 2) Get another instance of your earth object
				Earth &dead= Earth::GetInstance();

    // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same
    // location in memory.
		// Earth::GetInstance();
				cout<<"Get Instance:"<<endl;
				cout<<&alive<<endl;
				cout<<&dead<<endl;

    // 3) Call IncreasePopulation from one of your Earth instances. Can you see this change
    // from your other Earth instance?
				alive.IncreasePopulation();
				cout<<"Increase pop:"<<endl;
				cout<<&alive<<endl;
				cout<<&dead<<endl;


    // 4) Create a public field in your Earth object. Do you need an instance of an Earth object
    // to access this field?
		//cout<<Earth::random_num<<endl;
		//no we can't access it, "invalid use of non-static data member 'random_num"

	return 0;
}
