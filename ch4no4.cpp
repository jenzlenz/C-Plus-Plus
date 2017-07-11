/**********************************************
Program Name: ch4no4.cpp
Author: J Dooley
Date: July 9, 2017
Synopsis:  Write a program that will read in a length in feet and inches and output the equivalent length in meters and centimeters.  
There should be at least 3 functions: one to do the input, one to do the conversion and one to do the output.    
Include a loop that allows the user to repeat this computation for new input values until user wants to end the program.
**********************************************/

#include <iostream>
using namespace std;

void getInput(int& feet, int& inches);
void doConversion(int& feet, int& inches, int& meters, double& centimeters);
void showResult(int feet, int inches, int meters, double centimeters);

int main ()
{
bool repeat = true;
int feet = 0;
int inches = 0;
int  meters = 0;
double centimeters = 0.0;
char response = ' ';

while (repeat == true)
  	{
	getInput(feet, inches);
	doConversion(feet, inches, meters, centimeters);
	showResult(feet, inches, meters, centimeters);

	cout << "Do you want to repeat this computation? (y or n)\n";
	cin >> response;

	if (response == 'y')
		repeat = true;
	else
		repeat = false;

	}

return 0;
}

void getInput(int& feet, int& inches)
{
	cout << "Enter the number of feet.\n";
	cin >> feet;
	cout << "Enter the number of inches.\n";
	cin >> inches;
}

void doConversion(int& feet, int& inches, int& meters, double& centimeters)
{
	int totalInches = 0;
	totalInches = inches + (feet * 12);

	int totalCentimeters = 0;
	totalCentimeters = (totalInches * 2.54);

	int totalMeters = 0;
	totalMeters = totalCentimeters / 100;

	meters = totalMeters;
	centimeters = totalCentimeters % 100;;

}

void showResult(int feet, int inches, int meters, double centimeters)
{
	cout << feet << " feet " << inches << " inches is equal to " << meters << " meters " << centimeters << " centimeters.\n";	

}

