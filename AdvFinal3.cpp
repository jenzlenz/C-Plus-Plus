#include <iostream>
#include <vector>

using namespace std;

#define R  5
#define C  4

int main()
{
   
vector< vector<int> > Matrix1(R, vector<int>(C,0)); // Declare size of 5X4 array
vector< vector<int> > Matrix2(C, vector<int>(R,0)); // Declare size of 4X5 array 
vector< vector<int> > productV(R, vector<int>(R,0));//create 5X5 Product Vector
   
vector<int> Row;	// Declare Row Vector
   
vector<int>::iterator Row_Ptr; // Declare Iterators
vector< vector<int> >::iterator Col_Ptr; // Declare Iterators


int SumProd = 0;

//Populate Matrix1
for(int j = 0; j < R; ++j)
    for(int i = 0; i < C; ++i) {
        Matrix1[j][i] = j;
    }
        
//Populate Matrix2
for(int i = 0; i < C; ++i)
    for(int j = 0; j < R; ++j)
        Matrix2[i][j] = j;

//Print Matrix 1
cout << " --- Matrix 1---" << endl;
for(int i=0; i < R; i++)
   {
    for(int j=0; j < C; j++)
        cout << Matrix1[i][j] << "\t";
    cout << endl;
   }

//Print Matrix 2
cout << " --- Matrix 2---" << endl;
for(int i=0; i < C; i++)
   {
    for(int j=0; j < R; j++)
        cout << Matrix2[i][j] << "\t";
    cout << endl;
   }

//Calculate Sum of Products
for(int i = 0; i < R; ++i) 
{
        for(int j = 0; j < R; ++j) 
        {
            for(int k = 0; k < C; ++k)
            {
                productV[i][j] += Matrix1[i][k] * Matrix2[k][j];
                //cout << "productV = " << productV[i][j] << endl;
    			//productV.push_back(SumProd);
            }
        }
        
}

//Print Output Vector Results
cout << " --- Product Matrix ---" << endl;
for(int i=0; i < R; i++)
   {
    for(int j=0; j < R; j++)
        cout << productV[i][j] << "\t";
    cout << endl;
   }

return 0;
}
