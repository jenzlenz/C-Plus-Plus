/*
Program Name: ch12no6.cpp
Author: J Dooley
Date: October 31, 2017
Synopsis:  Write a program that merges the numbers from two files and write them into a third file.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

void mergeTwoFiles(ifstream& fileA, ifstream& fileB, ofstream& fout);

int main()
{

ifstream fileA;
ifstream fileB;
ofstream fout;

cout << "Begin merging files.\n";

fileA.open("ch12no6A.txt");
if(fileA.fail()){
  cout << "Input file A could not be opened.\n";
  exit(1);
}

fileB.open("ch12no6B.txt");
if(fileB.fail()){
  cout << "Input file B could not be opened.\n";
  exit(1);
}

fout.open("ch12no6_merged.txt", ios::out | ios::app);
if(fout.fail()){
  cout << "Output file ch12no6_merged.txt could not be opened.\n";
  exit(1);
}

mergeTwoFiles(fileA, fileB, fout);

fileA.close();
fileB.close();
fout.close();

cout << "End of file merge.\n";
return 0;
}

void mergeTwoFiles(ifstream& fileA, ifstream& fileB, ofstream& fout)
{
  cout << "inside of the function mergeTwoFiles" << endl;
  
  int next;
  while (fileA >> next)
  {
    fout << next << endl;
    cout << "while loop for fileA" << endl;
  }
 
  while (fileB >> next)
  {
    fout << next << endl;
    cout << "while loop for fileB" << endl;
  }
}

