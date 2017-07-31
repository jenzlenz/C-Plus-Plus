#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
public:
	void setData(int u, int v);
	float getRadius()const;
	float getDistance(const Point &P);
private:
	int X;
	int Y;
	float Radius;
};

int main()
{
 	Point A, B, *A_ptr, *B_ptr;
	A_ptr = &A;
	B_ptr = &B;

	A.setData(15, 15);
	B.setData(20, 20);

	A.getRadius();
	B.getRadius();

	A.getDistance(*A_ptr); 
	B.getDistance(*B_ptr);	

return 0;
}   

void Point::setData(int u, int v)
{
	cout << "**********Inside the setData function********* \n";
	struct Point Z;

	Z.X = u;
	Z.Y = v;
	
	cout << "Point Data has been set " << endl;

}

float Point::getRadius()const
{
	cout << "****************Inside the getRadius function*********** \n";
	float radius = 0.0;
	struct Point W;
	radius = sqrt(((W.X) * (W.X)) + ((W.Y) * (W.Y)));
	cout << "Radius = " << radius << endl;
	return (radius);
}

float Point::getDistance(const Point &P)
{
	cout << "****************Inside the getDistance function************ \n";
	float distance = 0.0;
	struct Point T;
	cout << "Distance = " << distance << endl;
return (distance);
}
