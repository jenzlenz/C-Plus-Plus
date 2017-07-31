/********************************************************************************
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
**********************************************************************************/

#include <stdio.h>
#include <math.h>

struct Point{
  int X;
  int Y;
  float Radius;
};

//prototype functions
void setData(struct Point *P, int u, int v);
float getRadius(struct Point *P);
float getDistance(struct Point *P1, struct Point *P2);
	
int main()
{
	/*declare structures*/
	struct Point A, *P1;
	struct Point B, *P2;

	P1 = &A;
	P2 = &B;

	float radius = 0;

	setData(P1, 3, 4);
	setData(P2, 10, 15);

	getRadius(P1);
	getRadius(P2);

	getDistance(&A, &B);		

    return 0;
}

//function definitions

void setData(struct Point *P, int u, int v){
        struct Point Z;
	Z.X = u;
        Z.Y = v;
}

float getRadius(struct Point *P){
	struct Point *W;
	float radius = 0.0;
	radius = sqrt((W->X)*(W->X) + (W->Y)*(W->Y));
	printf("Radius = %.4f", radius);

return radius;
}

float getDistance(struct Point *P1, struct Point *P2){
 	float distance = 0;
	struct Point S, T;

	printf("Distance = %.2f", distance);

return distance;
}

