/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int value =3;
    int value2 = 2;
    int *pt1 = &value; //3
    int *pt22= &value2; //2
    int **pt33 =
    int **pt2 = &pt1;
    // int *pt2 = *pt1;
    int *pt3 = &value;
    int &pt4= value;
    //int &pt5 = *value;

    cout<<"pt1: "<<*pt1<<endl;
    cout<<"pt2: "<<**pt2<<endl;
    cout<<"pt3: "<<pt3<<endl;
    cout<<"pt4: "<<pt4<<endl;
    //cout<<"pt5: "<<pt5<<endl;



    return 0;
}
