/*
Program Name: ch1no10.cpp
Author: J. Dooley
Date: June 25th, 2017
Synopsis: Write a program that allows the user to enter time in seconds and then outputs how far an object would drop if it is freefall for that length of time.  Assume no friction or resistance from air and a constant acceleration of 32 feet per second due to gravity.  distance = 1/2 * acceleration * (time * time)  
*/

#include <iostream>
using namespace std;

int main ()
{

const int acceleration = 32;
int time = 0;
float distance = 0;

cout << "Enter freefall time in seconds.\n";
cin >> time;

distance = .5 * acceleration * (time * time);

cout << "The object would drop " << distance << " feet if in freefall for " << time << " seconds.\n";

return 0;
}

