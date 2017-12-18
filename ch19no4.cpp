/*
Author: Jennifer Dooley
Program Name: ch19no4.cpp
Date: December 17, 2017
Synopsis:  
Create a StudentInfo vector object, 
prompt for and build a vector of Student Info
sort the data by name
calculate max and min grades, the class average
the print out this summarizing data along with the class roll and grades
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
#define SIZE 3

struct StudentInfo {
	string name;
	int grade;
};

bool sortByName(const StudentInfo &lhs, const StudentInfo &rhs) { return lhs.name < rhs.name; }

int main()
{
vector<StudentInfo> StudentGrades(SIZE);
vector<StudentInfo>::iterator iter;

//prompt for and build a vector of Student data
for (int i = 0; i < SIZE; i++){
	cout << "Please enter student name:\n";
	std::cin >> StudentGrades.at(i).name;
	cout << "Please enter student grade:\n";
	std::cin >> StudentGrades.at(i).grade;
}

//sort the data by name
sort (StudentGrades.begin(), StudentGrades.end(), sortByName);
    for (StudentInfo &s : StudentGrades)
        cout << s.name << " ";

//print the data after sorting by name
//declare variable to calculate class average
double sumOfGrades = 0;
double classAverage = 0;
int maxGrade = 0;
int minGrade = 100;
cout << "After sorting by name, Vector contains:\n";
for(iter = StudentGrades.begin(); iter != StudentGrades.end(); iter++) {
	cout << (*iter).name << " ";
	cout << (*iter).grade;
	if ((*iter).grade > maxGrade)
	   maxGrade = (*iter).grade;
	if ((*iter).grade < minGrade)
	   minGrade = (*iter).grade;
	//calculate sum of grades for all students
	double sumOfGrades = sumOfGrades + (*iter).grade;
	classAverage = (sumOfGrades/SIZE);
	cout << endl;
};

cout << "The maximum grade is : " << maxGrade << endl;
cout << "The minimum grade is : " << minGrade << endl;
cout << "The class average grade is : " << classAverage << endl;

return 0;
}
