//Michael Launius
//Assignment 6
//Schneider

#include <string>
#include <iostream>
#include "Node.h"
#include "BST.h"
#include "AnalyzeInput.h"

using namespace std;

const bool DEBUG = false;

int main()
{
	BST* bst = new BST;
	AnalyzeInput* input = new AnalyzeInput;
	string cmdString, operation;
	int arg1;
	
	while(operation.compare("quit") != 0)
	{
		cout << "bst> "; getline (cin, cmdString);
		input->analyzeCmd(cmdString, operation, arg1);
		
		if(operation.compare("add") == 0) bst->add(arg1);
		
		else if(operation.compare("delete") == 0) bst->numToDelete(arg1);
		
		else if(operation.compare("search") == 0) bst->numToFind(arg1);
		
		else if(operation.compare("inorder") == 0){
			 bst->print(); cout << endl;}
		
		else if(operation.compare("height") == 0) bst->height();
		
		else if (operation.compare("quit") == 0) bst->quit();
				
		else{ cout << "Error! " << endl; }
	}
	return 0;
}