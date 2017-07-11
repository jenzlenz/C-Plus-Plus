/*
Program Name: ch3no4.cpp
Author: J Dooley
Date: June 26, 2017
Synopsis:  
The gravitational force between two bodies with masses m1 and m2 separated by a distance d is given by the following formula:
F = (G * m1 * m2) / (d * d)
where G is the universal gravitational constant:
G = 6.673 * (10 to the minus 8) *  (cm cubed) / (g * sec * sec)

Write a function definition that takes arguments for the masses of two bodies and the distance between them and returns the gravitational force between them.
Since you will use the above formula, tha gravtational force will be in dynes.
One dynes equals a g . cm/sec*sec

You should use a globally defined constant for the universal gravitational constant.
Embed your function definition in a complete program that computes the gravitational force between two objects given suitable inputs.  Your program should allow the user to repeat this calculation as often as the user wishes.
*/

#include <iostream>
using namespace std;

float gravitationalForce(float, float, float, float);

int main ()
{

const float G = 6.67300E-11;
float mass1 = 0;
float mass2 = 0;
float distance = 0;
float Force = 0;
bool response = true;

while (response == true)
{
	cout << "Enter the mass of the first object.\n";
	cin >> mass1;

	cout << "Enter the mass of the second object.\n";
	cin >> mass2;

	cout << "Enter the distance between mass one and mass two.\n";
	cin >> distance;
	
	Force = gravitationalForce(mass1, mass2, distance, G);
	
	cout << "The gravitational force between mass one and mass two is " << Force << ".\n";

	cout << "Do you wish to repeat the calculation? (respond with 0 or 1)\n";
	cin >> response;
}
return 0;
}

float gravitationalForce(float mass1, float mass2, float distance, float G){
	float gForce = 0;
	gForce = G * mass1 * mass2 / distance * distance;
return gForce;
}

