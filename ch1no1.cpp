/*
Program Name: ch1no1.cpp
Author: J. Dooley
Date: June 25th
Synopsis: A metric ton is 35,273.92 ounces.  
This program reads the weight of package of breakfast cereal in ounces and output the weight in metric tons 
as well as the number  of boxes needed to yeild one metric ton of cereal.
*/

#include <iostream>
using namespace std;

int main()
{

float ouncesInTon = 35273.92;
float ouncesInCereal = 15.3;
float cerealTons = 0;
float howManyBoxesForTon = 0;

cerealTons = ouncesInCereal / ouncesInTon;

cout << "One box of cereal is " << cerealTons << " tons.\n";

howManyBoxesForTon = ouncesInTon / ouncesInCereal;

cout << "The number of boxes needed to yeild one ton of cereal is " << howManyBoxesForTon << " boxes.\n";

return 0;
}
