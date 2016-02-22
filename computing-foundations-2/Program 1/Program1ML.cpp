#include <string>
#include <iostream>
#include "Set.h"

using namespace std;

const bool DEBUG = false;

int main()
{
	Set *R = new Set;
	Set *S = new Set;
	Set *T = new Set;
	Set input;
	
	
	input.setOperation("default");
	while(input.getOperation() != "quit")
	{
		input.getInput();
		/*----------assign--------*/
		if(input.getOperation() == "assign")
		{
			if(input.getSetID() == 'R')
			{
				if(DEBUG) cout << "Assign -> R" << endl;
				input.assign(R->cVector);
				if(DEBUG) R->coutCVector();
			}
			if(input.getSetID() == 'S')
			{
				if(DEBUG) cout << "Assign -> S" << endl;
				input.assign(S->cVector);
				if(DEBUG) S->coutCVector();
			}
			if(input.getSetID() == 'T')
			{
				if(DEBUG) cout << "Assign -> T" << endl;
				input.assign(T->cVector);
				if(DEBUG) T->coutCVector();
			}
		}
		/*-------------clear---------*/
		else if(input.getOperation() == "clear")
		{
			if(DEBUG) cout << "main -> clear" << endl;
			if(input.getSetID() == 'R')
			{
				R->clear();
			}
			else if(input.getSetID() == 'S')
			{
				S->clear();
			}
			else if(input.getSetID() == 'T')
			{
				T->clear();
			}
		}
		/*-----------intersection---------*/
		else if(input.getOperation()== "intersection")
		{
			if(input.arg1 == 'R')
			{
				if(input.arg2 == 'S') input.intersection(R->cVector, S->cVector);
				if(input.arg2 == 'T') input.intersection(R->cVector, T->cVector);
			}
			else if(input.arg1 == 'S')
			{
				
				if(input.arg2 == 'R') input.intersection(S->cVector, R->cVector);
				if(input.arg2 == 'T') input.intersection(S->cVector, T->cVector);
			}
			else if(input.arg1 == 'T')
			{
				if(input.arg2 == 'R') input.intersection(T->cVector, R->cVector);
				if(input.arg2 == 'S') input.intersection(T->cVector, S->cVector);
			}
		}
		/*----------union-------------*/
		else if(input.getOperation() == "union")
		{
				if(input.arg1 == 'R')
			{
				if(input.arg2 == 'S') input.unn(R->cVector, S->cVector);
				if(input.arg2 == 'T') input.unn(R->cVector, T->cVector);
			}
			else if(input.arg1 == 'S')
			{
				
				if(input.arg2 == 'R') input.unn(S->cVector, R->cVector);
				if(input.arg2 == 'T') input.unn(S->cVector, T->cVector);
			}
			else if(input.arg1 == 'T')
			{
				if(input.arg2 == 'R') input.unn(T->cVector, R->cVector);
				if(input.arg2 == 'S') input.unn(T->cVector, R->cVector);
			}
		}
		/*--------difference-----------*/
		else if(input.getOperation() == "difference")
		{
			if(input.arg1 == 'R')
			{
				if(input.arg2 == 'S') input.diff(R->cVector, S->cVector);
				if(input.arg2 == 'T') input.diff(R->cVector, T->cVector);
			}
			else if(input.arg1 == 'S')
			{
				
				if(input.arg2 == 'R') input.diff(S->cVector, R->cVector);
				if(input.arg2 == 'T') input.diff(S->cVector, T->cVector);
			}
			else if(input.arg1 == 'T')
			{
				if(input.arg2 == 'R') input.diff(T->cVector, R->cVector);
				if(input.arg2 == 'S') input.diff(T->cVector, R->cVector);
			}
		}
		else if(input.getOperation() == "print")
		{
			if(input.getSetID() == 'R') R->coutCVector();
			else if(input.getSetID() == 'S') S->coutCVector();
			else if(input.getSetID() == 'T') T->coutCVector();
		}
		else if(input.getOperation() != "clear" && input.getOperation() != "quit") cout << "Error! in main" << endl;
	}

	return 0;
}
