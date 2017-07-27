/*
Program Name: ch6no2.cpp
Author: J Dooley
Date: July 24, 2017
Synopsis: 
Define a class for a type called CounterType.
An object of this type is used to count things so it records a count that is a non negative whole number. (i.e. int)
Include a mutator function that sets the counter to a count given as an argument.
Include mutator functions to increase the count by one and decrease the count by one.
No member function should allow the value of the counter to become negative.
Include a member function that returns the current count value and one that outputs the count.
Embed your class definition in a test program.
*/

#include <iostream>
using namespace std;

class CounterType
{
public:
	void setCount(int newCount);
	int increaseCount(int count);
	int decreaseCount(int count);
	int currentCount();
	void outputCount();
private:
	int count;
};

int main()
{
 	CounterType Count;
	int theCurrentCount = 0;

	Count.setCount(88);
	Count.outputCount();

	Count.increaseCount(12);
	Count.outputCount();

	theCurrentCount = Count.currentCount(); 
	cout << "theCurrentCount is equal to " << theCurrentCount << ".\n";	

	Count.decreaseCount(80);
	Count.outputCount();

return 0;
}   

void CounterType::setCount(int newCount)
{
	//cout << "**********Inside the setCount function********* \n";
	if (newCount < 0)
		cout << "Counter value must remain non negative!\n";
	else
		count = newCount;
	
	cout << "Count has been reset to " << count << endl;

}

int CounterType::increaseCount(int increaseAmount)
{
	//cout << "****************Inside the increaseCount function*********** \n";
	count = count + increaseAmount;
	return (count);
}

int CounterType::decreaseCount(int decreaseAmount)
{
	//cout << "****************Inside the decreaseCount function************ \n";
	if (count == 0)
		cout << "Counter value is currently zero, decreasing would make it negative!\n";
	else
		count = count - decreaseAmount;
	//cout << "After decrease count is now " << count << ".\n";

return (count);
}

int CounterType::currentCount()
{
	//cout << "*************Inside the currentCount function******* \n";
	return count;
}

void CounterType::outputCount()
{
	//cout << "*************Inside the outputCount function********* \n";
	cout << "Count is equal to " << count << ".\n";
}
