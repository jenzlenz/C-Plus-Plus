#include <iostream>
#include <cstdlib>
using namespace std;
#include <stdlib.h> //for the seed and random number generator

#define R 5 //number of rows = years
#define C 12 //number of columns = months

void Rain_Gen(int* Matrix_ptr[], int row, int col);
void print_Matrix(int* Matrix_ptr[], int row, int col);
void calcYearAcc(int** Matrix_ptr_ptr, int M, int Y);
void calcMonthAcc(int** Matrix_ptr_ptr, int M, int Y);

int main()
{

int Matrix[R][C] = {'\0'};        
int *Matrix_ptr[R] = {NULL};
int **Matrix_ptr_ptr = NULL; //int ptr to the array of int ptrs        
Matrix_ptr_ptr = &Matrix_ptr[0];
        
unsigned long int seed = 1023;        
srand(seed); //initializes the random number generator
        
//assign pointers to rows        
for(int i = 0; i < R; ++i)                
  Matrix_ptr[i] = &Matrix[i][0]; //zeroth column
        
//populate matrix via array of pointers        
Rain_Gen(Matrix_ptr, R, C); //passing a ptr to an array of ptrs
print_Matrix(Matrix_ptr, R, C);

int YearAcc[R] = {'\0'};
calcYearAcc(Matrix_ptr_ptr, R, C);

int MonthAcc[C] = {'\0'};
calcMonthAcc(Matrix_ptr_ptr, R, C);

return 0;
}

void Rain_Gen(int* Matrix_ptr[], int row, int col)
{                
  for(int i = 0; i < row; ++i)
  {          
    for(int j = 0; j < col; ++j) 
    {           
      *(Matrix_ptr[i]+j) = 65 + (rand() % 30);  //will produce numbers < 100
    }
  }
}

void calcYearAcc(int **Matrix_ptr_ptr, int M, int Y)
{  
  int yearAccum[R] = {0};    
  
     for (int i = 0; i < 5; ++i)
     {  
       int yAccum = 0;
       for (int j = 0; j < 12; ++j)
       {
          yAccum += Matrix_ptr_ptr[i][j];
       }
     yearAccum[i] = yAccum;
     }
    
     for (int i = 0; i < 5; ++i)
     {
       cout << "yearAccum[" << i << "] = " << yearAccum[i] << endl;
     }
     cout << endl;
}

void calcMonthAcc(int **Matrix_ptr_ptr, int M, int Y) 
{  
  int monthAccum[C] = {0};
  
     for (int j = 0; j < 12; ++j)
     {  
       int mAccum = 0;
       for (int i = 0; i < 5; ++i)
       {
          mAccum += Matrix_ptr_ptr[i][j];
       }
     monthAccum[j] = mAccum;
     }
    
     for (int i = 0; i < 12; ++i)
     {
       cout << "monthAccum[" << i << "] = " << monthAccum[i] << endl;
     }
     cout << endl;
}

void print_Matrix(int* Matrix_ptr[], int row, int col)
{
  cout << endl;
  for(int i = 0; i < row; ++i)            
  {
    for(int j = 0; j < col; ++j)                
    { 
     cout << *(Matrix_ptr[i]+j) << " ";
    }
  cout << endl;
  }
  cout << endl;
}

