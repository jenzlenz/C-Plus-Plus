/*
Program Name: Advf3.cpp
Author: Jennifer Dooley
Date: Dec 19, 2017
Synopsis: 
Write a program to multiply two vector integer matrices.
Output the results onto a third vector matrix.  
Allow the user to input the dimensions of the two matrices.
Evaluate if matrix multiplication is possible on the dimensions entered.
Output an error message if the dimensions are incompatible and can not be multiplied.
*/

#include <iostream>
#include <vector>

using namespace std;

#define R  5
#define C  4

int main()
{
//initialize matrix dimensions
int M1R = 1, M2R = 1, M1C = 1, M2C = 1;

do {
cout << "Please enter the number of rows (must be => 0) for matrix 1." << endl;
cin >> M1R;
cout << "Please enter the number of columns (must be => 0) for matrix 1." << endl;
cin >> M1C;
cout << "Please enter the number of rows (must be => 0) for matrix 2." << endl;
cin >> M2R;
cout << "Please enter the number of columns (must be => 0) for matrix 2." << endl;
cin >> M2C;
if ((M1R != M2C) || (M1R < 0) || (M1C < 0) || (M2R < 0) || (M2C < 0))
	cout << "Number of rows in Matrix 1 must equal number of columns in Matrix 2 to perform matrix multiplication." << endl;
	cout << "All dimensions MUST be 0 or greater. " << endl;
	cout << "You will need to enter your dimensions again. " << endl;
} while (M1R != M2C);
   
vector< vector<int> > Matrix1(M1R, vector<int>(M1C,0)); // Declare size of 5X4 array
vector< vector<int> > Matrix2(M2R, vector<int>(M2C,0)); // Declare size of 4X5 array 
vector< vector<int> > productV(M1R, vector<int>(M2C,0));//create 5X5 Product Vector
   
vector<int> Row;	// Declare Row Vector
   
vector<int>::iterator Row_Ptr; // Declare Iterators
vector< vector<int> >::iterator Col_Ptr; // Declare Iterators


int SumProd = 0;

//Populate Matrix1
for(int j = 0; j < M1R; ++j)
    for(int i = 0; i < M1C; ++i) {
        Matrix1[j][i] = j;
    }
        
//Populate Matrix2
for(int i = 0; i < M2R; ++i)
    for(int j = 0; j < M2C; ++j)
        Matrix2[i][j] = j;

//Print Matrix 1
cout << " --- Matrix 1---" << endl;
for(int i=0; i < M1R; i++)
   {
    for(int j=0; j < M1C; j++)
        cout << Matrix1[i][j] << "\t";
    cout << endl;
   }

//Print Matrix 2
cout << " --- Matrix 2---" << endl;
for(int i=0; i < M2R; i++)
   {
    for(int j=0; j < M2C; j++)
        cout << Matrix2[i][j] << "\t";
    cout << endl;
   }

//Calculate Sum of Products
for(int i = 0; i < M1R; ++i) 
{
        for(int j = 0; j < M2C; ++j) 
        {
            for(int k = 0; k < M1C; ++k)
            {
                productV[i][j] += Matrix1[i][k] * Matrix2[k][j];

            }
        }
        
}

//Print Output Vector Results
cout << " --- Product Vector Matrix ---" << endl;
for(int i=0; i < M1R; i++)
   {
    for(int j=0; j < M2C; j++)
        cout << productV[i][j] << "\t";
    cout << endl;
   }

return 0;
}
