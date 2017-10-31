/*
Program Name: ch12no1.cpp
Author: J Dooley
Date: October 28, 2017
Synopsis:  Write a program that displays the largest and smallest integers within an input file.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

int main()
{

ifstream inStream;
ofstream outStream;
 
inStream.open("ch12no1.txt");
if(inStream.fail()){
  cout << "Input file could not be opened.\n";
  exit(1);
}

int next_number = 0;
int smallest = 0;
int largest = 0;

while (inStream >> next_number){
if (next_number > largest){
   largest = next_number;
   cout << "next Number was the largest.\n";
}
else if (next_number < smallest){
        smallest = next_number;
        cout << "next number was the smallest.\n";
     }
     else
        cout << "Next number was neither largest nor smallest.\n";
}

cout << "The largest number in the file is: " << largest << endl;
cout << "The smallest number in the file is: " << smallest << endl;

inStream.close();
return 0;
}

