/*
Program Name: ch6no3.cpp
Author: J Dooley
Date: July 25, 2017
Synopsis:

Write a definition of a class Point that might be used to store and manipulate the location of  a point on a plane.

Declare a member function that sets the private data after an object of this class is created.

Declare a member function to move the point by an amount along the vertical and horizontal directions specified by the first and second arguments.

Declare a member function to rotate the point by 90 degrees clockwise around the origin.

Declare two const inspector functions to retrieve the current coordinates of the point.

Document those functions with appropriate comments.

Embed your class in a test program that requests data for several points from the user, creates points, then exercises the member functions.

*/

#include <iostream>
using namespace std;

class Point
{
public:
	void setPoint(double x, double y);
	void movePoint(double x, double y);
	void rotatePoint90();
        const double getCurrentxAxis();
	const double getCurrentyAxis();
private:
	double xAxis;
	double yAxis;
};

int main()
{
	Point  pointA, pointB, pointC;
	double coord1 = 0.0; 
	double coord2 = 0.0;

	cout << "Please enter first coordinate.\n ";
	cin >> coord1;

	cout << "Please enter second coordinate.\n ";
        cin >> coord2;

	pointA.setPoint(coord1, coord2);
	
	cout << "Please enter first coordinate.\n ";
        cin >> coord1;

        cout << "Please enter second coordinate.\n ";
        cin >> coord2;

        pointB.setPoint(coord1, coord2);

	cout << "Please enter first coordinate.\n ";
        cin >> coord1;

        cout << "Please enter second coordinate.\n ";
        cin >> coord2;

        pointC.setPoint(coord1, coord2);

///////////////////////////////////////////////////////////////

	pointA.movePoint(5, 5);
	pointB.movePoint(10, 10);
	pointC.movePoint(8, 8);

///////////////////////////////////////////////////////////////

	pointA.rotatePoint90();
	pointB.rotatePoint90();
	pointC.rotatePoint90();

//////////////////////////////////////////////////////////////

	//put the value gotten for the two const get functions into coord1 and coord2 then print to prove the get worked correctly
        coord1 = pointA.getCurrentxAxis();
        coord2 = pointA.getCurrentyAxis();
        cout << "Get Current xAxis and yAxis of Point A returns " << coord1 << " and " << coord2 << ".\n";

	coord1 = pointB.getCurrentxAxis();
        coord2 = pointB.getCurrentyAxis();
	cout << "Get Current xAxis and yAxis of Point B returns " << coord1 << " and " << coord2 << ".\n";

	coord1 = pointC.getCurrentxAxis();
        coord2 = pointC.getCurrentyAxis();
	cout << "Get Current xAxis and yAxis of Point C returns " << coord1 << " and " << coord2 << ".\n";


//////////////////////////////////////////////////////////////
}

void Point::setPoint(double x, double y)
{
	xAxis = x;
	yAxis = y;
	cout << "Point is set to " << xAxis << " " << yAxis << ".\n";
}

void Point::movePoint(double x, double y)
{
	xAxis = xAxis + x;
	yAxis = yAxis + y;
	cout << "Point is moved to " << xAxis << " " << yAxis << ".\n";
}

void Point::rotatePoint90()
{
	// 90 degree rotation of (x, y) should return (y, -x)
	int temp = 0;
	temp = xAxis;
	xAxis = yAxis;
	yAxis = -temp;	

	cout << "Point is rotated 90 degrees to " << xAxis << " " << yAxis << ".\n";
}

const double Point::getCurrentxAxis()
{
	return xAxis;
}

const double Point::getCurrentyAxis()
{
        return yAxis;
}
