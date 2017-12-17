/*
Author: Jennifer Dooley
Program Name: HW9.cpp
Date: December 17, 2017
Synopsis:  
Create an integer list object, 
insert the elements -3 through 29
using an iterator print out all nodes
remove elements divisible by 3
using an iterator print out all nodes
*/

#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

int main()
{
list<int> listObject;

for (int i = -3; i <=29; i++)
	listObject.push_back(i);

cout << "List contains:\n";
list<int>::iterator iter;
for(iter = listObject.begin(); iter != listObject.end(); iter++)
	cout << *iter << " ";
cout << endl;

cout << "Removing all entries divisible by 3:\n";
for (iter = listObject.begin(); iter != listObject.end(); iter++) {
	if (*iter % 3 == 0){
		listObject.erase(iter);
	}
}
	
cout << "List now contains:\n";	
for(iter = listObject.begin(); iter != listObject.end(); iter++)
	cout << *iter << " ";
cout << endl;

return 0;
}
