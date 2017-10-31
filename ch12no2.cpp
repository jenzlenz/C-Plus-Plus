/*
Program Name: ch12no2.cpp
Author: J Dooley
Date: October 31, 2017
Synopsis:  Write a program that displays on the screen the average from a file containing numbers of type double.
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

inStream.open("ch12no2.txt");
if(inStream.fail()){
  cout << "Input file could not be opened.\n";
  exit(1);
}

double next_number = 0;
int count = 0;
double sum = 0;
double average = 0;

while (inStream >> next_number){
      ++count;
      sum = sum + next_number;
}

average = sum / count;

cout << "The average of all numbers in the file is: " << average << endl;
inStream.close();
return 0;
}
