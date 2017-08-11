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
  Point operator*(int scalar); //rescale P2=P1*3
  Point operator=(const Point &rhs); //assignment of P2=P1;
  bool operator==(const Point &rhs); //equality of two points

//friend functions
  friend Point operator*(int, Point &rhs); //rescale the point, P2=3*P1;
  //friend ostream & operator<<(ostream &os, Pointe &X);  

};

int main()
{

Point A; //uses default constructor
Point B(3,4,5); //uses parameterized constructor
Point C(2,4,6); //uses parameterized constructor
Point D = B; //uses copy constructor

int num = 0;
A.reset(6, 7, 8); //uses reset mutator
num = A.getx(); //uses accessor
cout << "A.X = " << num << endl;
num = A.gety(); //uses accessor
cout << "A.Y = " << num << endl;
num = A.getz(); //uses accessor
cout << "A.Z = " << num << endl;

//exam requested distance between y - x, in my program the equivalent points are C - B
//because the exam requested to return an int for the distance, the distance equals = 1, 
//but really the true distance is 1.414214 - should really return a float
int distance = C - B; //uses overloaded operator-
cout << "Distance C - B = " << distance << endl;

//verify overloaded assignment operator - this function uses two already existing obects
A=B; //uses overloadd assignment operator
num = A.getx(); //accessor
cout << "A.X = " << num;
num = B.getx(); //accessor
cout << " B.X = " << num << endl;
num = A.gety(); //accessor
cout << "A.Y = " << num;
num = B.gety(); //accessor
cout << " B.Y = " << num << endl;
num = A.getz(); //accessor
cout << "A.Z = " << num;
num = B.getz(); //accessor
cout << " B.Z = " << num << endl;

//verify the boolean equality overloaded operator
bool isequal = (A==B); //uses overladed boolean equality operator
cout << "A==B is " << isequal << "\n";
isequal = (C==B); //uses overloaded boolean equality operator
cout << "C==B is " << isequal << "\n";

//verify scale Point i.e. X*5
A.reset(5,5,5);
A = A*5;
num = A.getx();
cout << "A.X = " << num;
num = A.gety();
cout << "  A.Y = " << num;
num = A.getz();
cout << "  A.Z = " << num;
cout << "\n End of X*5 overload \n";


//verify scale Point 10*X
A.reset(10,10,10);
A = 10*A;
num = A.getx();
cout << "A.X = " << num;
num = A.gety();
cout << "  A.Y = " << num;
num = A.getz();
cout << "  A.Z = " << num;
cout << "\n End of 10*X overload \n";


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
  X = rhs.X;
  Y = rhs.Y;
  Z = rhs.Z;
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
   difYcoord = this->Y - rhs.Y;
   difZcoord = this->Z - rhs.Z;

   distance = pow(difXcoord, 2) + pow(difYcoord,2) + pow(difZcoord,2);
   distance = sqrt(distance);

return distance;
};

Point Point::operator*(int scalar){
   cout << "Entering the scalar overloaded operator X*5" << endl;
   X = X * scalar;
   Y = Y * scalar;
   Z = Z * scalar;

return *this;
}; 

Point operator*(int scale, Point &rhs){
   cout << "Entering the scalar overloaded operator 10*X" << endl;
return Point(scale * rhs.X, scale * rhs.Y, scale * rhs.Z);
};

 
Point Point::operator=(const Point &rhs){
   cout << "Entering the overloaded assignment operator " << endl;
   this->X = rhs.X;
   this->Y = rhs.Y;
   this->Z = rhs.Z;

};

bool Point::operator==(const Point &rhs){
  cout << "Entering boolean equality overloaded operator " << endl;
  if (rhs.X != this->X)
  {
     return false;
  }
  else if (rhs.Y != this->Y)
       {
          return false;
       }
       else if (rhs.Z != this->Z)
            {
               return false;
            }
            else
                 return true;
};

