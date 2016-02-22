//Michael Launius
//Assignment 3: Calc class implementation
//Dr. Schneider

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Calculator.h"
using namespace std;

string bString;
void Calculator::calcCmd(string &cmdString){ //takes input
	cout << "calc> "; getline(cin, cmdString);
}

void Calculator::analyzeCmd(string cmd, string &operation, double &arg1, double &arg2){//pulls data from the input
	int wordCount = 0; //Which 'word' of the input is the loop on?
	string arg1String, arg2String;
	string buffer;
	stringstream stream(cmd);

	while (1){
		if (wordCount == 1)
			{stream >> operation;}
		if (wordCount == 2)
			{stream >> arg1;}
		if (wordCount == 3)
			{stream >> arg2;}
		wordCount++;
		if(wordCount > 4) break;
	}

}//END

void Calculator::binary(int number){
	int remainder;
	if(number <= 1) {
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number >> 1);    
	cout << remainder;

}//END