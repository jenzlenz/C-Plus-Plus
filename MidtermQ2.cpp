#include <iostream>
#include <cstdlib>
using namespace std;
#include <stdlib.h> //for the seed and random number generator

#define R 5 //number of rows
#define C 12 // number of columns

void Rain_Gen(int* Matrix_ptr[], int row, int col);
void print_Matrix(int* Matrix_ptr[]);
void print_Matrix(int* Matrix_ptr[], int row, int col);
void print_Matrix2(int** Matrix_ptr_ptr, int row, int col);
int YearAcc(int** Matrix_ptr_ptr, int M, int Y);
int MonthAcc(int** Matrix_ptr_ptr, int M, int Y);

int main()
{

int YearAcc[R] = {'\0'};
int *YearAcc_ptr = {NULL};
int *YearAcc_ptr = &YearAcc[0];

int MonthAcc[C] = {'\0'};
int *MonthAcc_ptr = {NULL};
int *MonthAcc_ptr = &MonthAcc[0];

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
print_Matrix2(Matrix_ptr_ptr, R, C);
print_Matrix(YearAcc_ptr);
print_Matrix(MonthAcc_ptr;

return 0;
}

void Rain_Gen(int* Matrix_ptr[], int row, int col){        
cout << "Inside the Rain gen function" << endl;        
for(int i = 0; i < row; ++i)          
  for(int j = 0; j < col; ++j)            
    *(Matrix_ptr[i]+j) = 65 + (rand() % 30);  //will produce numbers < 100
}

int YearAcc(int **Matrix_ptr_ptr, int M, int Y){
  int yAccum = 0;
  int YearAccum[R] = {0};
  int yAccum_ptr = &yAccum[0];
    
  for (int i = 0; i < Y; ++i)
    for (j = 0; j < M; +j)
      yAccum += **Matrix_ptr_ptr[i]+j;
  YearAccum[i] = yAccum;
  
return yAccum_ptr;
}

int MonthAcc(int **Matrix_ptr_ptr, int M, int Y) {
  int mAccum = 0;  
  int MonthAccum[C] = {0};  
  int mAccum_ptr = &mAccum[0];      
  
  for (int i = 0; i < M; ++i)    
    for (j = 0; j < Y; +j)      
      mAccum += **Matrix_ptr_ptr[i]+j;  
      MonthAccum[i] = mAccum;  
  
  return mAccum_ptr;
}

void print_Matrix(int* Matrix_ptr[]) {
 for (int i = 0, i < C; ++i)
  cout << Matrix_ptr[i];
 cout << endl; 
}

void print_Matrix(int* Matrix_ptr[], int row, int col){
  for(int i = 0; i < row; ++i)            
    for(int j = 0; j < col; ++j)                
      cout << *(Matrix_ptr[i]+j) << endl;
}

void print_Matrix2(int** Matrix_ptr_ptr, int row, int col){
  for(int i = 0; i < row; ++i)                
    for(int j = 0; j < col; ++j)                      
      cout << **(Matrix_ptr[i]+j) << endl;
}
