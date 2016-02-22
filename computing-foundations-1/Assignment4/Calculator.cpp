//Michael Launius
//Assignment 4: Calc class implementation
//Dr. Schneider

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Calculator.h"
using namespace std;

string bString;

void Calculator::saveIntToArray(int intResult) //saves result of operation to the array of results
{
	resultArray[index] = new Result;
	resultArray[index]->classIntResult = intResult;
	resultArray[index]->classStrResult = "A";
	index++;
	numberOfResults++;
	//cout << "numResults = " << numberOfResults << endl;
}//END

void Calculator::saveStringToArray(string strResult)
{
	resultArray[index] = new Result;
	resultArray[index]->classStrResult = strResult;
	index++;
	numberOfResults++;
}
void Calculator::outputArray()
{
	int sizeOfArray = 0;
	int index = 0;

	while (index < numberOfResults){
	if(resultArray[index]->classStrResult != "A"){
		cout << resultArray[index]->classStrResult;
	}
	else cout << resultArray[index]->classIntResult;
	if (index != numberOfResults-1){
	cout << "-";
		}
	index++;
	}
	cout << endl;
}

void Calculator::calcCmd(string &cmdString){ //takes input
	cout << "calc> "; getline(cin, cmdString);
}//END

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
		bStr << number;
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number >> 1);  
	bStr << remainder;
	cout << remainder;
	
	//cout << "bStr = " << bStr.str() << endl;

}//END