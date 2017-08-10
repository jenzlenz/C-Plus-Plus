/* 
Program Name: Final2.cpp
Author: J Dooley
Date: August 7, 2017
Synopsis:
Design and code a point class in C++
*/

#include <iostream>
#include <cstring>
#include <cmath>
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

int num = 0;
A.reset(6, 7, 8);
num = A.getx();
cout << "A.X = " << num << endl;
num = A.gety();
cout << "A.Y = " << num << endl;
num = A.getz();
cout << "A.Z = " << num << endl;

//exam requested distance between y - x, in my program the equivalent points are C - B
//because the exam requested to return an int for the distance, the distance equals = 1, 
//but really the true distance is 1.414214 - should really return a float
int distance = C - B;
cout << "Distance C - B = " << distance << endl;

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

int Point::operator-(const Point &rhs){
//distance is sqrt of the sum of the squared differences between Point(x,y,z) and rhs(x,y,z)
   int difXcoord = 0;
   int difYcoord = 0;
   int difZcoord = 0;
   int distance = 0;
   
   difXcoord = this->X - rhs.X;
   cout << "difXcoord = " << difXcoord;
   difYcoord = this->Y - rhs.Y;
   cout << "difYcoord = " << difYcoord;
   difZcoord = this->Z - rhs.Z;
   cout << "difZcoord = " << difZcoord; 

   distance = pow(difXcoord, 2) + pow(difYcoord,2) + pow(difZcoord,2);
   distance = sqrt(distance);

return distance;
};
 
Point Point::operator*(int scale){

}; //rescale a point P2=P1*3; for example
 
Point Point::operator=(const Point &rhs){

}; //assignment of P2=P1;

bool Point::operator==(const Point &rhs){

}; //equality of two points

