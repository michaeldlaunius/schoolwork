/* Michael Launius
* Schneider
* Program 2 - Tables | Table.cpp
* Table class implementation
*/

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Table.h"
using namespace std;

//Row *Table::head;
//Row *Table::tail;
const bool DEBUG = false;

/* insert: Inserts new row into table without checking for duplicates
* Appends new rows to end of linked list */
void Table::insert(int numItems)
{
	static int beenHere = 0;
	int testNum = 0;
	if (head == NULL)
	{
		if(DEBUG) cout << "IN HEAD == NULL" << endl;
		head = new Row;
		
		if(DEBUG) cout << "head = NULL, if" << endl;
		for (int i = 0; i < numItems; i++)
			cin >> head->arr[i];
		//print(3);
		cin.clear();
	}
	
	else
	{
		n = head;

		while (n->next != NULL) //Find last row of the table
		{
			//if(DEBUG){print(3);}
			n = n->next;
		}
		
		n->next = new Row;
				
		if(DEBUG) cout << "head != NULL, grades, if" << endl;
		for (int i = 0; i < numItems; i++)
		{
			cin >> n->next->arr[i];
		}
		//curr->next = n;
		cin.clear();
		//if(DEBUG) print(3);
	}
	if(DEBUG) print(4);
	numRows++;
}
///////////////////////////////////////////////////////////////
/* Prints out rows of table */
void Table::print(int numItems)
{
	Row *printPtr = new Row;
	printPtr = head;
	
// 	if(DEBUG)
// 	{
// 		cout << "head: ";
// 		for(int i = 0; i < numItems; i++)
// 			cout << head->arr[i] << ".";
// 		cout << endl;
// 	}

	while(printPtr != NULL)
	{
	cout << "(";
	for(int i = 0; i < numItems; i++)
	{
		cout << printPtr->arr[i];
		if(i < numItems-1) cout << ",";
	}
	cout << ")";
	printPtr = printPtr->next;
	}
	cout << endl;
}
///////////////////////////////////////////////////////////////
void Table::select(string table, int numItems)
{
	int attrIndex;
	bool doneThat = 0;
	string attr;
	string value;
	int searchNum = 0;
	
	n = head;
	
	cin >> attr;
	cin >> value;
	//Set attribute to corresponding array element
	if(table == "students")
	{
		if(attr == "id")
			attrIndex = 0;
		else if(attr == "firstname")
			attrIndex = 1;
		else if(attr == "lastname")
			attrIndex = 2;
		else 
		{
			cout << "Error! Invalid attribute" << endl;
			return;
		}
	}
	else if (table == "grades")
	{
		if(attr == "id")
			attrIndex = 0;
		else if(attr == "term")
			attrIndex = 1;
		else if(attr == "year")
			attrIndex = 2;
		else if(attr == "grade")
			attrIndex = 3;
		else
		{
			cout << "Error! Invalid attribute" << endl;
			return;
		}
	}
	else
	{
		cout << "Error! Invalid table" << endl;
		return;
	}
	//////
	//Search table for given value & print out any row containing the value
	while (searchNum < numRows)
	{
		if(DEBUG && doneThat == 0)
		{
			cout << "select in search while loop!" << endl;
			doneThat = 1;
		}
		if(n->arr[attrIndex] == value)
		{
			cout << "(";
			for(int i = 0; i < numItems; i++)
			{
				cout << n->arr[i];
				if(i < numItems-1) cout << ",";
			}
			cout << ")";
		}
		n = n->next;
		searchNum++;
	}
	cout << endl;
}
///////////////////////////////////////////////////////////////
/*Joins two tables*/
void Table::join(Table *table2)
{
	int searchNum = 0;
	int searchNum2 = 0;
	bool doneThat = 0;
	bool didOutput = 0; //Did join yield a result?
	
	n = head;
	table2->n = table2->head;
	
	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < table2->numRows; j++)
		{
			if(n->arr[0] == table2->n->arr[0])
 			{
 				didOutput = 1;
 				cout << "(";
 				for(int k = 0; k < 3; k++)
 				{
 					cout << n->arr[k];
 					cout << ",";
 				}
 				for(int k2 = 1; k2 < 4; k2++)
 				{
 					//if(DEBUG) cout << "join, second half of join, i = " << i << endl;
 					cout << table2->n->arr[k2];
 					if(k2<3) cout << ",";
 				}
				cout << ")";
			}
			if(table2->n->next != NULL) table2->n = table2->n->next;
 		}
 		if(n->next != NULL) n = n->next;
 		table2->n = table2->head;
 	}
	
// 	while (searchNum < numRows) //Find rows with matching id's and join them
// 	{
// 		if(DEBUG && doneThat == 0)
// 		{
// 			cout << "join, in while loop!" << endl;
// 			doneThat = 1;
// 		}
// 		if(n->arr[0] == table2->n->arr[0])
// 		{
// 			didOutput = 1;
// 			cout << "(";
// 			for(int i = 0; i < 3; i++)
// 			{
// 				cout << n->arr[i];
// 				cout << ",";
// 			}
// 			for(int i = 1; i < 4; i++)
// 			{
// 				//if(DEBUG) cout << "join, second half of join, i = " << i << endl;
// 				cout << table2->n->arr[i];
// 				if(i<3) cout << ",";
// 			}
// 			cout << ")";
// 		}
// 		if(n->next != NULL || table2->n->next != NULL)
// 		{
// 			if(n->next != NULL) n = n->next;
// 			if(table2->n->next != NULL) table2->n = table2->n->next;
// 		}
// 		else return;
// 		
// 		searchNum++;
// 	}
	if(didOutput)cout << endl;
}		
		