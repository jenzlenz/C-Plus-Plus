/* 
Program Name: Final2.cpp
Author: J Dooley
Date: August 7, 2017
Synopsis:
Design and code a point class in C++
*/

#include <iostream>
#include <cstring>
using namespace std;

class Point
{
private:
  int X, Y, Z;

public:

//constructors and deconstructor
  Point(); 			//default constructor
  Point(int, int, int); 	//parameterized constructor
  ~Point(); 			//deconstructor
  Point(const Point & rhs); 	//copy constructor

//mutators and accessors
  void reset(int x, int y, int z); //resets the values of x, y, z
  int getx()const; //gets and returns X for a given point object
  int gety()const; //gets and returns Y fr a given point object
  int getz()const; // gets and returns Z for a given point object

//overloaded operators
  int operator-(const Point &rhs); //distance between two points
  Point operator*(int scale); //rescale a point P2=P1*3; for example
  Point operator=(const Point &rhs); //assignment of P2=P1;
  bool operator==(const Point &rhs); //equality of two points

//friend functions
  //friend Point operator*(it, Point &); //rescale the point, P2=3*P1;
  //friend ostream & operator<<(ostream &os, Pointe &X);  

};

int main()
{

Point A;
Point B(3,4,5);
Point C(2,4,6);
Point D = B; //uses copy constructor

return 0;
}

Point::Point():X(0),Y(0),Z(0){
  cout << "default constructor" << endl;
}

Point::Point(int X, int Y, int Z):X(X),Y(Y),Z(Z){
  cout << "Parameterized constructor" << endl;
}

Point::~Point(){
  //deconstructor is empty because here is no object to create on the heap
  //int are created on the stack
  cout << "deconstructor" << endl;
}

Point::Point(const Point & rhs){
  cout << "Entering copy constructor \n";
  this->X = rhs.X;
  this->Y = rhs.Y;
  this->Z = rhs.Z;
  cout << "Exiting copy contructor \n";
}

void Point::reset(int a, int b, int c){
  X = a;
  Y = b;
  Z = c;
}

int Point::getx()const{
  return X;
}

int Point::gety()const{
  return Y;
}

int Point::getz()const{
  return Z;
}

