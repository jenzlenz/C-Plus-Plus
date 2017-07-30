/*
Program Name: Point.c
Author: J Dooley
Date: July 30, 2017
Synopsis:
Write a program that declares this structure

struct Point
{
int X;  //x coord
int Y;  // y coord 
float Radius;  //Radius = sqrt((X*X) + (Y*Y))
}

program must contain the following accessor functions:
void setData(struct Point*, int u, int v);
float getRadius(struct Point*)const;
float getDistance(struct Point *P1, struct Point *P2)

The program should create a Point P1 at(X=3, Y=4) and Point P2 at (X=10, Y=15).
The program should output the distance between P1 and P2.
