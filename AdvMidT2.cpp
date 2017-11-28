/* 
Program Name: AdvMidT2.cpp
Author: J Dooley
Date: November 26, 2017
Synopsis:
Design and code a point class in C++.  
Demonstrate exception handling if any of the coordinates are negative.  
Integrate the Point class inside a class Person.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class negativeXCoord{}; //for exception try/throw/catch 
class negativeYCoord{}; //for exception try/throw/catch

class Point
{
protected:
  int X, Y;

public:

//constructors and destructor
  Point(); 			//default constructor
  Point(int, int);      	//parameterized constructor
  ~Point(); 			//destructor
  Point(const Point & rhs); 	//copy constructor

//mutators and accessors
  void reset(int x, int y); //resets the values of x, y
  int getx()const; //gets and returns X for a given point object
  int gety()const; //gets and returns Y fr a given point object

//overloaded operators
  int operator-(const Point &rhs); //distance between two points
  Point operator*(int scalar); //rescale P2=P1*3
  Point operator=(const Point &rhs); //assignment of P2=P1;
  bool operator==(const Point &rhs); //equality of two points

//friend functions
  friend Point operator*(int, Point &rhs); //rescale the point, P2=3*P1;
  friend ostream &operator << (ostream& output, Point &pt);  
  friend void foo(Point &x, Point y); //prints x and y coords by reference and by value

};

class Person
{
private:
char Name[32];
int Age;
Point GPS;

public:

//constructors and destructor
  Person();
  Person(char *, int, int x, int y);
  ~Person();
  Person(const Person &rhs);

//mutators and accessors
//  char getName() const;
  int getAge() const;
  Point getGPS() const;

//overloaded operators
  int operator-(const Person &rhs);
};

int main()
{

Point A; 	//uses default constructor
Point B(3,4); //uses parameterized constructor
Point C(10,40); //uses parameterized constructor
Point D = B; 	//uses copy constructor

int num = 0;
A.reset(6, 7); 	//uses reset mutator
num = A.getx(); 	//uses accessor
cout << "A.X = " << num << endl;
num = A.gety(); 	//uses accessor
cout << "A.Y = " << num << endl << endl;

//exam requested distance between y - x, in my program the equivalent points are C - B
//because the exam requested to return an int for the distance, the distance equals = 1, 
//but really the true distance is 1.414214 - should really return a float
int distance = C - B; 	//uses overloaded operator-
cout << "Distance C - B = " << distance << endl << endl;

//verify overloaded assignment operator - this function uses two already existing obects
A=B; 			//uses overloaded assignment operator
num = A.getx(); 	//accessor
cout << "A.X = " << num;
num = B.getx(); 	//accessor
cout << " B.X = " << num << endl;
num = A.gety(); 	//accessor
cout << "A.Y = " << num;
num = B.gety(); 	//accessor
cout << " B.Y = " << num << endl << endl;

//verify the boolean equality overloaded operator
bool isequal = (A==B); 		//uses overladed boolean equality operator
cout << "A==B is " << isequal << "\n";
isequal = (C==B); 		//uses overloaded boolean equality operator
cout << "C==B is " << isequal << "\n" << endl;

//verify scale Point X*10
A.reset(3,4);
A = A*10;
num = A.getx();
cout << "A.X = " << num;
num = A.gety();
cout << "  A.Y = " << num;
cout << "\n End of X*10 overload " << endl << endl;

//verify scale Point 10*X
A.reset(3,4);
A = 10*A;
num = A.getx();
cout << "A.X = " << num;
num = A.gety();
cout << "  A.Y = " << num;
cout << "\n End of 10*X overload " << endl << endl;

cout << "Verifying ostream overloaded operator " << endl;
cout << A << endl;
cout << B << endl;
cout << C << endl;
cout << D << endl;
cout << "End of ostream verification. " << endl << endl;

//passing point objects by reference and by value and printing x,y coordinates
Point *ptr = new Point(-2,3);
foo(*ptr, C); 

//testing for negative value in Point objects
Point E(-1,0);
Point F(0,-1);
Point G(-1,-1);

Person Z; //default constructor
Person X("Joe Doe", 33, 10, 15);
Person Y("Mary Joe", 22, 20, 30);
cout << "The distance between Person X and Person Y is: " << Y-X << endl;

return 0;
}

Point::Point():X(0),Y(0){
  cout << "default constructor" << endl;
}

Point::Point(int X, int Y):X(X),Y(Y){
  try{
  if (X < 0)
     throw negativeXCoord();
  if (Y < 0)
     throw negativeYCoord();
  } //end of try block

  catch(negativeXCoord){
     cout << "X coordinate of point can NOT be negative.  X entered was: " << X << endl << endl; 
  } //end of catch block 
  catch(negativeYCoord){
     cout << "Y coordinate of point can NOT be negative.  Y entered was: " << Y << endl << endl;                
  } //end of catch block

  cout << "Parameterized constructor" << endl;
}


Point::~Point(){
  //deconstructor is empty because here is no object to create on the heap
  //int are created on the stack
  cout << "destructor" << endl;
}

Point::Point(const Point & rhs){
  cout << "Entering copy constructor \n";
  X = rhs.X;
  Y = rhs.Y;
}

void Point::reset(int a, int b){
  X = a;
  Y = b;
}

int Point::getx()const{
  return X;
}

int Point::gety()const{
  return Y;
}

void foo(Point &x, Point y){
  cout << endl << "Inside function foo " << endl;
  cout << "Point by reference: (" << x.X << "," << x.Y << ")" << endl;
  cout << "Point by value: (" << y.X << "," << y.Y << ")" << endl << endl;
};

int Point::operator-(const Point &rhs){
//distance is sqrt of the sum of the squared differences between Point(x,y,z) and rhs(x,y,z)
   int difXcoord = 0;
   int difYcoord = 0;
   int distance = 0;
   
   difXcoord = this->X - rhs.X;
   difYcoord = this->Y - rhs.Y;

   distance = pow(difXcoord, 2) + pow(difYcoord,2);
   distance = sqrt(distance);

return distance;
};

Point Point::operator*(int scalar){
   cout << "Entering the scalar overloaded operator X*10" << endl;
   X = X * scalar;
   Y = Y * scalar;

return *this;
}; 

Point operator*(int scale, Point &rhs){
   cout << "Entering the scalar overloaded operator 10*X" << endl;
return Point(scale * rhs.X, scale * rhs.Y);
};

 
Point Point::operator=(const Point &rhs){
   cout << "Entering the overloaded assignment operator " << endl;
   this->X = rhs.X;
   this->Y = rhs.Y;

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
       else 
            return true;
};

ostream &operator << (ostream& output, Point &pt){
   output << "Point(" << pt.X << "," << pt.Y << ")" << endl;
return output;
};

Person::Person(){
   cout << "Person default constructor" << endl << endl;
   for (int i=0; i<32; i++)
        Name[i]='\0';
   int Age = 0;
   GPS.reset(0,0);
};

Person::Person(char *name, int age, int x, int y):Age(age),GPS(x,y){
   cout << "Person parameterized constructor " << endl << endl;
   int len = strlen(name) + 1;
   name = new char[len];
   strcpy(Name, name);
   //Age = age;
   //GPS.X = x;
   //GPS.Y = y;
};

Person::~Person(){
   cout << "Person destructor " << endl << endl;
};

Person::Person(const Person &rhs){
   cout << "Person copy constructor " << endl << endl;
   strcpy(Name, rhs.Name);//I know this is a shallow copy
   
//deep copy does NOT compile
//   delete[]Name;
//   Name = new char[strlen(rhs.Name)+1];
//   strcpy(Name, rhs.Name);
//end deep copy
   Age = rhs.Age;
   GPS = rhs.GPS;
};

// this does not compile
//char Person::getName(){
//   return Name;
//};
 

int Person::getAge()const{
   return Age;
};
  

Point Person::getGPS()const{
   return GPS;
};

int Person::operator-(const Person &rhs){
   int difXcoord = 0;
   int difYcoord = 0;
   int distance = 0;
   
   difXcoord = GPS.getx() - rhs.GPS.getx();
   difYcoord = GPS.gety() - rhs.GPS.gety();

   distance = pow(difXcoord, 2) + pow(difYcoord,2);
   distance = sqrt(distance);

return distance;
};
