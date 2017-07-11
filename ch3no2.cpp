/*
Program Name ch3no2.cpp
Author: J. Dooley
Date: June 26, 2017
Synopsis:  Write a program to gauge the rate of inflation for the past year.  The program asks for the price of an item both one year ago and today.  It estimates the inflation rate as the difference in price divided by the year-ago price.  Your program should allow the user to repeat this calculation as often as the user wishes.  Define a function to compute the rate of inflation.  The inflation rate should be a value of type double giving the rate as a percentage.
*/

#include <iostream>
using namespace std;

double calculateInflationRate(double, double);

int main ()
{

double priceToday = 0;
double priceOneYearAgo = 0;
double inflationRate = 0;
bool response = true;

while (response == true)
{
	cout << "Enter the price of a hotdog today.\n";
	cin >> priceToday;

	cout << "Enter the price of a hot dog one year ago.\n";
	cin >> priceOneYearAgo;

	inflationRate = calculateInflationRate(priceToday, priceOneYearAgo);
	
	cout << "The inflation rate is " << inflationRate << ".\n";

	cout << "Do you wish to repeat the calculation? (respond with 0 or 1)\n";
	cin >> response;
}
return 0;
}

double calculateInflationRate(double todayRate, double yearAgoRate){
	double inflationRate = 0;
	inflationRate = todayRate / yearAgoRate;
return inflationRate;
}
   
