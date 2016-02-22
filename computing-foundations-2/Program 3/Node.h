/* Michael Launius
* Schneider
* Program 3 - Graphs | Node.h
* Node Prototype
*/

#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		friend class List;
		
		Node(){};
		
		Node *next;
		
		int weight;
		int nodeID;
		
};
#endif