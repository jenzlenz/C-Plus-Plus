/* 
Program Name: ch15no1.cpp
Author: J Dooley
Date: October 24, 2017
Synopsis:
Create base class called Figure with two derived classes, Rectangle and Triangle.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Figure
{  
public:
  Figure();			//default constructor
  ~Figure();			//destructor
  void erase();
  void draw();
  void center();
};

class Rectangle:public Figure
{
public:
  Rectangle();		
  ~Rectangle(); 		
  void erase();
  void draw();
  void center();
};

class Triangle:public Figure
{
public:
  Triangle();  
  ~Triangle();
  void erase();
  void draw();
  void center();
};


int main()
{

Rectangle R;
Figure *ptrR= &R;

ptrR->draw();
cout << "Derived class RECTANGLE object calling center()." << endl;
ptrR->center();

Triangle T;
Figure *ptrT= &T;

ptrT->draw();
cout << "Derived class TRIANGLE object calling center()." << endl;
ptrT->center();

return 0;
}

Figure::Figure(){
  cout << "default FIGURE constructor" << endl;
}

Figure::~Figure(){
  cout << "FIGURE destructor" << endl;
}

void Figure::erase(){
  cout << "FIGURE erase has been called" << endl;
}

void Figure::draw(){
  cout << "FIGURE draw has been called" << endl;
}

void Figure::center(){
  cout << "FIGURE center has been called" << endl;
  erase();
  draw();
}

Rectangle::Rectangle(){
   cout << "default RECTANGLE constructor" << endl;
}

Rectangle::~Rectangle(){
  cout << "RECTANGLE destructor" << endl;
}

void Rectangle::erase(){
  cout << "RECTANGLE erase has been called" << endl;
}

void Rectangle::draw(){
  cout << "RECTANGLE draw has been called" << endl;
}

void Rectangle::center(){
  cout << "RECTANGLE center has been called" << endl;
  erase();
  draw();
}

Triangle::Triangle(){
   cout << "default TRIANGLE constructor" << endl;
}

Triangle::~Triangle(){
  cout << "TRIANGLE destructor" << endl;
}

void Triangle::erase(){
  cout << "TRIANGLE erase has been called" << endl;
}

void Triangle::draw(){
  cout << "TRIANGLE draw has been called" << endl;
}

void Triangle::center(){
  cout << "TRIANGLE center has been called" << endl;
  erase();
  draw();
}



