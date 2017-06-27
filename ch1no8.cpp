/*
Program Name: ch1no8.cpp
Author: J. Dooley
Date: June 25th, 2017
Synopsis: 
The Babylonian algorithm to compute the square root of a number n is as follows:
1. Make a guess at the answer (you can pick n/2 as your initial guess)
2. Compute r = n / guess.
3. Set guess = (guess + r) / 2
4. Go back to step 2 for as many iterations as necessary.  The more step 2 and 3 are repeated, the closer guess will become to the square root of n.

Write a program that inputs an integer for n, iterates through the Babylonian algorithm 5 times, and outputs the answer as a double to two decimal places.  Your answer will be most accurate for small values of n. 
*/

#include <iostream>
using namespace std;

int main ()
{

int n = 0;
int guess = 0;
int r = 0;

cout << "Please enter a number you'd like to know the square root of.\n";
cin >> n;

guess = n / 2;
for (int i = 0; i < 5; i++){ 
	cout << "Within the loop i is equal to " << i << ".\n"; 
	r = n / guess;
	cout << "r is " << r << ".\n";
	guess = (guess + r) / 2;
	cout << "Guess is " <<guess << ".\n\n";
}

cout << "The square root of n is " << guess << ".\n";

return 0;
}

