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
string getShapeType() const;

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
//void SortShape(Shape* S_ptr[], int n); not compiling
float getDistance(Shape &rhs);
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
Shape* shape_ptr[6];
shape_ptr[0] = new Circle(30, 30, 5);
shape_ptr[1] = new Circle(50, 50, 10);
shape_ptr[2] = new Triangle(15, 20, 5, 10);
shape_ptr[3] = new Rectangle(150, 150, 15, 10);
shape_ptr[4] = new Rectangle(100, 100, 5, 15);
shape_ptr[5] = new Doughnut(40, 70, 5, 15);

for (int i=0; i<6; ++i){
   cout << "Object " << i+1 << " is a: " << shape_ptr[i]->getShapeType() << " ";
   cout << "X = " << shape_ptr[i]->getX() << " ";
   cout << "Y = " << shape_ptr[i]->getY() << " ";
   shape_ptr[i]->calcArea();
   cout << "Area = " << shape_ptr[i]->getArea() << " ";
   cout << "Color = " << shape_ptr[i]->getColor() << endl;
};
      
//SortShape(*shape_ptr[], 6); not compiling

Circle C1(0, 0, 10);
Circle C2(3, 4, 15);
cout << "The distance between C1 and C2 is: " << C1.getDistance(C2) << endl;

return 0;
}

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

float Shape::getDistance(Shape &rhs){
   float distance = 0;
   int difXcoord = 0;
   int difYcoord = 0;
   
   difXcoord = this->x - rhs.x;
   difYcoord = this->y - rhs.y;

   distance = pow(difXcoord, 2) + pow(difYcoord,2);
   distance = sqrt(distance);
return distance;
};

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

string Shape::getShapeType() const{
return shapeType;
};

/* not compiling
void Shape::SortShape(Shape* S_ptr[], int n){
//Sorting by the area of each shape
	for(int i = 0; i<=4; i++)
        for(int j=i+1; j <= n; j++)
            if(S_ptr(i)->getArea() > S_ptr(j)->getArea())
            {
                float temp = *S_ptr();
                *S_ptr(i) = *S_ptr(j);
                *S_ptr(j) = temp;
            } 
};
not compiling */

Circle::Circle(){
setX(0);
setY(0);
setRadius(0);
setColor(violet);
setShapeType();
cout << "CIRCLE default constructor: count = " << count << endl;
}; //default constructor

Circle::Circle(int X, int Y, float Radius){
setX(X);
setY(Y);
radius = Radius;
setColor(violet);
setShapeType();
cout << "CIRCLE parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Circle::Circle(const Circle &rhs){
setX(rhs.x);
setY(rhs.y);
radius = rhs.radius;
setColor(rhs.color);
shapeType= rhs.shapeType;
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
setShapeType();
cout << "TRIANGLE default constructor: count = " << count << endl;
}; //default constructor

Triangle::Triangle(int X, int Y, int Base, int Height){
setX(X);
setY(Y);
base = Base;
height = Height;
setColor(orange);
setShapeType();
cout << "TRIANGLE parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Triangle::Triangle(const Triangle &rhs){
setX(rhs.x);
setY(rhs.y);
base = rhs.base;
height = rhs.height;
color = rhs.color;
shapeType = rhs.shapeType;
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
setShapeType();
cout << "RECTANGLE default constructor: count = " << count << endl;
}; //default constructor

Rectangle::Rectangle(int X, int Y, int Base, int Height){
setX(X);
setY(Y);
setColor(indigo);
base = Base;
height = Height;
setShapeType();
cout << "RECTANGLE parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Rectangle::Rectangle(const Rectangle &rhs){
setX(rhs.x);
setY(rhs.y);
base = rhs.base;
height = rhs.height;
color = rhs.color;
shapeType = rhs.shapeType;
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
setShapeType();
cout << "DOUGHNUT default constructor: count = " << count << endl;
}; //default constructor

Doughnut::Doughnut(int X, int Y, float Radius, float IR){
setX(X);
setY(Y);
setColor(blue);
radius = Radius;
innerRadius = IR;
setShapeType();
cout << "DOUGHNUT parameterized constructor: count = " << count << endl;
}; //parameterized constructor

Doughnut::Doughnut(const Doughnut &rhs){
setX(rhs.x);
setY(rhs.y);
radius = rhs.radius;
innerRadius = rhs.innerRadius;
color = rhs.color;
shapeType = rhs.shapeType;
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

