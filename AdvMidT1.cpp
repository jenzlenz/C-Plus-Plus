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

//accessors
int getX() const;
int getY() const;
float getArea() const;
COLOR getColor() const;

//mutators
void setX(int X);
void setY(int Y);
void setArea(float);
void setColor(COLOR c);
virtual void setShapeType() = 0;//virtual

//member functions
virtual float calcArea() = 0;//virtual
virtual void drawObject() = 0;//virtual
void resetLocation(int deltaX, int deltaY);

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
virtual float calcArea();
virtual void drawObject();
virtual void setShapeType();
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
virtual float calcArea();
virtual void drawObject();
virtual void setShapeType();
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
float getRadius() const;
virtual void setShapeType();
void setRadius(float R);
void setArea(float);
virtual float calcArea();
virtual void drawObject();

//overloaded scalar functions
Circle operator*(int scalar); 
friend Circle operator*(int scale, Circle &rhs);

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
float getRadius() const;
float getInnerRadius() const;
virtual float calcArea();
virtual void drawObject();
virtual void setShapeType();
};




int main()
{
/* Commenting out all my testing
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
//Circle C;
//Circle D = C;
Circle E(30, 30, 5);
Circle F(50, 50, 10);
//cout << endl << "The radius of Circle C is: " << C.getRadius() << endl;
//cout << "The area of Circle C is: " << C.calcArea() << endl;
//cout << "The radius of Circle D is: " << D.getRadius() << endl;
//cout << "The area of Circle D is: " << D.calcArea() << endl;
cout << "The radius of Circle E is: " << E.getRadius() << endl;
cout << "The area of Circle E is: " << E.calcArea() << endl;
cout << "The radius of Circle F is: " << F.getRadius() << endl;
cout << "The area of Circle F is: " << F.calcArea() << endl;
E.drawObject();

//Testing Triangle Class
//Triangle T;
//Triangle U = T;
Triangle V(15, 20, 5, 10);
//cout << endl << "The area of Triangle T is: " << T.calcArea() << endl;
//cout << "The area of Triangle U is: " << U.calcArea() << endl;
cout << "The area of Triangle V is: " << V.calcArea() << endl;
V.drawObject();

//Testing Rectangle Class
//Rectangle R;
//Rectangle S = R;
Rectangle P(150, 150, 15, 10);
Rectangle Q(100, 100, 5, 15);
//cout << "The area of Rectangle R is: " << R.calcArea() << endl;
//cout << "The area of Rectangle S is: " << S.calcArea() << endl;
cout << "The area of Rectangle P is: " << P.calcArea() << endl;
cout << "The area of Rectangle Q is: " << Q.calcArea() << endl;
P.drawObject();

//Testing Doughnut Class
//Doughnut J;
//Doughnut K = J;
Doughnut L(40, 70, 5, 10);
//cout << "The radius of Doughnut J is: " << J.getInnerRadius() << endl;
//cout << "The area of Doughnut J is: " << J.calcArea() << endl;
//cout << "The radius of Doughnut K is: " << K.getInnerRadius() << endl;
//cout << "The area of Doughnut K is: " << K.calcArea() << endl;
cout << "The radius of Doughnut L is: " << L.getRadius() << endl;
cout << "The inner radius of Doughnut L is: " << L.getInnerRadius() << endl;
cout << "The area of Doughnut L is: " << L.calcArea() << endl;
L.drawObject();
Commenting out all my testing */

Shape* shape_ptr[6];
shape_ptr[0] = new Circle(30, 30, 5);
shape_ptr[1] = new Circle(50, 50, 10);
shape_ptr[2] = new Triangle(15, 20, 5, 10);
shape_ptr[3] = new Rectangle(150, 150, 15, 10);
shape_ptr[4] = new Rectangle(100, 100, 5, 15);
shape_ptr[5] = new Doughnut(40, 70, 5, 15);

for (int i=0; i<6; ++i){
   cout << "X = " << shape_ptr[i]->getX() << endl;
   cout << "Y = " << shape_ptr[i]->getY() << endl;
   shape_ptr[i]->calcArea();
   cout << "Area = " << shape_ptr[i]->getArea() << endl;
   cout << "Color = " << shape_ptr[i]->getColor() << endl;
   //shape_ptr[i]->getShapeType();
};




return 0;
}

//Shape::Shape():x(0), y(0), area(0.0), shapeType(NULL){
Shape::Shape():x(0), y(0), area(0.0), color(red){
++count;
cout << "default SHAPE constructor: count = " << count << endl;
}

Shape::Shape(int X, int Y, float area, COLOR(red)):x(X), y(Y), area(getArea()){
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

void Shape::setShapeType(){
shapeType = " ";
};

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

void Shape::setArea(float A){
area = A;
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
setX(0);
setY(0);
setRadius(0);
setColor(violet);
cout << "CIRCLE default constructor: count = " << count << endl;
}; //default constructor

Circle::Circle(int X, int Y, float Radius){
setX(X);
setY(Y);
radius = Radius;
setColor(violet);
cout << "CIRCLE parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Circle::Circle(const Circle &rhs){
setX(rhs.x);
setY(rhs.y);
radius = rhs.radius;
setColor(rhs.color);
}; //copy constructor

Circle::~Circle(){
cout << "CIRCLE destructor: count = " << count << endl;
}; //destructor

float Circle::getRadius() const{
return radius;
};

void Circle::setRadius(float R) {
radius = R;
};

void Circle::setShapeType(){
shapeType = "Circle";
};

float Circle::calcArea(){
//cout << "Calculating Area for CIRCLE" << endl;
area = PI*radius*radius;
setArea(area);
return area;
};

void Circle::setArea(float A){
area = A;
};

void Circle::drawObject(){
cout << "Drawing CIRCLE" << endl;
}

Circle Circle::operator*(int scalar){
   cout << "Entering the scalar overloaded operator X*10" << endl;
   setX(getX() * scalar);
   setY(getY() * scalar);
   radius = radius * scalar;
   setArea(calcArea());
return *this;
}; 

Circle operator*(int scale, Circle &rhs){
   cout << "Entering the scalar overloaded operator 10*X" << endl;
return Circle(scale * rhs.getX(), scale * rhs.getY(), scale * rhs.getRadius());
};

Triangle::Triangle():base(0), height(0){
setX(x);
setY(y);
setColor(orange);
cout << "TRIANGLE default constructor: count = " << count << endl;
}; //default constructor

Triangle::Triangle(int X, int Y, int Base, int Height){
setX(X);
setY(Y);
base = Base;
height = Height;
setColor(orange);
cout << "TRIANGLE parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Triangle::Triangle(const Triangle &rhs){
setX(rhs.x);
setY(rhs.y);
base = rhs.base;
height = rhs.height;
color = rhs.color;
}; //copy constructor

Triangle::~Triangle(){
cout << "TRIANGLE destructor: count = " << count << endl;
}; //destructor

float Triangle::getBase() const{
return base;
};

void Triangle::setShapeType(){
shapeType = "Triangle";
};

float Triangle::getHeight() const{
return height;
};

float Triangle::calcArea(){
//cout << "Calculating Area for TRIANGLE" << endl;
area = (base*height)/2;
setArea(area);
return area;
};

void Triangle::drawObject(){
cout << "Drawing TRIANGLE" << endl;
}

Rectangle::Rectangle():base(0), height(0){
setColor(indigo);
cout << "RECTANGLE default constructor: count = " << count << endl;
}; //default constructor

Rectangle::Rectangle(int X, int Y, int Base, int Height){
setX(X);
setY(Y);
setColor(indigo);
base = Base;
height = Height;

cout << "RECTANGLE parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Rectangle::Rectangle(const Rectangle &rhs){
setX(rhs.x);
setY(rhs.y);
base = rhs.base;
height = rhs.height;
color = rhs.color;
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

void Rectangle::setShapeType(){
shapeType = "Rectangle";
};

float Rectangle::calcArea(){
//cout << "Calculating Area for RECTANGLE" << endl;
area = base * height;
setArea(area);
return area;
};

void Rectangle::drawObject(){
cout << "Drawing RECTANGLE" << endl;
}

Doughnut::Doughnut(){
setX(0);
setY(0);
setColor(blue);
radius = 0.0;
innerRadius = 0.0;
cout << "DOUGHNUT default constructor: count = " << count << endl;
}; //default constructor

Doughnut::Doughnut(int X, int Y, float Radius, float IR){
setX(X);
setY(Y);
setColor(blue);
radius = Radius;
innerRadius = IR;
cout << "DOUGHNUT parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Doughnut::Doughnut(const Doughnut &rhs){
setX(rhs.x);
setY(rhs.y);
radius = rhs.radius;
innerRadius = rhs.innerRadius;
color = rhs.color;
}; //copy constructor

Doughnut::~Doughnut(){
cout << "DOUGHNUT destructor: count = " << count << endl;
}; //destructor

float Doughnut::getRadius() const{
Circle::getRadius();
};

float Doughnut::getInnerRadius() const{
return innerRadius;
};

void Doughnut::setShapeType(){
shapeType = "Doughnut";
};

float Doughnut::calcArea(){
//cout << "Calculating Area for DOUGHNUT" << endl;
area = PI * (pow(radius, 2) - pow(innerRadius, 2));
setArea(area);
return area;
};

void Doughnut::drawObject(){
cout << "Drawing DOUGHNUT" << endl;
}

