/* Michael Launius
* Schneider
* Program 2 - Tables | Row.h
* Row Prototype
*/

#ifndef ROW_H
#define ROW_H

#include <string>
using namespace std;
class Row
{
	public:
		friend class Table;
		Row(){};
		Row *next;
		
		private:
		string arr[5];
		
};
#endif