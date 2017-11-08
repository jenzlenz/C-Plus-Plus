/*
Author: Jennifer Dooley
Date: November 7, 2017
Program Name: ch18no5.cpp
Synopsis: Demonstrate the use of a try throw catch block.
*/

#include <iostream>
using namespace std;

class negativeAmount{};
class withdrawlAmountTooHigh{};

class Account
{
private: 
    double balance;

public:
    Account();
    Account(double initialDeposit);
    double getBalance();
    double deposit(double amount);
    double withdraw(double amount); 
};

int main()
{

Account rich(1000.00);
Account poor;
Account middleClass(500.00);

cout << rich.getBalance() << endl;
cout << rich.withdraw(5000.00) << endl;//withdraw more than available balance

cout << middleClass.getBalance() << endl;
cout << middleClass.withdraw(-100.00) << endl;//withdrawl amount should never be negative

cout << poor.getBalance() << endl;
cout << poor.deposit(-500.00) << endl; //deposit amount hould never be negative

return 0;
}

Account::Account(){
 balance = 0;
}

Account::Account(double initialDeposit){
 balance = initialDeposit;
}

double Account::getBalance(){
 return balance;
}

double Account::deposit(double amount){
 try{
     if (amount > 0)
        balance += amount;
     else
        //return -1;
        throw(amount);
 }
 catch(double amount)
 {
  cout << "Amount to deposit can not be less than zero.  Attempted deposit Amount was: " << amount << endl;
 }
 return balance;
}

double Account::withdraw(double amount){
 //if ((amount > balance) || (amount < 0))
 try{
     if (amount > balance)  
        //return -1;
        throw withdrawlAmountTooHigh();
     else if (amount < 0)
              //return -1;
              throw negativeAmount();
          else
             balance -= amount;
    }
 catch(withdrawlAmountTooHigh){
       cout << "You attempted to withdraw too much. Attempted withdrawl amount was " << amount << " and your balance is only: " << balance << endl;
 }
 catch(negativeAmount){
       cout << "You can not withdraw a negative amount of money. Attempted withdrawl amount was :" << amount << endl;
}
 return balance;
}
