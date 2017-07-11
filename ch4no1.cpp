/**********************************************
Program Name: ch4no1.cpp
Author: J Dooley
Date: July 9, 2017
Synopsis:  Write a program that convert from a 24 hour notation to a 12 hour notation.  
The input is given as two integers.  
There should be at leat 3 functions: one to do the input, one to do the conversion and one to do the output.  
Record AM/PM info as A for AM and P for PM.  
Thus the function for doing the conversion will have a call by reference formal parameter of type char to record AM PM info.  
Include a loop that allows the user to repeat this computation for new input values until user wants to end the program.
**********************************************/

#include <iostream>
using namespace std;

void getInput(int& hours, int& minutes);
void doConversion(int& hours, char& amORpm);
void showResult(int hours, int minutes, char amORpm);

int main ()
{
bool repeat = true;
int hours = 0;
int minutes = 0;
char amORpm = 'A';
char response = ' ';

while (repeat == true)
  	{
	getInput(hours, minutes);
	doConversion(hours, amORpm);
	showResult(hours, minutes, amORpm);

	cout << "Do you want to repeat this computation? (y or n)\n";
	cin >> response;

	if (response == 'y')
		repeat = true;
	else
		repeat = false;

	}

return 0;
}

void getInput(int& hours, int& minutes)
{
	cout << "Enter the hours.\n";
	cin >> hours;
	cout << "Enter the minutes.\n";
	cin >> minutes;
}

void doConversion(int& hours, char& amORpm)
{
	if (hours > 12)
	{
		hours = (hours - 12);
		amORpm = 'P';
	}
	else
		amORpm = 'A';
}

void showResult(int rhours, int rminutes, char amORpm)
{
	cout << "That time expressed in 12 hour notation is " << rhours << ":"  << rminutes << amORpm << "M.\n";	

}
