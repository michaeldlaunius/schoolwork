/* Michael Launius
* Schneider
* Program 3 - Graphs | List.h
* List Prototype
*/

#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List
{
	public:
		friend class Graph;
		List(){};
	
		Node * curr;
		Node * n;
		

	
	private:
	
		Node * head;
		Node * tail;
		
};
#endif