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
#define PI 3.14159

enum COLOR {red, orange, yellow, green, blue, indigo, violet};

class Shape
{
protected:
//member variables
int x;
int y;
float area;
COLOR color;
string shapeType;
static int count;

public:
//constructors
Shape();//default constructor
Shape(int X, int Y, float Area, COLOR color);//parameterized constructor
~Shape();//destructor
Shape(const Shape &rhs);//copy constructor

//member functions
int getX() const;
int getY() const;
void setX(int X);
void setY(int Y);
void setColor(COLOR c);
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
Triangle(int X, int Y, int Base, int Height); //parameterized constructor
Triangle(const Triangle &rhs); //copy constructor
~Triangle(); //destructor

//member functions
float getBase() const;
float getHeight() const;
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
Rectangle(int X, int Y, int Base, int Height); //parameterized constructor
Rectangle(const Rectangle &rhs); //copy constructor
~Rectangle(); //destructor

//member functions
float getBase() const;
float getHeight() const;
float calcArea();
void drawObject();
};

class Circle:public Shape
{
protected:
float radius;

public:
//constructors
Circle(); //default constructor
Circle(int X, int Y, float Radius); //parameterized constructor
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
float innerRadius;

public:
//constructors
Doughnut(); //default constructor
Doughnut(int x, int y, float Radius, float InnerRadius); //parameterized constructor
Doughnut(const Doughnut &rhs); //copy constructor
~Doughnut(); //destructor

//member functions
float getInnerRadius() const;
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
Circle D = C;
cout << "The radius of Circle C is: " << C.getRadius() << endl;
cout << "The area of Circle C is: " << C.calcArea() << endl;
cout << "The radius of Circle D is: " << D.getRadius() << endl;
cout << "The area of Circle D is: " << D.calcArea() << endl;
C.drawObject();


//Testing Triangle Class
Triangle T;
Triangle U = T;
cout << "The area of Triangle T is: " << T.calcArea() << endl;
cout << "The area of Triangle U is: " << U.calcArea() << endl;
T.drawObject();


//Testing Rectangle Class
Rectangle R;
Rectangle S = R;
cout << "The area of Rectangle R is: " << R.calcArea() << endl;
cout << "The area of Rectangle S is: " << S.calcArea() << endl;
R.drawObject();

//Testing Doughnut Class
Doughnut J;
Doughnut K = J;
cout << "The radius of Doughnut J is: " << J.getRadius() << endl;
cout << "The area of Doughnut J is: " << J.calcArea() << endl;
cout << "The radius of Doughnut K is: " << K.getRadius() << endl;
cout << "The area of Doughnut is: " << K.calcArea() << endl;
J.drawObject();

return 0;
}

//Shape::Shape():x(0), y(0), area(0.0), shapeType(NULL){
Shape::Shape():x(0), y(0), area(0.0), color(red){
++count;
cout << "default SHAPE constructor: count = " << count << endl;
}

Shape::Shape(int X, int Y, float area, COLOR(green)):x(X), y(Y), area(getArea()){
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

int Shape::getX() const{
//cout << "SHAPE getX" << endl;
return x;
}

int Shape::getY() const{
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

void Shape::setColor(COLOR c){
cout << "SHAPE set color" << endl;
switch(c){
 case red:{ 
      color = red;
      break;}
 case orange:{ 
      color = orange;
      break;}
 case yellow:{ 
      color = yellow;
      break;}
 case green:{ 
      color = green;
      break;}
 case blue:{ 
      color = blue;
      break;}
 case indigo:{ 
      color = indigo;
      break;}
 case violet:{ 
      color = violet;
      break;}
}
};

float Shape::calcArea(){
//cout << "Calculating Area for SHAPE" << endl;
return 0.0;
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

Circle::Circle(int X, int Y, float Radius){
setX(X);
setY(Y);
radius = Radius;
cout << "CIRCLE parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Circle::Circle(const Circle &rhs){
radius = rhs.radius;
}; //copy constructor

Circle::~Circle(){
cout << "CIRCLE destructor: count = " << count << endl;
}; //destructor

//member functions
float Circle::getRadius(){
return radius;
};

float Circle::calcArea(){
//cout << "Calculating Area for CIRCLE" << endl;
area = PI*radius*radius;
return area;
};

void Circle::drawObject(){
cout << "Drawing CIRCLE" << endl;
}

Triangle::Triangle():base(0), height(0){
cout << "TRIANGLE default constructor: count = " << count << endl;
}; //default constructor

Triangle::Triangle(int X, int Y, int Base, int Height){
setX(X);
setY(Y);
base = Base;
height = Height;
cout << "TRIANGLE parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Triangle::Triangle(const Triangle &rhs){
base = rhs.base;
height = rhs.height;
}; //copy constructor

Triangle::~Triangle(){
cout << "TRIANGLE destructor: count = " << count << endl;
}; //destructor

float Triangle::getBase() const{
return base;
};

float Triangle::getHeight() const{
return height;
};

float Triangle::calcArea(){
//cout << "Calculating Area for TRIANGLE" << endl;
area = (base*height)/2;
return area;
};

void Triangle::drawObject(){
cout << "Drawing TRIANGLE" << endl;
}

Rectangle::Rectangle():base(0), height(0){
cout << "RECTANGLE default constructor: count = " << count << endl;
}; //default constructor

Rectangle::Rectangle(int X, int Y, int Base, int Height){
setX(X);
setY(Y);
base = Base;
height = Height;
cout << "RECTANGLE parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Rectangle::Rectangle(const Rectangle &rhs){
base = rhs.base;
height = rhs.height;
}; //copy constructor

Rectangle::~Rectangle(){
cout << "RECTANGLE destructor: count = " << count << endl;
}; //destructor

float Rectangle::getBase() const{
return base;
};

float Rectangle::getHeight() const{
return height;
};

float Rectangle::calcArea(){
//cout << "Calculating Area for RECTANGLE" << endl;
area = base * height;
return area;
};

void Rectangle::drawObject(){
cout << "Drawing RECTANGLE" << endl;
}

Doughnut::Doughnut(){
cout << "DOUGHNUT default constructor: count = " << count << endl;
}; //default constructor

Doughnut::Doughnut(int X, int Y, float Radius, float IR){
setX(X);
setY(Y);
radius = Radius;
innerRadius = IR;
cout << "DOUGHNUT parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Doughnut::Doughnut(const Doughnut &rhs){
//x = rhs.X;
//y = rhs.Y;
radius = rhs.radius;
innerRadius = rhs.innerRadius;
}; //copy constructor

Doughnut::~Doughnut(){
cout << "DOUGHNUT destructor: count = " << count << endl;
}; //destructor

float Doughnut::getInnerRadius() const{
return innerRadius;
};

float Doughnut::calcArea(){
//cout << "Calculating Area for DOUGHNUT" << endl;
area = PI * (pow(radius, 2) - pow(innerRadius, 2));
return area;
};

void Doughnut::drawObject(){
cout << "Drawing DOUGHNUT" << endl;
}

