/*
Program Name: ch6no8.cpp
Author: J Dooley
Date: July 25, 2017
Synopsis:
Define a class named Money that defines a monetary amount.
The class should have two positive integer variables, one to store the dollars and one to store the cents.
Add accessor functions to read and set both member variables.
Add another function that returns the monetary amount as a double.
Write a program that tests your functions with at least two different monetary objects.
*/

#include <iostream>
using namespace std;

class Money
{
public:
	void setMoney(int newDollars, int newCents);
	double convertMoney();
private:
	int dollars;
	int cents;
};

int main()
{
 	Money myWallet, yourWallet;
	double dMoney = 00.00;

	myWallet.setMoney(88, 88);
	yourWallet.setMoney(50, 50);

	dMoney = myWallet.convertMoney();
	cout.precision(2);
	cout << "myWalet converted to double is equal to " << fixed << dMoney << ".\n";

	dMoney = yourWallet.convertMoney();
        cout << "yourWalet converted to double is equal to " << fixed << dMoney << ".\n";
	
return 0;
}   

void Money::setMoney(int newDollars, int newCents)
{
	cout << "**********Inside the setMoney function********* \n";
	if ((newDollars < 0) || (newCents < 0))
		cout << "Dollar and Cents values must remain non negative!\n";
	else {
		dollars = newDollars;
		cents = newCents;
	}

	cout << "Dolars has been reset to " << dollars << " cents has been reset to " << cents << ".\n";

}

double Money::convertMoney()
{
	double converted = 0.0;
	double dcents = (double) cents;
	converted = (dollars + (dcents/100));
	return converted;	

}
