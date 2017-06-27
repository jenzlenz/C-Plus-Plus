/*
Program Name: ch1no7.cpp
Author: J. Dooley
Date: June 25th, 2017
Synopsis: Write a program that inputs the subject weight in pounds, the number of METS for an activity and the number of minutes spent on that activity, and then outputs an estimate for the total number of calories burned.  One kilogram is equal to 2.2 pounds. 
*/

#include <iostream>
using namespace std;

int main ()
{

float weightInPounds = 0.0;
float METS = 0.0;
float minutesSpent = 0.0;
float caloriesPerMinute = 0.0;
float totalCaloriesBurned = 0.0;
float weightInKg = 0.0;

cout << "Enter weight in pounds ";
cin >> weightInPounds;

cout << "Enter METS spent on activity ";
cin >> METS;

cout << "Enter minutes spent performing activity.";
cin >> minutesSpent;

weightInKg = weightInPounds * 2.2;
caloriesPerMinute = 0.0175 * METS * weightInKg;
totalCaloriesBurned = caloriesPerMinute * minutesSpent;

cout << "Total calories burned are: " << totalCaloriesBurned << ".\n";

return 0;
}

