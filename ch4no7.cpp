/**********************************************
Program Name: ch4no7.cpp
Author: J Dooley
Date: July 10, 2017
Synopsis:  Write a program that will read in a weight in pounds and ounces and output the equivalent in kilograms and grams.  
There should be at least 3 functions: one to do the input, one to do the conversion and one to do the output.    
Include a loop that allows the user to repeat this computation for new input values until user wants to end the program.
**********************************************/

#include <iostream>
using namespace std;

void getInput(int& pounds, int& ounces);
void doConversion(int& pounds, int& ounces, int& kilos, double& gramss);
void showResult(int pounds, int ounces, int kilos, double grams);

int main ()
{
bool repeat = true;
int pounds = 0;
int ounces = 0;
int kilos = 0;
double grams = 0.0;
char response = ' ';

while (repeat == true)
  	{
	getInput(pounds, ounces);
	doConversion(pounds, ounces, kilos, grams);
	showResult(pounds, ounces, kilos, grams);

	cout << "Do you want to repeat this computation? (y or n)\n";
	cin >> response;

	if (response == 'y')
		repeat = true;
	else
		repeat = false;

	}

return 0;
}

void getInput(int& pounds, int& ounces)
{
	cout << "Enter the number of pounds.\n";
	cin >> pounds;
	cout << "Enter the number of ounces.\n";
	cin >> ounces;
}

void doConversion(int& pounds, int& ounces, int& kilos, double& grams)
{

	int totalOunces = 0;
	totalOunces = ounces + (pounds * 16);


	int totalGrams = 0;

	totalGrams = (totalOunces * 28.3495);


	int totalKilos = 0;

	totalKilos = totalGrams / 1000;


	kilos = totalKilos;

	grams = totalGrams % 1000;;
}

void showResult(int pounds, int ounces, int kilos, double grams)
{
	cout << pounds << " pounds " << ounces << " ounces is equal to " << kilos << " kilos " << grams << " gramss.\n";	

}


