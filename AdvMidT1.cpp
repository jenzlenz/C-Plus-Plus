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
protected:
//member variables
int x;
int y;
float area;
COLOR color;
//string shapeType;
static int count;

public:
//constructors
Shape();//default constructor
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

int Shape::count = 0; // initialization of static int count variable must be outside of class

class Triangle:public Shape
{
private:
int base;
int height;

public:
//constructors
Triangle(); //default constructor
Triangle(const Triangle &rhs); //copy constructor
~Triangle(); //destructor

//member functions
float calcArea();
void drawObject();
};

class Rectangle:public Shape
{
private:
int base;
int height;

public:
//constructors
Rectangle(); //default constructor
Rectangle(const Rectangle &rhs); //copy constructor
~Rectangle(); //destructor

//member functions
float calcArea();
void drawObject();
};

class Circle:public Shape
{
private:
float radius;

public:
//constructors
Circle(); //default constructor
Circle(const Circle &rhs); //copy constructor
~Circle(); //destructor

//member functions
float getRadius();
float calcArea();
void drawObject();
};

class Doughnut:public Circle
{
private:
float radius;

public:
//constructors
Doughnut(); //default constructor
Doughnut(const Doughnut &rhs); //copy constructor
~Doughnut(); //destructor

//member functions
float calcArea();
void drawObject();
};




int main()
{

//Testing Shape Base Class
//Shape A;
//A.setX(5);
//A.setY(10);
//cout << " The X of object A is equal to : " << A.getX() << endl;
//cout << " The Y of object A is equal to : " << A.getY() << endl;
//Shape B = A;
//cout << "The area of object A is: " << A.calcArea() << endl;
//A.drawObject();
//A.resetLocation(8,8);
//cout << " The X of object A after resetLocation is equal to : " << A.getX() << endl;
//cout << " The Y of object A after resetLocation is equal to : " << A.getY() << endl;
//cout << "The area of object A is: " << A.getArea() << endl;
//cout << "The color of object A is: " << A.getColor() << endl;

//Testing Circle Class
Circle C;
cout << "The radius of Circle C is: " << C.getRadius() << endl;
cout << "The area of Circle C is: " << C.calcArea() << endl;
C.drawObject();
Circle D = C;

//Testing Triangle Class
Triangle T;
cout << "The area of Triangle T is: " << T.calcArea() << endl;
T.drawObject();
Triangle U = T;

//Testing Rectangle Class
Rectangle R;
cout << "The area of Rectangke R is: " << R.calcArea() << endl;
R.drawObject();
Rectangle S = R;

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
x += deltaX;
y += deltaY;
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

Circle::Circle(){
cout << "CIRCLE default constructor: count = " << count << endl;
}; //default constructor

Circle::Circle(const Circle &rhs){
//x = rhs.X;
//y = rhs.Y;
radius = rhs.radius;
}; //copy constructor

Circle::~Circle(){
cout << "CIRCLE destructor: count = " << count << endl;
}; //destructor

//member functions
float Circle::getRadius(){
return (radius = 5.5);
};

float Circle::calcArea(){
//cout << "Calculating Area for CIRCLE" << endl;
return 99.99;
};

void Circle::drawObject(){
cout << "Drawing CIRCLE" << endl;
}

Triangle::Triangle(){
cout << "TRIANGLE default constructor: count = " << count << endl;
}; //default constructor

Triangle::Triangle(const Triangle &rhs){
//x = rhs.X;
//y = rhs.Y;
//radius = rhs.radius;
}; //copy constructor

Triangle::~Triangle(){
cout << "TRIANGLE destructor: count = " << count << endl;
}; //destructor

float Triangle::calcArea(){
//cout << "Calculating Area for TRIANGLE" << endl;
return 33.33;
};

void Triangle::drawObject(){
cout << "Drawing TRIANGLE" << endl;
}

Rectangle::Rectangle(){
cout << "RECTANGLE default constructor: count = " << count << endl;
}; //default constructor

Rectangle::Rectangle(const Rectangle &rhs){
//x = rhs.X;
//y = rhs.Y;
//radius = rhs.radius;
}; //copy constructor

Rectangle::~Rectangle(){
cout << "RECTANGLE destructor: count = " << count << endl;
}; //destructor

float Rectangle::calcArea(){
//cout << "Calculating Area for RECTANGLE" << endl;
return 44.44;
};

void Rectangle::drawObject(){
cout << "Drawing RECTANGLE" << endl;
}


