//Michael Launius
//Assignment 6 - Binary Search Tree header
//Schneider

#ifndef BST_H
#define BST_H

#include "Node.h"
#include <stdlib.h>

using namespace std;

class BST{

public:
BST(){} //Default constructor

Node* newNode;
Node* curr;
Node* parent;

int numItems;

void add(int num);
void insertNode (Node*& nodePtr, Node*& newNode);
void numToFind(int num);
bool searchNode(int num, Node* nodePtr);
void numToDelete(int num);
bool findNode(int num, Node*& nodePtr);
bool del(Node*& nodePtr);
void print();
void inorder(Node* nodePtr) const;
void height();
int getHeight(Node* node);

void quit(){exit(0);} //exits program

private:
static Node* root;
int treeHeight;

}; //END BST CLASS

#endif