/* 
Program Name: Final1.cpp
Author: J Dooley
Date: August 1, 2017
Synopsis:
Design and code a polynomial class in C++
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
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

  Poly operator*(const int scale); //scale a poly P2 = P1 * 5
  friend Poly operator*(const int scale, const Poly &rhs); //scale a Poly P2 = P1 *5
  friend Poly operator*(const Poly &lhs, const Poly &rhs); //multiply two polys P3 = P1 * P2

  bool operator==(const Poly &rhs); //equality of two polynomials

  const int & operator[](int i)const; //return the ith coefficient
  int & operator[](int i); //return the ith coefficient

  int operator()(int x); //evaluate P(x)

//member funcions
  void printPoly(); //prints the polynomial
};

int main()
{
  int myarray1[] = {-19, 1, -12, 3, 2};
  int myarray2[] = {-19, 1, -6, 0, 0, 7, 0, 2};
  int result = 0;

  Poly P1; //create a poly p3 using default constructor
  Poly P2(1); //create poly with order zero,  all coeffs 1

  Poly P3(4, myarray1);
  Poly P4(7, myarray2);

  int x = 5;
  result = P3(x);
  cout << "P3(5) = " << result << endl;
  result = P4(x);
  cout << "P4(5) = " << result << endl;

  Poly P5(7); //Poly with order 7, coeffs all set to 1, using one param contructor

//    Poly P6;    //create a default Poly object
//    P6.set();   //query user for coeff values and populate P6 with them  
//  Poly P7;
//  P7=P1+P2;
//  Poly P8;   
//  P8=P1-P2;
  Poly P9;
  P9=P3*P4;
//  P1 = P2*5;
//  P1 = 10*P2;
  
//  P4.printPoly();

  bool arePolyEqual = (P3 == P3);
  cout << "arePolyEqual = " << arePolyEqual << endl;
  arePolyEqual = (P3 == P2);
  cout << "arePolyEqual = " << arePolyEqual << endl;

return 0;
}

Poly::Poly():order(0),coefficient(NULL){
  cout << "default constructor" << endl;
}

Poly::Poly(int Order):order(Order){
  order = Order;
  coefficient = new int[Order+1];
  for(int i = 0; i < (Order + 1); ++i)
     coefficient[i] = 1;
  cout << "Parameterized constructor - only one parameter" << endl;
}

Poly::Poly(int Order, int *Coefficient):order(Order){
  order = Order;
  coefficient = new int[Order+1];
  for(int i = 0; i < (Order + 1); ++i)
     coefficient[i] = Coefficient[i];
  cout << "Parameterized constructor - 2 parameters" << endl;
}
 
Poly::~Poly(){
  delete []coefficient; //deallocate memory on the heap
  cout << "destructor" << endl;
}

int* Poly::get(){
   //return *coefficient; does not compile yet
}

void Poly::set(){
 //query user and store coeffs in vector since we don't know how many user is going to enter
  
        vector<int> UserInput;
        int next = 1;
        do
        {
	cout << "Enter a coefficient to add to the arrays. \n"
             << "Place a -99 to end. \n";
	cin >> next; 
        
        if (next != -99)
        {
            UserInput.push_back(next);
            cout << next << " added" << endl;
            cout << "UserInput.size() = " << UserInput.size() << endl;
        }
        } while (next != -99);
        cout << "User finished entering coefficients. \n" << endl;
  
//now transfer coeffs from vector to object coefficient array
        order = UserInput.size() - 1;
        cout << "order = " << order << endl;
        int value = 0;
        for (int i = 0; i < UserInput.size(); ++i){
            cout << "inside for loop to copy vector to object coefficient" << endl;
              value = UserInput[i];
              coefficient[i] = value;
        }
  cout << "leaving  set function \n";
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
  cout << "Entering the scalar overloaded operator P2 = P1*5" << endl;
  for (int i = 0; i <= order+1; ++i){ 
    coefficient[i] = coefficient[i] * scale;
  }
return *this;
}

Poly operator*(const int scale, const Poly& rhs){
  cout << "Enterng the scalar overloaded operator  P2 = 5 * P1" << endl;
  int size = 0;
  Poly resultPoly;

  size = rhs.order;

  int *newArray = new int[size];

  for(int i = 0; i < (size +1); ++i)
    resultPoly.coefficient[i] = scale * rhs.coefficient[i];

  cout << "check the values in the coefficient array for the resultPoly\n";
  for(int j = 0; j < (size + 1); ++j){
        cout << "coefficient[" << j << "] = " << resultPoly.coefficient[j] << endl;
  }
  return resultPoly;
}

Poly operator*(const Poly &lhs, const Poly &rhs){

    int i = 0;
    Poly resultPoly;
 
    resultPoly.order = max(lhs.order, rhs.order);
//result poly will accomodate the order of the larger Poly

//multiply lhs and rhs and stuff that into result POLY only for as much as both polys have values 
    for (i = 0; i < min(lhs.order, rhs.order)+1; ++i){
    resultPoly.coefficient[i] = lhs.coefficient[i]*rhs.coefficient[i];
    }
//put 0 in the rest of the coeff array to make up for the fewer coeffs in the other array
    for (i = min(lhs.order, rhs.order)+1; i < max(lhs.order, rhs.order); ++i){
    resultPoly.coefficient[i] = 0;
    }

  return resultPoly;
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


const int & operator[](int i)const{
  return *coefficient[i];
}
 
int & operator[](int i){
  return *coefficient[i];
}
  

int Poly::operator()(int x){
  cout << "INside the evaluation of poly operator" << endl;
  int result = 0;
  for(int index = 0; index <= order; index++){
      result += pow ((coefficient[index] * x), index);
  }
  return result;
}

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

