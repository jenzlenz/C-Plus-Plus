/* 
Program Name: Final1.cpp
Author: J Dooley
Date: August 1, 2017
Synopsis:
Design and code a polynomial class in C++
*/

#include <iostream>
#include <cstring>
using namespace std;

class Poly
{
private:
  int order;
  int *coefficient;

public:
  Poly();
  Poly(int order);
  Poly(int order, int *coefficient);   
  ~Poly();
};

int main()
{
  int myarray1[] = {2, 3, -12, 1, -19};
  int myarray2[] = {2, 0, 7, 0, 0, -6, 1 -19};

  Poly P3; //create a poly p3 using default constructor
  Poly P1(1); //create poly with order zero,  all coeffs 1
  Poly P2(1,myarray1); 

return 0;
}

Poly::Poly():order(0),coefficient(NULL){
  cout << "default constructor" << endl;
}

Poly::Poly(int Order):order(Order){
  coefficient = new int[Order+1];
  for(int i = 0; i < (Order + 1); ++i)
     coefficient[i] = 1;
  order = Order;
  cout << "Parameterized constructor - only one parameter" << endl;
}

Poly::Poly(int Order, int *Coefficient):order(Order){
  coefficient = new int[Order+1];
  for(int i = 0; i < (Order + 1); ++i)
     coefficient[i] = Coefficient[i];
  order = Order;
  cout << "Parameterized constructor - 2 parameters" << endl;
}
 
Poly::~Poly(){
  delete []coefficient; //deallocate memory on the heap
  cout << "deconstructor" << endl;
}
