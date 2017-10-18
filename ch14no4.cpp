/* 
Program Name: ch14no4.cpp
Author: J Dooley
Date: October 17, 2017
Synopsis:
Create base class called Vehicle with a derived class called Truck.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Person
{  
private: 
  string Name;

public:
  Person();					//default constructor
  Person(string theName);			//parameterized constructor
  Person(const Person& theObject);		//parameterized constructor
  ~Person();					//destructor
  string getName() const;
  Person operator=(const Person &rtside);
  friend istream& operator >>(istream& inStream, Person& personObject);
  friend ostream& operator <<(ostream& outStream, const Person& personObject);
};

class Vehicle
{
protected:
  string Manufacturer;
  int    Cylinders;
  Person Owner;

public:
  Vehicle();								//default constructor
  Vehicle(string theManufacturer, int theCylinders, Person theOwner);   //parameterized constructor
  ~Vehicle(); 								//destructor
};

class Truck:public Vehicle
{
private:
  double loadCapacity;
  int 	 towCapacity;
public:
  Truck(); 											//default constructor
  Truck(string theManufacturer, int theCylinders, Person theOwner, double theLoad, int theTow); //parameterized constructor
  ~Truck();											//destructor

};

int main()
{

Person John; 					//uses default constructor
Person Jasmine("Jasmine"); 			//uses parameterized constructor

Vehicle Car1;  					//uses default constructor
Vehicle Car2("Honda", 4, Jasmine);		//uses parameterized constructor

Truck Truck1;  					//uses default constructor
Truck Truck2("Honda", 8, John, 10.5, 18);	//uses parameterized constructor

return 0;
}

Person::Person()
{
  cout << "default Person constructor" << endl;
}

Person::Person(string theName){
  cout << "Parameterized Person constructor" << endl;
  Name = theName;
}

Person::~Person(){
  cout << "Person destructor" << endl;
}

Person::Person(const Person & rhs){
  cout << "Entering person copy constructor \n";
  Name = rhs.Name;
}

string Person::getName()const{
  return Name;
}

Person Person::operator=(const Person &rhs){
   cout << "Entering the overloaded person assignment operator " << endl;
   this->Name = rhs.Name;
};

ostream &operator << (ostream& output, Person &person){
   output << "Person: " << person.getName() << endl;
return output;
};

Vehicle::Vehicle()
{
   cout << "default Vehicle constructor" << endl;
}

Vehicle::Vehicle(string theManufacturer, int theCylinders, Person theOwner)
{
   cout << "paramerized Vehicle constructor" << endl;
   Manufacturer = theManufacturer;
   Cylinders = theCylinders;
   theOwner = theOwner.getName();
}

Vehicle::~Vehicle()
{
  cout << "Vehicle destructor" << endl;
}

Truck::Truck()
{
  cout << "default truck constructor" << endl;
}

Truck::Truck(string theManufacturer, int theCylinders, Person theOwner, double theLoadCapacity, int theTowCapacity)
{
  cout << "parameterized truck constructor" << endl;
  Manufacturer = theManufacturer;
  Cylinders = theCylinders;
  theOwner = theOwner.getName();
  loadCapacity = theLoadCapacity;
  towCapacity = theTowCapacity;
}

Truck::~Truck()
{
  cout << "truck destructor" << endl;
}
