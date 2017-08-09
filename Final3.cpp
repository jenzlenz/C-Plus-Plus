/*
Author: J Dooley
Date: August 7, 2017
Synopsis:
Design and code a Bond and Date class in C++
*/

#include <iostream>
#include <cstring>
using namespace std;

class Date
{
private:
  int day, month, year;
  static int daysMonth[12];
  static int monthsYear;

public:

//constructors and deconstructor
  Date();                       //default constructor
  Date(int, int, int);          //parameterized constructor
  ~Date();                      //deconstructor
  Date(const Date & rhs);       //copy constructor

//mutators and accessors
  int calcDiff(const Date &Today); //calculate the number of days in between
};

class Bond
{

private:
  char *name;
  float value;
  const Date purchaseDate;
  const Date maturityDate;
  Date Today;

public:
//constructrs and deconstructor
  Bond(); //default constructor
  Bond(char*, int, Date, Date);  //parameterized constructor
  ~Bond();  //deconstructor
  Bond(const Bond & rhs);  //copy constructor

//mutators and accessors
  void setToday(Date &hoy);
  //print function
  int calcDaysToMaturity(Date &hoy);
}; 

//overloaded operators


int main()
{

/*
Date Today(4, 18, 2012);
Date Maturity(12, 31, 2025);
Date Purchase(2, 28, 2012);
Bond X;  //put the constructor in private section to show this is forbidden
Bond Y("NYC_Obligation", 885.0, Purchase, Maturity);
Bond *bond_ptr = new Bond("GW_Bridge_Obligation", 895.0, Purchase, Maturity);
int days = Y.calcDaysToMaturity(Today);
*/

return 0;
}

Date::Date():day(1), month(1), year(1){
  cout << "default date constructor" << endl;
}; 
  
Date::Date(int Day, int Month, int Year):day(Day), month(Month), year(Year){
  cout << "parameterized date constructor" << endl;
}; 
  
Date::~Date(){
  cout << "date deconstructor" << endl;
};       
  
Date::Date(const Date & rhs){
  cout << "copy date constructor" << endl;
}; 

int Date::calcDiff(const Date &Today){
  cout << "calculate the number of days between date and today" << endl;
};

Bond::Bond():name(NULL), value(0.0), purchaseDate(0,0,0), maturityDate(0,0,0){
  cout << "default bond constructor" << endl;
};
  
Bond::Bond(char *Name, int Value, Date d1, Date d2):name(Name), value(Value), purchaseDate(0,0,0), maturityDate(0,0,0){
  cout << "parameterized bond constructor" << endl;
}  
  
Bond::~Bond(){
  cout << "bond deconstructor" << endl;
}; 
  
Bond::Bond(const Bond & rhs){
  cout << "copy bond constructor" << endl;
}; 

void Bond::setToday(Date &hoy){
  cout << "set Todays date" << endl;
};
  
int Bond::calcDaysToMaturity(Date &hoy){
  cout << "calc days to maturity" << endl;
};
