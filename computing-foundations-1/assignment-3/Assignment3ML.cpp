//Programming Assignment #2
//Michael Launius
// Professor: Schneider

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Calculator.h"
using namespace std;

int main(){
	Calculator *calc = new Calculator;
	string cmdString, operation;
	double arg1, arg2;
	double answer;
	while(operation[0] != 'q')
	{
	calc->calcCmd(cmdString);
	calc->analyzeCmd(cmdString, operation, arg1, arg2);
	
	if(operation[0] == 's' || operation[0] == 'S'){
	answer = calc->subtract(arg1, arg2); cout << answer << endl;}
	else if(operation[0] == 'a' || operation[0] == 'A'){
	answer = calc->add(arg1, arg2); cout << answer << endl;}
	else if(operation[0] == 'm' || operation[0] == 'M'){
	answer = calc->multiply(arg1, arg2); cout << answer << endl;}
	else if(operation[0] == 'd' || operation[0] == 'D'){
	answer = calc->divide(arg1, arg2);cout << answer << endl;}
	else if(operation[0] == 'b' || operation[0] == 'B'){
	calc->binary(arg1); cout << endl;}
	else if(operation[0] == 'q' || operation[0] == 'Q') calc->quit();
	else{
		cout << "Error! " << endl;
		}
	
	}//END WHILE
	return 0;
}//END MAIN