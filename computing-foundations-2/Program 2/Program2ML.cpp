/* Michael Launius
* Schneider
* Program 2 - Tables | Program2ML.cpp
* Main Function Implementation
*/

//Received permission from Dr. Schneider to use only 'Row' and 'Table' classes
#include <iostream>
#include <string>
#include "Table.h"
#include "Row.h"
using namespace std;

const bool DEBUG = false;
int main()
{
	/*-------------Variables------------*/
	string function;
	string table;

	Table *students = new Table;
	Table *grades = new Table;
	
	/*-------------Function Calls-------*/
	cout << "tables> ";
	cin >> function;
	while(function != "quit")
	{
		if(DEBUG) cout << "Function: " << function << endl;
		//if(DEBUG) cout << "Table: " << table << endl;
		
		if(function == "insert")
		{
			cin >> table;
			if(DEBUG) cout << "insert, Table: " << table << endl;
			
			if(table == "students") students->insert(3);
			else if (table == "grades") grades->insert(4);
			else cout << "Error! Invalid table" << endl;
		}
		
		else if(function == "print")
		{
			cin >> table;
			if(DEBUG) cout << "print, Table: " << table << endl;
			
			if (table == "students") students->print(3);
			else if(table == "grades") grades->print(4);
			else cout << "Error! Invalid table" << endl;
		}
		
		else if(function == "select")
		{
			cin >> table;
			if(DEBUG) cout << "select, Table: " << table << endl;
			
			if (table == "students") students->select(table,3);
			else if(table == "grades") grades->select(table,4);
			else cout << "Error! Invalid table" << endl;
		}
		
		else if(function == "join")
		{
			students->join(grades);
		}
		
		else cout << "Error! Invalid function" << endl;
		cout << "tables> ";
		cin >> function;
		//cin.clear();
	}
	return 0;
}
//Received permission from Dr. Schneider to use only 'Row' and 'Table' classes
