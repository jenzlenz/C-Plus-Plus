/*
Program Name:AdvQ2.cpp
Author: Jennifer Dooley
Date: Dec 5, 2017
Synopsis:  Write a templated power function that exercises the following rwelation Y = X to the N power.
X and Y can be either an int, float, long, double, etc  N MUST always be an int.  In the case wheer X is a char, the power function should be specialized to return n error message "Cannot use the power function on chars."
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
inline T absoluteValue(T x){
 if (x < 0) {
     return -x;
    } else { 
        return x;
       }
};

int main() 
{
int x = -2;
double y = -3.5;
float z = -5.55555;
long w = -9.12345678987654321;
char c = 'c';

cout << "The absolute value of x is " << absoluteValue(x) << endl;
cout << "The absolute value of y is " << absoluteValue(y) << endl;
cout << "The absolute value of z is " << absoluteValue(z) << endl;
cout << "The absolute value of w is " << absoluteValue(w) << endl;
cout << "The absolute value of c is " << absoluteValue(c) << endl;
cout << "The absolute value of -8 is " << absoluteValue(-8) << endl;

return 0; 
}

