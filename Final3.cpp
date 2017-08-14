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
  ~Date();                      //destructor
  Date(const Date & rhs);       //copy constructor

//mutators and accessors
  int calcDiff(const Date &Today); //calculate the number of days in between
  int getDay()const;
  int getMonth() const;
  int getYear() const;
  void setDate(int d, int m, int y);

//friend
  friend class Bond;
};

class Bond
{
private:
  char *name;
  float value;
  const Date purchaseDate;
  const Date maturityDate;
  Date Today;
//Bond(); //default constructor - sh/be in public to compile

public:
//constructors and deconstructor
  Bond(); //default constructor
  Bond(char*, int, Date, Date);  //parameterized constructor
  ~Bond();  //destructor
  Bond(const Bond & rhs);  //copy constructor

//mutators and accessors
  void setToday(Date &hoy);
  
//print function

  int calcDaysToMaturity(Date &hoy);
}; 

//overloaded operators


int main()
{

Date Today(4, 18, 2012);
Date Maturity(12, 31, 2025);
Date Purchase(2, 28, 2012);
Date Yesterday;
Yesterday = Purchase;
int yday =0;
yday = Yesterday.getDay();
int ymonth = 0;
ymonth = Yesterday.getMonth();
int yyear = 0;
yyear = Yesterday.getYear();
cout << "Yesterday = " << ymonth << " " << yday << " " << yyear << endl;

//Bond X;  //put the constructor in private section to show this is forbidden
//Bond Y("NYC_Obligation", 885.0, Purchase, Maturity);
//Bond *bond_ptr = new Bond("GW_Bridge_Obligation", 895.0, Purchase, Maturity);
//Bond Z;  //default constructor
//X=Z;  //copy constructor

/*
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
  cout << "date destructor" << endl;
  //date constructor is empty because date is all int which are created on stack
};       
  
Date::Date(const Date & rhs){
  cout << "copy date constructor" << endl;
  day = rhs.day;
  month = rhs.month;
  year = rhs.year;
}; 

int Date::getDay()const{
  return day;
};

int Date::getMonth()const{
  return month;
};

int Date::getYear()const{
  return year;
};

void Date::setDate(int d, int m, int y){
  day = d;
  month = m;
  year = y;
};

int Date::calcDiff(const Date &Today){
  cout << "calculate the number of days between date and today" << endl;
/*
  function gc( y, m, d) {
  m = (m + 9) % 12;
  y = y - m/10;
  return 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + ( d - 1 );
}
Difference between two dates = gc(y2,m2,d2) - gc(y1,m1,d1)
*/

};

Bond::Bond():name(NULL), value(0.0), purchaseDate(0,0,0), maturityDate(0,0,0){
  cout << "default bond constructor" << endl;
};
  
Bond::Bond(char *Name, int Value, Date d1, Date d2):name(Name), value(Value), date(Date::day, Date::month, Date::year),date(Date::day, Date::month, Date::year){
  cout << "parameterized bond constructor" << endl;
}  
  
Bond::~Bond(){
  cout << "bond destructor" << endl;
  delete []name;
//all others created on stack
}; 
  
Bond::Bond(const Bond & rhs):Date(purchaseDate), Date(maturityDate){
  cout << "copy bond constructor" << endl;
  delete []name;   //deallocate from heap my name
  int len = strlen(rhs.name);
  name = new char[len+1];
  strcpy(name, rhs.name);

  value = rhs.value;
  Today = rhs.Today;

  //purchaseDate(rhs.purchaseDate);
  //maturityDate(rhs.maturityDate);

  cout << "Leaving copy bond constructor" << endl;
}; 

void Bond::setToday(Date &hoy){
  cout << "set Todays date" << endl;
  Today.day = hoy.day;
  Today.month = hoy.month;
  Today.year = hoy.year;
};
  
int Bond::calcDaysToMaturity(Date &hoy){
  cout << "calc days to maturity" << endl;
/*
  hoy.month = (hoy.month + 9) % 12;
  hoy.year = hoy.year - m/10;
  return 365*hoy.year + hoy.year/4 - hoy.year/100 + hoy.year/400 + (hoy.month*306 + 5)/10 + ( hoy.day - 1 );
*/
//Difference between two dates = gc(y2,m2,d2) - gc(y1,m1,d1)


};
