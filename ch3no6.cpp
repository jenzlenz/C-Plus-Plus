/*
Program Name: ch3no6.cpp
Author: J Dooley
Date: June 26, 2017
Synopsis: Write a function that computes teh average and standard deviation of four scores.  The standard deviation is defined to be the square root of the average of the four values (s sub i - a) squared, where a is the average of the four scores s1, s2, s3, s4.  The function will have six parameters and will call two other functions.  Embed the function in a program that allows you to test the function again and again until you tell the program you are finished.*/

#include <iostream>
#include <cmath>
using namespace std;

float calcAverage(int, int, int, int);
int calcSum(int, int, int, int);
float calcStd(float, int);

int main ()
{

int score1 = 100;
int score2 = 95;
int score3 = 90;
int score4 = 85;
float average = 0;
int scoresum = 0;
float sdeviation = 0;

scoresum = calcSum(score1, score2, score3, score4);
average = calcAverage(score1, score2, score3, score4);
sdeviation = calcStd(average, scoresum);
 
cout <<"The sum of the scores is " << scoresum << ".\n";
cout <<"The average is " << average << ".\n";
cout <<"The standard deviation is " << sdeviation << ".\n";

return 0;
}

float calcAverage(int score1, int score2, int score3, int score4){
	float average = 0;
	average = (score1 + score2 + score3 + score4)/4;
	return average;
}

int calcSum(int score1, int score2, int score3, int score4){
	int sum = 0;
	sum = (score1 + score2 + score3 + score4);
	return sum;
}

float calcStd(float average, int sum){
	float sdeviation = 0;
	sdeviation = sqrt((sum - average) * (sum - average));
	return sdeviation; 
}
