//Michael Launius
//Assignment 5
//main implementation
//Schneider

#include <string>
#include <iostream>
#include "Node.h"
#include "List.h"
#include "AnalyzeInput.h"
using namespace std;

const bool DEBUG = false;

int main(){
	List *list = new List;
	AnalyzeInput *input = new AnalyzeInput;
	string cmdString, operation;
	int arg1;
	
	//cout << "list> "; getline(cin, cmdString);
	//input->analyzeCmd(cmdString, operation, arg1);
	if(DEBUG) cout << "in main, before while, operation = " << operation << endl;
	while(operation.compare("quit") != 0)
	{
		cout << "list> "; getline(cin,cmdString);
		input->analyzeCmd(cmdString, operation, arg1);
		
		if(operation.compare("addleft") == 0){
		if(DEBUG) cout << "in main, if addleft" << endl;
		list->addLeft(arg1);}
		
		else if(operation.compare("addright") == 0){
		if(DEBUG) cout << "in main, if addright" << endl;
		list->addRight(arg1);}
		
		else if(operation.compare("left") == 0){
		if(DEBUG) cout << "in main, if left" << endl;
		list->left();}
		
		else if(operation.compare("right") == 0){
		if(DEBUG) cout << "in main, if right" << endl;
		list->right();}
		
		else if(operation.compare("search") == 0){
		if (DEBUG) cout << "in main, if search" << endl;
		if(list->search(arg1)) cout << "true" << endl;
		else cout << "false" << endl;}
		
		else if(operation.compare("print") == 0){
		if(DEBUG) cout << "in main, if print" << endl;
		list->print();}
		
		else if(operation.compare("quit") == 0){
		if(DEBUG) cout << "in main, if quit" << endl;
		list->quit();}
		
		else{ cout << "Error! " << endl; }
	}//END WHILE
	return 0;
}//END MAIN
		
		