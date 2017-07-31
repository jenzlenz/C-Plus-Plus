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
	P->X = u;
        P->Y = v;
	printf("Inside setData function - after set \n");
}

float getRadius(struct Point *P){
	float radius = 0.0;
	radius = ((P->X)*(P->X) + (P->Y)*(P->Y));
	radius = sqrt(radius);
	printf("Radius = %.4f\n", radius);

return radius;
}

float getDistance(struct Point *P1, struct Point *P2){
 	float distance = 0.0;
	distance = pow((P2->X - P1->X), 2.0) + pow((P2->Y - P1->Y), 2.0);
	distance = sqrt(distance);
	printf("Distance = %.2f\n", distance);

return distance;
}



