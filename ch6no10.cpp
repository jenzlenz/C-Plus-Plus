/*
Program Name: ch6no10.cpp
Author: J Dooley
Date: July 25, 2017
Synopsis:
Create a Temperature class that internally stores a temperature in degrees Kelvin.

Create functions named setTempKelvin, setTempFahrenheit, and setTempCelcius 
that take an input temperature in a specified temperature scale, 
converts the temperature to Kelvin, and stores that in the class member variable.

Also create functions that return the stored temperature in degrees Kelvin, Fahrenheit, and Celcius.

Write the main function to test your class.

Use these formulas to convert:
Kelvin = Celcius + 273.15
Celcius = (5/9) * (Fahrenheit - 32)
*/

#include <iostream>
using namespace std;

class Temperature
{
public:
	void setTempKelvin(double temp);
	void setTempFahrenheit(double temp);
	void setTempCelcius(double temp);
	double returnKelvin();
	double returnFahrenheit();
	double returnCelcius();
private:
	double Kelvin;
};

int main()
{
	Temperature todaysTemp, yesterdaysTemp, tomorrowsTemp;
	double desiredTemp = 00.00;

	//invoking each set function with the intention of it giving me the same result
	//303K = 86F = 30C

	todaysTemp.setTempKelvin(303);
	//temp is expressed already as Kelvin
	
	yesterdaysTemp.setTempFahrenheit(86);
	//temp is converted from F to K then Kelvin variable is set

	tomorrowsTemp.setTempCelcius(30);
	//temp is converted from Celcius to K then the Kelvin variable is set

	desiredTemp = todaysTemp.returnKelvin();
	cout << "Todays temp converted to Kelvin is " << desiredTemp << ".\n";
	
	desiredTemp = todaysTemp.returnFahrenheit();
        cout << "Todays temp converted to Fahrenheit is " << desiredTemp << ".\n";
	
	desiredTemp = todaysTemp.returnCelcius();
        cout << "Todays temp converted to Celcius is " << desiredTemp << ".\n";

return 0;
}

void Temperature::setTempKelvin(double temp)
{
	Kelvin = temp;
	cout << "Kelvin is set to " << Kelvin << ".\n";
}

void Temperature::setTempFahrenheit(double temp)
{
	Kelvin = (temp - 32)/1.8 + 273.15;
	cout << "Kelvin is set to " << Kelvin << ".\n";
}

void Temperature::setTempCelcius(double temp)
{
	Kelvin = temp + 273.15;
	cout << "Kelvin is set to " << Kelvin << ".\n";
}

double Temperature::returnKelvin()
{
	return Kelvin;  //no conversion needed
}

double Temperature::returnFahrenheit()
{
	 double Fahrenheit = 0.0;
	 Fahrenheit = (((1.8)*(Kelvin - 273.15)) + 32);
   return Fahrenheit;
}

double Temperature::returnCelcius()
{
   double Celcius = 0.0;
	 Celcius = Kelvin - 273.15;
   return Celcius;
}

