//Michael Launius
//Calculator.h
//Schneider

#include <string>
#include <sstream>
#include "Result.h"
#ifndef CALCULATOR_H
#define CALCULATOR_H

using namespace std;

class Calculator{
	public:
	Calculator(){}//Default constructor

	Result *resultArray[20];
	stringstream bStr;
	int numberOfResults;
	int index;

	void saveIntToArray(int intResult); //Saves an int to the array
	
	void saveStringToArray(string strResult); //Saves a string to the array

	void outputArray();	

	void calcCmd(string &cmdString);
	
	void analyzeCmd(string cmd, string &operation, double &arg1, double &arg2);
	
	double subtract(double arg1, double arg2){//returns the two numbers subtracted
		return arg1 - arg2;}

	double add(double arg1, double arg2){//returns the two numbers added
		return arg1+arg2;}

	double multiply(double arg1, double arg2){//returns the two numbers multiplied
		return arg1*arg2;}
	
	double divide(double arg1, double arg2){//returns the two numbers divided
		return arg1/arg2;}
		
	void binary(int arg1);
	
	int quit(){exit(0);}
	
};

#endif //END Calculator Class Header