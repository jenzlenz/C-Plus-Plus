/* 
Program Name: ch14no1.cpp
Author: J Dooley
Date: October 18, 2017
Synopsis:
Create base class called Salaried Employee with a derived class, Administrator.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class SalariedEmployee
{  
protected: 
  double Salary;

public:
  SalariedEmployee();			//default constructor
  SalariedEmployee(double Salary);	//parameterized constructor
  ~SalariedEmployee();			//destructor
  double getSalary() const;
  void setSalary(double theNewSalary);
  void printCheck();
};

class Administrator:public SalariedEmployee
{
private:
  string Title;
  string Area;
  string Supervisor;
 
public:
  Administrator();		
  Administrator(double theSalary, string theTitle, string theArea, string theSupervisor);
  ~Administrator(); 		
  void setSupervisor(string theNewSupervisor);
  void inputAdministrator();
  void printAdministrator();
  void printCheck();
};

int main()
{

SalariedEmployee Tom;		//uses default constructor
SalariedEmployee Jim(77.77); 	//uses parameterized constructor
Jim.printCheck();

Administrator Mary;  		//uses default constructor
Administrator Jane(88.88, "Director", "Accounting", "Sue Blatt" );	//uses parameterized constructor
Jane.printCheck();

return 0;
}

SalariedEmployee::SalariedEmployee()
{
  cout << "default Salaried Employee constructor" << endl;
}

SalariedEmployee::SalariedEmployee(double theSalary){
  cout << "Parameterized Salaried Employee  constructor" << endl;
  Salary = theSalary;
}

SalariedEmployee::~SalariedEmployee(){
  cout << "Salaried Employee destructor" << endl;
}

double SalariedEmployee::getSalary()const{
  return Salary;
}

void SalariedEmployee::setSalary(double theNewSalary){
  Salary = theNewSalary;
}

void SalariedEmployee::printCheck(){
  cout << "The salary for the Salaried Employee is: " << Salary << endl;
}

Administrator::Administrator()
{
   cout << "default ADMINISTRATOR constructor" << endl;
}

Administrator::Administrator(double theSalary, string theTitle, string theArea, string theSupervisor)
{
   cout << "paramerized ADMINISTRATOR  constructor" << endl;
   Salary = theSalary;
   Title = theTitle;
   Area = theArea;
   Supervisor = theSupervisor;
}

Administrator::~Administrator()
{
  cout << "ADMINISTRATOR destructor" << endl;
}

void Administrator::setSupervisor(string theNewSupervisor){
  Supervisor = theNewSupervisor;
}

void Administrator::printAdministrator(){
  cout << "The ADMINISTRATORs data is: " << endl << endl;
}

void Administrator::inputAdministrator(){

}

void Administrator::printCheck(){

}

