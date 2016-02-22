//Michael Launius
//Calculator.h
//Schneider

#include <string>
#ifndef CALCULATOR_H
#define CALCULATOR_H

using namespace std;

class Calculator{
	public:
	Calculator(){}//Default constructor
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