/*
Program Name:AdvQ2.cpp
Author: Jennifer Dooley
Date: Dec 1, 2017
Synopsis:  Write a templated power function that exercises the following rwelation Y = X to the N power.
X and Y can be either an int, float, long, double, etc  N MUST always be an int.  In the case wheer X is a char, the power function should be specialized to return n error message "Cannot use the power function on chars."
*/

#include <iostream>
#include <cmath>
using namespace std;

void xToThePower(int x, int n);

int main() 
{

xToThePower(3, 2);
xToThePower(3, 3);
xToThePower(3, 4);
xToThePower(3, 5);

return 0; 
}

void xToThePower(int x, int n){
  int result = 0;
  for (int i = 1; i < n+1; ++i){
       if (i == 1){
         result = x;
       }  
       else { 
         result = result * x;
       }
   }
   cout << result << endl;
}
