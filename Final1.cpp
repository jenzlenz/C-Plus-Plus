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

//constructors and deconstructor
  Poly();
  Poly(int order);
  Poly(int order, int *coefficient);   
  ~Poly();

//mutators and accessors
  void set(); //queries the user for coefficient values
  void set(int coeff[], int size); //input coeffs via external coeff vector
  int* get(); //returns a pointer to the coeff array
  int getOrder()const;  //gets the order of the polynomial

//overloaded operators
  Poly operator+(const Poly &rhs); //add two polys
  Poly operator-(const Poly &rhs); //subtract two polys
  Poly operator*(const int scale); //scale a poly
  //Poly scale*Poly --not sure what he means here
  Poly operator*(const Poly &rhs); //multiply two polys
  bool operator==(const Poly &rhs); //equality of two polynomials
  //const int & operator[](int i)const; //return the ith coefficient
  //int & operator[](int i); //return the ith coefficient
  //int operator()(int x); //evaluate P(x)

//member funcions
  void printPoly(); //prints the polynomial
};

int main()
{
  int myarray1[] = {-19, 1, -12, 3, 2, 0, 0, 0};
  int myarray2[] = {-19, 1, -6, 0, 0, 7, 0, 2};

//this works  Poly P1; //create a poly p3 using default constructor
//this works  Poly P2(1); //create poly with order zero,  all coeffs 1
//this works  Poly P3(5,myarray1); //create poly with order 5, coeffs per array
  Poly P4(7,myarray2); //create Poly with order 7
//NOT working Poly P4.set();//query user for coeff values and create Poly P4  
//this works  Poly P5 = P3 + P4;   
//this works  Poly P6 = P3 - P4;
//check if works  Poly P7 = P3 * P3;

  P4.printPoly();

/* this all works
  bool arePolyEqual = (P3 == P3);
  cout << "arePolyEqual = " << arePolyEqual << endl;
  arePolyEqual = (P3 == P2);
  cout << "arePolyEqual = " << arePolyEqual << endl;
*/

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

int* Poly::get(){
   //return *coefficient; does not compile yet
}

void Poly::set(){
  //mutator queries the user for coefficient values

  int queryOrder = 0;

  cout << endl << "Enter the order, meaning the highest exponential value, for the polynomial: " << endl;
  cin << queryOrder;

  for (int i = 0; i < coefficient[i]; ++i){
	cout << "Enter coefficient for x^" << i << ":";
	cin << coefficient[i];
  }	
}

void Poly::set(int coeff[], int size){
  	order = size;
	for (int i = 0; i < size; ++i){
	  coefficient[i] = coeff[i];
	}
}
  
int Poly::getOrder()const{
   return order;
} 

Poly Poly::operator+(const Poly &rhs){
  int size = 0;
  Poly resultPoly;

  if(this->order >= rhs.order)
    size = this->order;
  else
    size = rhs.order;

  int *newArray = new int[size];

  for(int i = 0; i < (size +1); ++i)
    coefficient[i] = rhs.coefficient[i] + this->coefficient[i];

  cout << "check the values in the coefficient array for the resultPoly\n";
  for(int j = 0; j < (size + 1); ++j){
	cout << "coefficient[" << j << "] = " << coefficient[j] << endl;
  }
  return resultPoly;
  
}

Poly Poly::operator-(const Poly &rhs){
  int size = 0;
  Poly resultPoly;

  if(this->order >= rhs.order)
    size = this->order;
  else
    size = rhs.order;

  int *newArray = new int[size];

  for(int i = 0; i < (size +1); ++i)
    coefficient[i] = rhs.coefficient[i] - this->coefficient[i];

  cout << "check the values in the coefficient array for the resultPoly\n";
  for(int j = 0; j < (size + 1); ++j){
        cout << "coefficient[" << j << "] = " << coefficient[j] << endl;
  }
  return resultPoly;

} 
 
Poly Poly::operator*(const int scale){

}

bool Poly::operator==(const Poly &rhs){

   if(rhs.order != this->order){
       return false;
   }
   else if(rhs.order == this->order){
      for(int i = 0; i < rhs.order; i++){
         if(rhs.coefficient[i] == this->coefficient[i])
           return true;
         }
   }
   else
   {
    return false;
   }
}

/*
const int & operator[](int i)const{

}
 
int & operator[](int i){

}
  

int operator()(int x){

}
*/

void Poly::printPoly()
{
// i should be what the size of the poly is, size I think = (order+1)
for ( int i = 10; i > 0; i-- )
{       //should not print anything for coeff = 0
	if ( coefficient[i] < 0 ) //takes care of negative coeffs 
	{         
		cout << coefficient[i] << "x^" << i << " ";
	}
	else
        {
		if (coefficient[i] > 0) //take care of positive coeffs
		{
                cout << "+" << coefficient[i] << "x^" << i << " ";
		}
        } 
}
cout << coefficient[0] << endl; //takes care of printing the coeff ONLY for x^0
}

