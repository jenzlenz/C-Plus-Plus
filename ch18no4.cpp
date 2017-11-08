/*
Author: Jennifer Dooley
Date: November 7, 2017
Program Name: ch18no4.cpp
Synopsis: Demonstrate the use of a try throw catch block.
*/

#include <iostream>
using namespace std;
using std::cin;
using std::cout;

int getProductID(int ids[], string names [], int numProducts, string target);

int main()
{
  
int productIDs[] = {4, 5, 8, 10, 13};
string products[] = {"computer", "flash drive", "mouse", "printer", "camera"};

cout << getProductID(productIDs, products, 5, "mouse") << endl;  
cout << getProductID(productIDs, products, 5, "camera") << endl;
cout << getProductID(productIDs, products, 5, "computer") << endl;
cout << getProductID(productIDs, products, 5, "printer") << endl;
cout << getProductID(productIDs, products, 5, "flash drive") << endl;
cout << getProductID(productIDs, products, 5, "lap top") << endl;

return 0;
}

int getProductID(int ids[], string names [], int numProducts, string target)
{
    try{
     for (int i = 0; i < numProducts; ++i)
     {
        if (names[i] == target)
          return ids[i];
     }
    throw (target);
    }

    catch(string e)
        {
         cout << "Could not find this target: " << e << endl;
        }
}

 
