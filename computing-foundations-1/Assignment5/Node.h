//Michael Launius
//Assignment 5
//Node.h
//Schneider

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{ //NODE CLASS
	friend class List;
	Node(){} //Default constructor
	
	Node *next; //Ptr to next element in list
	Node *prev; //Ptr to previous element in list
	
	int data;
}; //END NODE CLASS

#endif //END HEADER