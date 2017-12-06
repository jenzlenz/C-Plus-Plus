/*
Program Name:AdvQ2.cpp
Author: Jennifer Dooley
Date: Dec 1, 2017
Synopsis:  Write a templated power function that exercises the following rwelation Y = X to the N power.
X and Y can be either an int, float, long, double, etc  N MUST always be an int.  In the case wheer X is a char, the power function should be specialized to return n error message "Cannot use the power function on chars."
*/

#include <iostream>
using namespace std;

template <class T>
inline T xToThePower(T x, int n){
 if (isalpha(x)) {
    cout << "Cannot use the power function on chars." << endl;
  } else {
          T result = 0;
          for (int i = 1; i < n+1; ++i){
              if (i == 1){
                 result = x;
              } else { 
                     result = result * x;
                }
          }
          cout << result << endl;
  }
};

int main() 
{
int x = 2;
double y = 3.5;
float z = 5.55555;
long w = 9.12345678987654321;
char c = 'c';

xToThePower(x, 2);
xToThePower(y, 3);
xToThePower(z, 4);
xToThePower(w, 4);
xToThePower(c, 5);

return 0; 
}
