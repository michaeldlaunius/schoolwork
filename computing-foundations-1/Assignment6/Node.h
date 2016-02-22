//Michael Launius
//Assignment 6
//Node.h
//Schneider

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
	friend class BST;
	
	Node(){} //Default Constructor
	
	Node* left;
	Node* right;
	Node* parent;
	
	int data;

};

#endif //END NODE CLASS HEADER