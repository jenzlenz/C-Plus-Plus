/*
Program Name: MidTermQ1.cpp
Author: J Dooley
Date: July 28, 2017
Synopsis:
Write a program to do the following:
populate the following arrays:
  float Array[100] = {1.0, 2.0, 3.0, 4.0,....100.0}
  int Fib[15] = {0, 1, 1, 2, 3, 5, 8,....610}

calculate the mean and standard deviation for both arrays while utilizing overloaded functions defined as follows:
  float Mean(float array[ ], int Size);
  float Mean(int array[ ], int Size);
  float SD(int array[ ], int Size); 
  float SD(float array[ ], int Size = 15);  //default value

The program should call the function to calculate the mean from the function to calculate the standard deviation.
*/

#include <iostream>
#include <cmath>
using namespace <std>;

void populateOneHundred(float array[], int size);
void populateFibonacci(int array[], int size);
float Avg(float array[ ], int size);  
float Avg(int array[ ], int size);  
float Sum(float array[], int size);
int Sum(int array[], int size);
float SD(int array[ ], int size);   
float SD(float array[ ], int Size = 15);  //default value

int main()
{

float average = 0.0;
Float stdDev = 0.0;
float oneHundred[100] = {0.0};
int fibonacci[15] = {0};
int size = 0;

populateOneHundred(&oneHundred[0], 100);
populateFibonacci(&Fibonacci[0], 15);

stdDev = SD(&oneHundred[0], 100);
cout << "Standard deviation of the array named oneHundred is " << stdDev << endl;

stdDev = SD(&fibonacci[0], 15);
cout << "Standard deviation of the array named fibonacci is " << stdDev << endl;

return 0;
}

void populateOneHundred(float array[], int size)
{
  for (int i = 0, i < size, ++i){
    *oneHundred[i] = float (i + 1);
    cout << "oneHundred[i] = " << oneHumdred[i];
  }
  endl;
}

void populateFibonacci(int array[], int size);
{
  for (int i = 0; i < size; ++i) {		
    if (i == 0) {	
        fib[i] = 0;		}		
    else	{			
            if (i == 1) {	
                fib[i] = 1;	}			
            else 	{				
                      fib[i] = fib[i - 2] + fib[i - 1];			}	
    }	
  }
}

float Average(float array[ ], int Size);  
{
  float average = 0.0;
  for (int i = 0, i < size; ++i){
    average += array[i];
   }
  
  average = average / size;
  
return average;
}

int Average(int array[ ], int Size);  
{
    int average = 0;  
    for (int i = 0, i < size; ++i){    
      average += array[i];   
    }    
    average = average / size;

return average;
}

float Sum(float array[ ], int size); 
{  
 float sum = 0.0;  
 for (int i = 0, i < size; ++i){    
 sum += array[i];   }    
   
 return sum;
}

int Sum(float array[ ], int size); 
{   
  int sum = 0.0;   
  for (int i = 0, i < size; ++i){     
    sum += array[i];   }        

return sum;
}
 
float SD(int array[ ], int Size);   
{
  float variance = 0.0;
  stdDev = 0.0;
  int sum = 0;
  int average = 0;
  
  average = Average(&array[0], size);
  sum = Sum(&array[0], size);
  variance = (1.0/4) * sum;
  stdDev = sqrt(variance);
  
return stdDev;
}

float SD(float array[ ], int Size = 15)
{
  float variance = 0.0;  
  stdDev = 0.0;  
  float sum = 0;  
  float average = 0;    
  average = Average(&array[0], size);  
  sum = Sum(&array[0], size);  
  variance = (1.0/4) * sum;  
  stdDev = sqrt(variance);

return stdDev;
}
