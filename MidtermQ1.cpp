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
  float SD(float array[ ], int Size = 15);  //default value
The program should call the function to calculate the mean from the function to calculate the standard deviation.
*/

#include <iostream>
#include <cmath>
using namespace std;

void populateOneHundred(float array[], int size);
void populateFibonacci(int array[], int size);
float Avg(float array[ ], int size);  
float Avg(int array[ ], int size);  
float Sum(float array[], int size);
int Sum(int array[], int size);
float SD(int array[ ], int size);   
float SD(float array[ ], int Size = 15);  //default value

int main()
{

float average = 0.0;
float stdDev = 0.0;
float oneHundred[100] = {0.0};
int fibonacci[15] = {0};
int size = 0;

populateOneHundred(&oneHundred[0], 100);
populateFibonacci(&fibonacci[0], 15);

stdDev = SD(&oneHundred[0], 100);
cout << "Standard deviation of the array named oneHundred is " << stdDev << endl;

stdDev = SD(&fibonacci[0], 15);
cout << "Standard deviation of the array named fibonacci is " << stdDev << endl;

return 0;
}

void populateOneHundred(float oneHundred[], int size)
{
  for (int i = 0; i < size; ++i){
    oneHundred[i] = i + 1.0;
    cout << "oneHundred[i] = " << oneHundred[i] << "\n";
  }
}

void populateFibonacci(int fibonacci[], int size)
{
  for (int j = 0; j < size; ++j) {		
    if (j == 0) 
    {	
        fibonacci[j] = 0;
    }		
    else
	{			
            if (j == 1) 
	    {	
                fibonacci[j] = 1;	
            }			
            else 	
	    {			
                fibonacci[j] = fibonacci[j - 2] + fibonacci[j - 1];
		cout << "fibonacci[j] = " << fibonacci[j] << ".\n";		       	            }	
        }	
   }
}

float Average(float array[ ], int size)  
{
  float average = 0.0;
  for (int k = 0; k < size; ++k){
    average += array[k];
   }
  
  average = average / size;
  cout << "average from oneHundred[100] = " << average << ".\n";
return average;
}

int Average(int array[ ], int size)  
{
    int average = 0;  
    for (int l = 0; l < size; ++l){    
      average += array[l];   
    }    
    average = average / size;
cout << "average from fibonacci[15] is " << average << ".\n";
return average;
}

float Sum(float array[ ], int size) 
{  
 float sum = 0.0;  
 for (int m = 0; m < size; ++m){    
 sum += array[m];   }    
 cout << "sum from oneHundred[100] = " << sum << ".\n";  
 return sum;
}

int Sum(int array[ ], int size) 
{   
  int sum = 0.0;   
  for (int n = 0; n < size; ++n){     
    sum += array[n];   }        
  cout << "sum from fibonacci[15] = " << sum << "\n";
return sum;
}
 
float SD(int array[ ], int size)
{
  float variance = 0.0;
  float stdDev = 0.0;
  float sqdValue = 0.0;
  float sumOfSqdValue = 0.0;
  int average = 0;
  average = Average(&array[0], size);
  for (int o = 0; o < size; ++o)
  {
     sqdValue = pow((array[o] - average), 2.0);
     sumOfSqdValue+=sqdValue;
  }
  variance = sumOfSqdValue / size;
  stdDev = sqrt(variance);
  
return stdDev;
}

float SD(float array[ ], int size)
{
  float sqdValue = 0.0;  
  float stdDev = 0.0;  
  float sumOfSqdValue = 0.0;
  float average = 0;    
  float variance = 0.0;
  average = Average(&array[0], size);  
  for (int o = 0; o < size; ++o)
  {
	sqdValue = pow((array[o] - average), 2.0);
	sumOfSqdValue+=sqdValue;  
  }
  variance = sumOfSqdValue / size;
  stdDev = sqrt(variance);
 
return stdDev;
}

