/*
Program Name: ch12no8.cpp
Author: J Dooley
Date: November 1, 2017
Synopsis:  Write a program that computes the average of 10 quiz scores and write the student record plus the computed grade to the output file.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

void computeGrades(ifstream& fin, ofstream& fout);

int main()
{

ifstream fin;
ofstream fout;

cout << "Begin computing grades.\n";

fin.open("ch12no8I.txt");
if(fin.fail()){
  cout << "Input file could not be opened.\n";
  exit(1);
}

fout.open("ch12no8O.txt");
if(fout.fail()){
  cout << "Output file could not be opened.\n";
  exit(1);
}

computeGrades(fin, fout);

fin.close();
fout.close();

cout << "End of computation.\n";

return 0;
}

void computeGrades(ifstream& fin, ofstream& fout)
{
  cout << "inside of the function computeGrades" << endl;
  
  fout.setf(ios::showpoint);
  fout.setf(ios::fixed);

  string fname;
  string lname;
  int quiz1;
  int quiz2;
  int quiz3;
  int quiz4;
  int quiz5;
  int quiz6;
  int quiz7;
  int quiz8;
  int quiz9;
  int quiz10;
  
  double average = 0.0;

  do
  {
    average = 0.0; //reset the average for this student  
    fin  >> fname;
    fout << fname << " ";
    fin  >> lname;
    fout << lname << " ";
    fin  >> quiz1;
    fout << quiz1 << " ";
    fin  >> quiz2;
    fout << quiz2 << " ";
    fin  >> quiz3;
    fout << quiz3 << " ";
    fin  >> quiz4;
    fout << quiz4 << " ";
    fin  >> quiz5;
    fout << quiz5 << " ";
    fin  >> quiz6;
    fout << quiz6 << " ";
    fin  >> quiz7;
    fout << quiz7 << " ";
    fin  >> quiz8;
    fout << quiz8 << " ";
    fin  >> quiz9;
    fout << quiz9 << " ";
    fin  >> quiz10;
    average = (quiz1 + quiz2 + quiz3 + quiz4 + quiz5 + quiz6 + quiz7 + quiz8 + quiz9 + quiz10)/10;
    fout << average << endl;
    fin.clear();
  } while (getline(fin, fname));
 
}


