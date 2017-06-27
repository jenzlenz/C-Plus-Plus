/*
Program Name: ch1no3.cpp
Author: J. Dooley
Date: June 25th, 2017
Synopsis: Workers at a particular company have won a 7.6% pay increase reroactive for six months.  
Write a program that takes an employee's previous salary as input and outputs the amount of retroactive pay due the employee, 
the new annual salary, and the new monthly salary.  
Use a variable declaration with the modifier const to express the pay increase.
*/

#include <iostream>
using namespace std;

int main ()
{

const float payIncrease = 1.076;
float previousSalary = 0.0;
float newSalary = 0.0;
float newMonthlySalary = 0.0;
float retroPay = 0.0;

cout << "Enter salary $";
cin >> previousSalary;

newSalary = previousSalary * payIncrease;
cout << "Your new annual salary is $" << newSalary << ".\n"; 

newMonthlySalary = newSalary / 12;
cout << "Your new monthly salary is $" << newMonthlySalary << ".\n";

retroPay = newMonthlySalary * 6;
cout << "Your 6 month retro pay is $" << retroPay << ".\n";

return 0;
}
