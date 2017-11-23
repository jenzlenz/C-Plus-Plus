/*
Program Name: AdvMidT1.cpp
Author: Jennifer Dooley
Date: November 22, 2017
Synopsis:  Create a program that contains abase class Shape and subclasses and write the proper constructors, destructors, methods to manipulate various piece of data in all classes.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

enum COLOR {red, orange, yellow, green, blue, indigo, violet};

class Shape
{
private:
//member variables
int x;
int y;
float area;
COLOR color;
//string shapeType;
static int count;

public:
//constructors
Shape();//default
Shape(int X, int Y, float Area, COLOR color);//parameterized constructor
~Shape();//destructor
Shape(const Shape &rhs);//copy constructor
//overloaded functions
//assignment operator

//member functions
int getX();
int getY();
void setX(int X);
void setY(int Y);
float calcArea();//virtual
void drawObject();//virtual
void resetLocation(int deltaX, int deltaY);
float getArea() const;
COLOR getColor() const;
};

int Shape::count = 0;

int main()
{
Shape A;
A.setX(5);
A.setY(10);
cout << " The X of object A is equal to : " << A.getX() << endl;
cout << " The Y of object A is equal to : " << A.getY() << endl;
Shape B = A;
cout << "The area of object A is: " << A.calcArea() << endl;
A.drawObject();
A.resetLocation(8,8);
cout << " The X of object A after resetLocation is equal to : " << A.getX() << endl;
cout << " The Y of object A after resetLocation is equal to : " << A.getY() << endl;
cout << "The area of object A is: " << A.getArea() << endl;
cout << "The color of object A is: " << A.getColor() << endl;
return 0;
}

//Shape::Shape():x(0), y(0), area(0.0), shapeType(NULL){
Shape::Shape():x(0), y(0), area(0.0), color(red){
++count;
cout << "default SHAPE constructor: count = " << count << endl;
}

Shape::Shape(int X, int Y, float area, COLOR(green)):x(X), y(Y), area(getArea()){
//int len = strlen(shapeTYPE);
//shapeType = new char[len+1];
//strcpy(shapeType, shapeTYPE);
++count;
cout << "SHAPE Parameterized Constructor: count = " << count << endl;
} 

Shape::~Shape(){
--count;
cout << "SHAPE destructor: count = " << count << endl; 
}

Shape::Shape(const Shape &rhs){
x = rhs.x;
y = rhs.y;
area = rhs.area;
color = rhs.color;
++count;
cout << "SHAPE copy constructor: count = " << count << endl;
}

int Shape::getX(){
//cout << "SHAPE getX" << endl;
return x;
}

int Shape::getY(){
//cout << "SHAPE getY" << endl;
return y;
}

void Shape::setX(int X){
x = X;
//cout << "SHAPE set X" << endl;
}

void Shape::setY(int Y){
y = Y;
//cout << "SHAPE set Y" << endl;
}

float Shape::calcArea(){
//cout << "Calculating Area for SHAPE" << endl;
return 88.88;
}

void Shape::drawObject(){
cout << "Drawing SHAPE" << endl;
}

void Shape::resetLocation(int deltaX, int deltaY){
x = x + deltaX;
y = y + deltaY;
//cout << "SHAPE reset location function" << endl;
}

float Shape::getArea()const{
//cout << "getting the area of SHAPE" << endl;
return area;
}

COLOR Shape::getColor()const{
//cout << "Inside SHAPE get color function - color = : " << color << endl;
return color;
}

