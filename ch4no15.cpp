/**********************************************
Program Name: ch4no4.cpp
Author: J Dooley
Date: July 10, 2017
Synopsis:  Write a function named ConvertToLowestTerms that inputs two integer parameters by reference named numerator and denominator.
The function should treat these variables as a fraction and reduce them to lowest terms.
If the demnominator is zero, the function should return false, otherwise the function should return true.
**********************************************/

#include <iostream>
#include <algorithm>
using namespace std;

void getInput(int& numerator, int& denominator);
bool ConvertToLowestTerms(int& numerator, int& denominator);

int main ()
{
bool repeat = true;
int numerator = 0;
int denominator = 0;
char response = ' ';

while (repeat == true)
  	{
	getInput(numerator, denominator);
	ConvertToLowestTerms(numerator, denominator);
	
	cout << "Do you want to repeat this computation? (y or n)\n";
	cin >> response;

	if (response == 'y')
		repeat = true;
	else
		repeat = false;

	}

return 0;
}

void getInput(int& numerator, int& denominator)
{
	cout << "Enter the numerator.\n";
	cin >> numerator;
	cout << "Enter the denominator.\n";
	cin >> denominator;
}

bool ConvertToLowestTerms(int& numerator, int& denominator)
{
	cout << denominator << "\n";
	if ((denominator >  0) && (numerator > 0))
	{
		int lesserValue = min(numerator, denominator);
    		while (max(numerator, denominator) % lesserValue)
        	lesserValue--;	
		denominator = denominator / lesserValue;
		numerator = numerator / lesserValue; 
		cout << "Numerator is changed to " << numerator  << "\n";
		cout << "Denominator is changed to " << denominator << "\n";
		return true;	
	}
	else
	{
		cout << "Denominator or Numerator is zero. Can't proceed.\n";
		return false;
	}
}
