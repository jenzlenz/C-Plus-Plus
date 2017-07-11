/*
Program Name: ch3no1.cpp
Author: J. Dooley
Date: June 25th, 2017
Synopsis: 
A liter is 0.264179 gallons.  
Write a program that will read in the number of liters of gasoline consumed by the user's car and the number of miles travelled by the car and will then output the number of miles per gallon the car delivered.  Your program should allow the user to repeat this calculation as often as the user wishes.  Define a function to compute the number of miles per gallon.  Your program should use a globally defined constant for the number of liters per gallon.
*/

#include <iostream>
using namespace std;

float MPG(float, float);

int main ()
{

const float litersPerGallon = 3.785;
float gallonsConsumed = 0;
float milesTravelled = 0;
float litersConsumed = 0;
float milesPerGallon = 0;
bool response = true;

while (response == true)
{
	cout << "Enter the liters of gas consumed by your car.\n";
	cin >> litersConsumed;

	gallonsConsumed = litersConsumed / litersPerGallon;

	cout << "Enter the number of miles traveled.\n";
	cin >> milesTravelled;

/*	milesPerGallon = milesTravelled / gallonsConsumed; */
	milesPerGallon = MPG(milesTravelled, gallonsConsumed);
	
	cout << "The number of miles per gallon your car gets is " << milesPerGallon << ".\n";

	cout << "Do you wish to repeat the calculation? (respond with 0 or 1)\n";
	cin >> response;
}
return 0;
}

float MPG(float howFar, float howManyGallons){
	float mpg = 0;
	mpg = howFar / howManyGallons;
return mpg;
}
