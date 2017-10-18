/* 
Program Name: ch14no6.cpp
Author: J Dooley
Date: October 17, 2017
Synopsis:
Create base class called Payment with two derived classes, CashPayment and CreditCardPayment.  Illustrate the redefinition of a function named paymentDetails for each of these classes.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Payment
{  
protected: 
  float Amount;

public:
  Payment();			//default constructor
  Payment(float theAmount);	//parameterized constructor
  ~Payment();			//destructor
  float getAmount() const;
  void paymentDetails();
};

class CashPayment:public Payment
{
public:
  CashPayment();		//default constructor
  CashPayment(float theCashAmt);   //parameterized constructor
  ~CashPayment(); 		//destructor
  void paymentDetails();
};

class CreditCardPayment:public Payment
{
private:
  string Name;
  int expDate;
  long int ccNum;
public:
  CreditCardPayment(); 	//default constructor
  CreditCardPayment(float theCCAmt, string theName, int theExpDate, long int theCCNum); //parameterized constructor
  ~CreditCardPayment();		//destructor
  void paymentDetails();
};

int main()
{

Payment P1; 			//uses default constructor
Payment P2(77.77); 		//uses parameterized constructor
P2.paymentDetails();

CashPayment CP1;  		//uses default constructor
CashPayment CP2(88.88);		//uses parameterized constructor
CP2.paymentDetails();

CreditCardPayment CCP1; 	//uses default constructor
CreditCardPayment CCP2(99.99, "James Jones", 11182017, 1234567890901234);	//uses parameterized constructor
CCP2.paymentDetails();

return 0;
}

Payment::Payment()
{
  cout << "default Payment constructor" << endl;
}

Payment::Payment(float theAmount){
  cout << "Parameterized Payment constructor" << endl;
  Amount = theAmount;
}

Payment::~Payment(){
  cout << "Payment destructor" << endl;
}

float Payment::getAmount()const{
  return Amount;
}

void Payment::paymentDetails(){
   cout << "Payment Amount is: " << Amount << endl << endl;
};

CashPayment::CashPayment()
{
   cout << "default CASH payment constructor" << endl;
}

CashPayment::CashPayment(float theCashAmount)
{
   cout << "paramerized CASH payment constructor" << endl;
   Amount = theCashAmount;
}

CashPayment::~CashPayment()
{
  cout << "CASH Payment destructor" << endl;
}

void CashPayment::paymentDetails(){
  cout << "The CASH payment amount is: " << Amount << endl << endl;
}

CreditCardPayment::CreditCardPayment()
{
  cout << "default credit card payment constructor" << endl;
}

CreditCardPayment::CreditCardPayment(float theCCAmt, string theName, int theExpDate, long int theCCNum)
{
  cout << "parameterized CREDIT CARD PAYMENT constructor" << endl;
  Amount = theCCAmt;
  Name = theName;
  expDate  = theExpDate;
  ccNum  = theCCNum;
}

CreditCardPayment::~CreditCardPayment()
{
  cout << "CREDIT CARD Payment destructor" << endl;
}

void CreditCardPayment::paymentDetails(){
  cout << "The CREDIT CARD payment amount is: " << Amount << endl;
  cout << "The name on the credit card is: " << Name << endl;
  cout << "The Expiration Date is: " << expDate << endl;
  cout << "The Credit Card Number is: " << ccNum << endl << endl;
}
