#include <iostream>
#include <string>
#include "Set.h"

using namespace std;

const bool DEBUG = false;

void Set::getInput()
{
	cout << "sets> ";
	cin >> operation;
	if(operation != "quit")
	{
		
		if(operation == "assign" || operation == "print" || operation == "clear")
		{
			cin >> setID;
			if(operation == "assign")
			{
				for(int i = 0; i < 13; i++)
				{
					cin >> cVector[i];
				}
			}	
		}
		else if(operation == "union" || operation == "intersection" || operation == "difference")
		{
			cin >> arg1;
			cin >> arg2;
		}
	
	/*--------------DEBUG-------------*/
		if(DEBUG) cout << "Operation = " << operation << endl;
		if(DEBUG) cout << "SetID = " << setID << endl;
		if(DEBUG) cout << "arg1 = " << arg1 << endl;
		if(DEBUG) cout << "arg2 = " << arg2 << endl;
		if(DEBUG)
		{
			cout << "cVector = ";
			for(int i = 0; i < 13; i++)
			{
				cout << cVector[i];
				if(i < 12) cout << "-";
			}
			cout << endl;
		}
	}//END IF STATEMENT
	/*----------------------------*/
}
///////////////////////////////
void Set::setOperation(string oper)
{
	operation = oper;
}
///////////////////////////////
string Set::getOperation()
{
	return operation;
}
///////////////////////////////
char Set::getSetID()
{
	return setID;
}
///////////////////////////////
void Set::coutCVector()
{
	for(int i = 0; i < 13; i++)
	{
		cout << cVector[i];
		if(i < 12) cout << "-";
	}
	cout << endl;
}
///////////////////////////////
void Set::assign(int array[])
{
	if(DEBUG) cout << "Set.cpp Assign" << endl;
	for(int i = 0; i < 13; i++)
	{
		array[i] = cVector[i];
		if(DEBUG) cout << array[i] << " ";
	}
	if(DEBUG) cout << endl;
}
///////////////////////////////
void Set::clear()
{
	if(DEBUG) cout << "Set.cpp - Clear" << endl;
	for(int i = 0; i < 13; i++)
	{
		cVector[i] = 0;
	}
	if(DEBUG) coutCVector();
}
///////////////////////////////
void Set::intersection(int array1[], int array2[])
{
	if(DEBUG) cout << "in intersection!" << endl;
	int result[13];
	for(int i = 0; i < 13; i++)
	{
		if(array1[i] == 1 && array2[i] == 1)
			result[i] = 1;
		else result[i] = 0;
	}
	for(int i = 0; i < 13; i++)
	{
		cout << result[i];
		if(i < 12) cout << "-";
	}
	cout << endl;
}
///////////////////////////
void Set::unn(int array1[], int array2[])
{
		if(DEBUG) cout << "in unn!" << endl;
	int result[13];
	for(int i = 0; i < 13; i++)
	{
		if(array1[i] == 1 || array2[i] == 1)
			result[i] = 1;
		else result[i] = 0;
	}
	for(int i = 0; i < 13; i++)
	{
		cout << result[i];
		if(i < 12) cout << "-";
	}
	cout << endl;
}
///////////////////////////
void Set::diff(int array1[], int array2[])
{
	if(DEBUG) cout << "in diff!" << endl;
	int result[13];
	for(int i = 0; i < 13; i++)
	{
		if(array1[i] == 1 && array2[i] != 1)
			result[i] = 1;
		else result[i] = 0;
	}
	for(int i = 0; i < 13; i++)
	{
		cout << result[i];
		if(i < 12) cout << "-";
	}
	cout << endl;
}
