#include <iostream>
using namespace std;

struct Grades
{
	int quiz1;
	double quiz1Percent;
	int quiz2;
	double quiz2Percent;
	int midterm;
	double midtermPercent;
	int final;
	double finalPercent;
};

void getScores(Grades& student);
void setPercent(Grades& student);
double calcNumericGrade(Grades& student);
void outputGrade(Grades& student, double total);

int main()
{
 	double total = 0.0;

	Grades student;
	getScores(student);
	setPercent(student);
	total = calcNumericGrade(student);
	outputGrade(student, total);
	
return 0;
}   

void getScores(Grades& student)
{
	cout << "**********Inside the getScores function********* \n";
	cout << "Enter score (0 - 10) for Quiz 1" << endl;
	cin >> student.quiz1;
	cout << "Enter score (0 - 10) for Quiz 2" << endl;
        cin >> student.quiz2;
	cout << "Enter score (0 - 100) for Midterm" << endl;
        cin >> student.midterm;
	cout << "Enter score (0 - 100) for Final" << endl;
        cin >> student.final;

}

void setPercent(Grades& student)
{
	student.quiz1Percent = .125;
	student.quiz2Percent = .125;
	student.midtermPercent = .25;
	student.finalPercent = .5;
}

double calcNumericGrade(Grades& student)
{
	double total = 0;
	total = (10)*(student.quiz1)*(student.quiz1Percent);
	cout << total << endl;
	total = total + (10)*(student.quiz2)*(student.quiz2Percent);
	cout << total << endl;
	total = total + (student.midterm)*(student.midtermPercent);
	cout << total << endl;
	total = total + (student.final)*(student.finalPercent);
	cout << total << endl;
	return total;
}

void outputGrade(Grades& student, double total)
{
	char alphaGrade = ' ';
	
	if (total >= 90) 
		alphaGrade = 'A';
	else if (total >= 80) 
		  alphaGrade = 'B';
	        else if (total >= 70) 
		         alphaGrade = 'C';
		       else if (total >= 65) 
			        alphaGrade = 'D';
			      else
				    alphaGrade = 'F';
				   

	cout << "Student Record" << endl;
	cout << "Grade for Quiz 1: " << student.quiz1 << endl;
	cout << "Grade for Quiz 2: " << student.quiz2 << endl;
	cout << "Grade for Midterm: " << student.midterm << endl;
        cout << "Grade for Final: " << student.final << endl;
	cout << "Numeric grade for student: " << total << endl;
	cout << "Alphanumeric grade for student: " << alphaGrade << endl;	
}

