//Programming Assignment #2
//Michael Launius
// Professor: Schneider

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

const bool DEBUG = false;

void calcCmd(string &cmdString){ //takes input
	cout << "calc> "; getline(cin, cmdString);
	if(DEBUG) cout << "From calcCmd: " << cmdString << endl;
}
void analyzeCmd(string cmd, string &operation, double &arg1, double &arg2){//pulls data from the input
	int wordCount = 0; //Which 'word' of the input is the loop on?
	string arg1String, arg2String;
	string buffer;
	
	
	stringstream stream(cmd);

	while (1){
		if(DEBUG) cout << "wordCount = " << wordCount << endl;
		if (wordCount == 1)
			{stream >> operation;}
		if (wordCount == 2)
			{stream >> arg1;}
		if (wordCount == 3)
			{stream >> arg2;}
		wordCount++;
		if(wordCount > 4) break;
		}
	

}		
void subtract(double arg1, double arg2){//outputs subtract
	cout << "Subtracting " << arg1 << " from " << arg2 << endl;}

void add(double arg1, double arg2){//outputs add
	cout << "Adding " << arg1 << " and " << arg2 << endl;}

void multiply(double arg1, double arg2){//outputs multiply
	cout << "Multiplying " << arg1 << " by " << arg2 << endl;}

void divide(double arg1, double arg2){//outputs divide
	cout << "Dividing " << arg1 << " by " << arg2 << endl;}
	
int quit(){//Quits program;
	exit(0);
	}

int main(){
	string cmdString, operation;
	double arg1, arg2;
	
	while(operation[0] != 'q')
	{
	calcCmd(cmdString);
	analyzeCmd(cmdString, operation, arg1, arg2);
	
	if(operation[0] == 's') subtract(arg1, arg2);
	else if(operation[0] == 'a' || operation[0] == 'A') add(arg1, arg2);
	else if(operation[0] == 'm' || operation[0] == 'M') multiply(arg1, arg2);
	else if(operation[0] == 'd' || operation[0] == 'D') divide(arg1, arg2);
	else if(operation[0] == 'q' || operation[0] == 'Q') quit();
	else{
		cout << "Error!" << endl;
		}
	
	if(DEBUG) cout << "From main, arg1 = " << arg1 << endl;
	if(DEBUG) cout << "From main, arg2 = " << arg2 << endl;
	if(DEBUG) cout << "From main, cmdString: " << cmdString << endl;
	if(DEBUG) cout << "From main, operation: " << operation << endl;
	}
	return 0;
}