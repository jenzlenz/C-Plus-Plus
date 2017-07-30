#include <iostream>
#include <cstdlib>
using namespace std;
#include <stdlib.h> //for the seed and random number generator

#define R 5 //number of rows = years
#define C 12 //number of columns = months

void Rain_Gen(int* Matrix_ptr[], int row, int col);
//void print_ymMatrix(int* Matrix_ptr[], int size);
void print_Matrix(int* Matrix_ptr[], int row, int col);
//void print_Matrix2(int** Matrix_ptr_ptr, int row, int col);
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
int *YearAcc_ptr = {NULL};
YearAcc_ptr = &YearAcc[0];
calcYearAcc(Matrix_ptr_ptr, R, C);
//print_ymMatrix(YearAcc_ptr, R);

int MonthAcc[C] = {'\0'};
int *MonthAcc_ptr = {NULL};
MonthAcc_ptr = &MonthAcc[0];
//calcMonthAcc(Matrix_ptr_ptr, R, C):
//print_ymMatrix(MonthAcc_ptr, C);

return 0;
}

void Rain_Gen(int* Matrix_ptr[], int row, int col){        
cout << "Inside the Rain gen function" << endl;        
for(int i = 0; i < row; ++i)
{          
  for(int j = 0; j < col; ++j) 
  {           
    *(Matrix_ptr[i]+j) = 65 + (rand() % 30);  //will produce numbers < 100
  }
}
cout << "exiting rain gen function" << endl;
}

void calcYearAcc(int **Matrix_ptr_ptr, int M, int Y){
  cout << "Inside calcYearAcc function" << endl;
  int yearAccum[R] = {0};
  //int *yAccum_ptr[] = {NULL};
  //yAccum_ptr = &yearAccum[0];
    
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
       cout << "yearAccum[" << i << "] = " << yearAccum[i] << " ";
     }
     cout << "\n Exiting calcYearAcc function " << endl;
}

void calcMonthAcc(int **Matrix_ptr_ptr, int M, int Y) {
  cout << "Inside calcMonthAcc function " << endl;
  int mAccum = 0;  
  int monthAccum[C] = {0};
  int *mAccum_ptr[] = {NULL};  
  *mAccum_ptr = &monthAccum[0];      
  
  for (int i = 0; i < M; ++i)    
    for (int j = 0; j < Y; ++j)      
    {
      mAccum += Matrix_ptr_ptr[i][j];  
      monthAccum[i] = mAccum;  
      cout << "monthAccum[i] = " << monthAccum[i] << " ";
    }
  cout << "exiting calcMonthAcc function" << endl;
}
/*
void print_ymMatrix(int* Matrix_ptr[], int size) 
{
 cout << "Inside the print_matrix function using int* matrix_ptr and int size ONLY.\n";
 for (int i = 0; i < size; ++i)
  cout << Matrix_ptr[i];
 //cout << "Printed from print_matrix function" << endl; 
}
*/
void print_Matrix(int* Matrix_ptr[], int row, int col)
{
  cout <<"INside the print matrix function using 3 params: Matrix_ptr, int row, int col.\n";
  for(int i = 0; i < row; ++i)            
  {
    for(int j = 0; j < col; ++j)                
    { 
     cout << *(Matrix_ptr[i]+j) << " ";
    }
  cout << "exiting print_matrix function with 3 params \n";
  }
}
/*
void print_Matrix2(int** Matrix_ptr_ptr, int row, int col){
  for(int i = 0; i < row; ++i)                
    for(int j = 0; j < col; ++j)                      
      cout << **(Matrix_ptr[i]+j) << endl;
}
*/

