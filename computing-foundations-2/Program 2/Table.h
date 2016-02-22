/* Michael Launius
* Schneider
* Program 2 - Tables | Table.h
* Table Prototype
*/

#ifndef TABLE_H
#define TABLE_H

#include "Row.h"
#include <string>

class Table
{
	public:
		Table(){}; //default constructor
		Row *n;
		Row *curr;
		
		void insert(int numItems);
		void print(int numItems);
		void select(string table, int numItems);
		void join(Table *table2);

	private:
		Row *head;
		Row *tail;
		int numRows;


};
#endif