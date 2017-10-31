/*
Program Name: quiz1.cpp
Author: J Dooley
Date: October 28, 2017
Synopsis:  Write a program that returns the day of the year (out of 365 or 366) based on a given day, month, year combination.
*/

#include <iostream>
using namespace std;

class DayOfYear
{
private:

int Day;
int Month;
int Year;
bool isLeap;
void validateDate() const;

public:

int calcDayOfYear() const;

//constructors and destructor
DayOfYear(); //default constructor
DayOfYear(int, int, int); //parameterized constructor
~DayOfYear(); //destructor
DayOfYear(const DayOfYear & rhs); //copy constructor

//accessors
int getDay() const;
int getMonth() const;
int getYear() const;

};

int main()
{


DayOfYear any_day;//uses default constructor
DayOfYear leap_day(2,29,2016); //uses paramterized constructor
DayOfYear my_birthday(8,7,1968); //uses parameterized constructor
DayOfYear new_years_eve(12,31,2017); //uses parameterized constructor
DayOfYear my_twins_birthday = my_birthday; //uses copy constructor

DayOfYear invalid_day(8,33,1900);
DayOfYear invalid_month(13,1,1900);
DayOfYear invalid_num_days_in_month(4,31,1900);

cout << endl << "any_day is " << any_day.getMonth() << " " << any_day.getDay() << " " << any_day.getYear() << endl;
cout << "Day of Year for any_day: " << any_day.calcDayOfYear() << endl << endl; 

cout << endl << "leap_day is " << leap_day.getMonth() << " " << leap_day.getDay() << " " << leap_day.getYear() << endl;
cout << "Day of Year for leap_day " << leap_day.calcDayOfYear() << endl << endl;

cout << endl << "my_birthday is " << my_birthday.getMonth() << " " << my_birthday.getDay() << " " << my_birthday.getYear() << endl;
cout << "Day of Year for my_birthday " << my_birthday.calcDayOfYear() << endl << endl;

cout << endl << "new years eve is " << new_years_eve.getMonth() << " " << new_years_eve.getDay() << " " << new_years_eve.getYear() << endl;
cout << "Day of Year for new_years_eve " << new_years_eve.calcDayOfYear() << endl << endl;

cout << endl << "my_twins_birthday is " << my_twins_birthday.getMonth() << " " << my_twins_birthday.getDay() << " " << my_twins_birthday.getYear() << endl;
cout << "Day of Year for my_twins_birthday " << my_twins_birthday.calcDayOfYear() << endl << endl;

return 0;

}

DayOfYear::DayOfYear():Day(1),Month(1),Year(1900){
  cout << endl << "default constructor - sets the date 1/1/1900" << endl;
}

DayOfYear::DayOfYear(int Month, int Day, int Year):Month(Month),Day(Day),Year(Year){
  cout << endl << "Parameterized contructor" << endl;
  validateDate();
  //calcDayOfYear();
}

void DayOfYear::validateDate() const {  

  if (Month < 1 || Month > 12){
     cout << "Month is invalid" << endl;
     //exit(1);
     };
   
  if (Day > 31 || Day < 1){
     cout << "Day is invalid" << endl;
     //exit(1);
     };
  
  if((Month == 4 || Month == 6 || Month == 9 || Month == 11) && (Day > 30)){
        cout << "Month has too many days - should be no more than thirty" << endl;
        //exit(1);
     }
     else if((Month == 2) && (Day > 29)){
           cout << "February never has more than 29 days" << endl;
           //exit(1);
          };           
}

DayOfYear::~DayOfYear(){
  cout << endl << "Destructor" << endl;
}

DayOfYear::DayOfYear(const DayOfYear & rhs){
  cout << "Copy Constructor \n" << endl;
  Day = rhs.Day;
  Month = rhs.Month;
  Year = rhs.Year;
}

int DayOfYear::getMonth() const{
  return Month;
}

int DayOfYear::getDay() const{
  return Day;
}

int DayOfYear::getYear() const{
  return Year;
}

int DayOfYear::calcDayOfYear() const {

  //to make the alogorithm the same for every month, I used 13 array items instead of 12
  int days_In_Month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  
  int doy = 0; //initialize

  for (int i = 0; i < Month; ++i){
          doy = doy + days_In_Month[i];
  }

  doy = doy + getDay();
  
  //leap year adds 1 to the doy but only if its March thru December
  if (Month > 2){
      if ((Year % 4 == 0) && (Year % 100 != 0)){
          doy = doy +1;
      }
      else if (Year % 400 == 0){
              doy = doy + 1;
           }
   }
return doy;
}
