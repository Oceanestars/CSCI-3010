/**
Oceane Andreis
Problem Set 2
Date: September 2 2019

This program is my main.cpp.
My main.cpp is used to test my methods and provide the 2 points and you can
change its dimension byt providing  more numbers(n-dimension).
I have organized it in the following way:
    1. Printed out the original coordinates
    2. Printed out the distance between the 2 points
    3. Printed out the translation of the 2 points with a positive number
    4. Printed out the translation of the 2 points with a negative number(using the previous coordinate of the last translation)
*/

#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

int main()
{
    vector<int>one = {3,6,1,3};
    vector<int>two = {7,-5,7,5};
    Point first(one);
    Point second(two);


    int change = 1; //Number passed in the translate function

    vector<int> first_n = first.get_alln(); // getting the coordinates

    vector<int> second_n = second.get_alln();


    cout<<"The original coordinates for the first point is: "<<"(";

    for(int i =0;i<first_n.size();i++)
    {
     cout<<first_n[i]<<",";
    }
    cout<<")"<<endl;

    cout<<"The original coordinates for the second point is: "<<"(";
    for(int i =0;i<second_n.size();i++)
    {
     cout<<second_n[i]<<",";
    }
    cout<<")"<<endl;

    cout<<"The dimension of our point is: "<<first.ndimension()<<endl;

    int result1 = first.distance(second_n);

    cout<<"------------------------------------------------------"<<endl;

    cout<<"The distance between our first and second point is: "<<result1<<endl;


    cout<<"------------------------------------------------------"<<endl;

    first.translate(change);
    second.translate(change);

    vector<int> finalvec =first.get_alln();
    vector<int> finalvec2 =second.get_alln();

    cout<<"Translate the coordinates by: "<<change<<endl;
    cout<<"The translation for the first point is: (";

    for(int i =0;i<finalvec.size();i++)
    {
     cout<<finalvec[i]<<",";
    }
    cout<<")"<<endl;

    cout<<"The translation for the second point is: (";
    for(int i = 0 ;i < finalvec2.size() ; i++)
    {
     cout<<finalvec2[i]<<",";
    }
    cout<<")"<<endl;


    cout<<"------------------------------------------------------"<<endl;

    change = -5;

    first.translate(change);
    second.translate(change);
    finalvec =first.get_alln();
    finalvec2 =second.get_alln();
    cout<<"Translate the coordinates by: "<<change<<endl;
    cout<<"The translation for the first point is: (";

    for(int i =0;i<finalvec.size();i++)
    {
      cout<<finalvec[i]<<",";
    }
    cout<<")"<<endl;

    cout<<"The translation for the second point is: (";

    for(int i =0;i<finalvec2.size();i++)
    {
      cout<<finalvec2[i]<<",";
    }
    cout<<")"<<endl;


    return 0;

}
