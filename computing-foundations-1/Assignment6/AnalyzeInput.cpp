//Michael Launius
//Assignment 6
//AnalyzeInput.cpp
//Schneider

#include <iostream>
#include <string>
#include <sstream>
#include "AnalyzeInput.h"
using namespace std;

const bool DEBUG = false;

void AnalyzeInput::analyzeCmd(string cmd, string &operation, int &arg1){//pulls data from the input
	int wordCount = 0; //Which 'word' of the input is the loop on?
	string arg1String;
	string buffer;
	stringstream stream(cmd);
	if(DEBUG) cout << "in analyzeCmd" << endl;
	while (1){
		if (wordCount == 1)
			{stream >> operation;}
		if (wordCount == 2)
			{stream >> arg1;}
		wordCount++;
		if(wordCount > 3) break;
	}

}//END