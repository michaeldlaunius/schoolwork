//Michael Launius
//Scheider

#include <iostream>

#include "BST.h"

using namespace std;

const bool DEBUG = true;

Node* BST::root;

/*----------------------------------ADD NODE-------------------------------*/

void BST::add(int num)
{	
	newNode = new Node;
	newNode->data = num;
	newNode->left = NULL;
	newNode->right = NULL;
	
	insertNode(root, newNode);
	
	/*if (DEBUG) cout << "in add!"<< endl;
	if (root == NULL)
	{
		if(DEBUG) cout << "root == NULL" << endl;
		root = n;
		if(DEBUG) cout << "root should not be null now" << endl;
		n->left = NULL;
		n->right = NULL;
		//parent = NULL;
		numItems++;
		if(DEBUG) cout << "numItems = " << numItems << endl;
	}
	
	else if (root != NULL){
		if(DEBUG) cout << "root != NULL" << endl;
		 insertNode(n, num);} */
		 
		 
}	
void BST::insertNode(Node*& nodePtr, Node*& newNode)
{

	
	/*if(num < nodePtr->data)
	{
		if(nodePtr->left == NULL)
		nodePtr->left = n;
		if(DEBUG) cout << "nodePtr->left data = " << nodePtr->left->data << endl;
		
		else{
		 insertNode(nodePtr->left, num);
		 	if(DEBUG) cout << "nodePtr->left data = " << nodePtr->left->data << endl;
		 	}

	}
	else
	{
		if(DEBUG) cout << "num > data" << endl;
			if(nodePtr->right == NULL){
			if(DEBUG) cout << "right == NULL" << endl;
			nodePtr->right = n;
			if(DEBUG) cout << "nodePtr->right = " << nodePtr->right->data << endl;
		}
		else insertNode(nodePtr->right, num);
	}
	numItems++;
	if(DEBUG) cout << "numItems = " << numItems << endl;*/
	
	////////////////
	
	
	
	if(nodePtr == NULL) 
	{
		nodePtr = newNode;
		if(DEBUG) cout << "nodePtr == NULL" << endl;
	}
	else if(nodePtr->data < newNode->data){
		if(DEBUG) cout << "nodePtr < newNode" << endl;
		 insertNode(nodePtr->right, newNode);
		 
		 }
	else insertNode(nodePtr->left, newNode);
}
	


/*---------------------------------SEARCH FOR NODE--------------------------*/
void BST::numToFind(int num)
{
	if(searchNode(num, root)) cout << "true" << endl;
	else cout << "false" << endl;
	}

bool BST::searchNode(int num, Node* nodePtr)
{
	if(DEBUG) cout << "root = " << root->data << endl;
	//if(DEBUG) cout << "nodePtr->right =" << nodePtr->right->data << endl;
	//if(DEBUG) cout << "this node = " << nodePtr->data << endl;
	
	if(nodePtr->data == num) return true;
	
	if(nodePtr == NULL) return false;
	if(num < nodePtr->data)
	{
		if(DEBUG) cout << "node < nodePtr->data" << endl;
		return searchNode(num, nodePtr->left);
	}
	else if(num > nodePtr->data)
	{
		if(DEBUG) cout << "node > nodePtr->data" << endl;
		return searchNode(num, nodePtr->right);
	}
}
/* 	//while (nodePtr != NULL)
	{
		//if(DEBUG) cout << "nodePtr data = " << nodePtr->data << endl;
		if(nodePtr->data == num)
		{
			return true;
		}
		else if(num < nodePtr->data)
		{
			if(DEBUG) cout << "HELPPPPPPPPPP" << endl;
			nodePtr = nodePtr->left;
		}
		else nodePtr = nodePtr->right;
	} return false; */

/*--------------------------------- REMOVE NODE ----------------------------*/
void BST::numToDelete(int num)
{
	findNode(num, root);
}

bool BST::findNode(int num, Node*& nodePtr)
{
	bool found = false;
	if (num < nodePtr->data)
		findNode(num, nodePtr->left);
	else if (num > nodePtr->data)
		findNode(num, nodePtr->right);
	else if(num == nodePtr->data)
	{
		found = true;
		del(nodePtr);
	}
	return found;
}

bool BST::del(Node*& nodePtr)
{
	Node* temp;
	bool deleted = true;
	
	if(nodePtr == NULL) return deleted = false;
	
	else if(nodePtr->right == NULL)
	{
		temp = nodePtr;
		nodePtr = nodePtr->left;
		delete temp;
	}
	else if(nodePtr->left == NULL)
	{
		temp = nodePtr;
		nodePtr = nodePtr->right;
		delete temp;
	}
	else
	{
		temp = nodePtr->right;
		while(temp->left) temp = temp->left; //go to leftmost node
		temp->left = nodePtr->left;
		temp = nodePtr;
		nodePtr = nodePtr->right;
		delete temp;
	}
	return deleted;
}		
/*--------------------------------------------------------------------------*/	

//-------------------------------------------IN ORDER------------------------
void BST::print()
{
	inorder(root);
}
void BST::inorder(Node *nodePtr) const
{
	if(nodePtr)
	{
		inorder(nodePtr->left);
		cout << nodePtr->data << "-";
		inorder(nodePtr->right);
	}
}
//-------------------------------------------------------------------------
/*int BST::totalHeight(Node* node)
{
	if(node == NULL) return 0;
	
	int leftHt = getHeight(node->left);
	int rightHt = getHeight(node->right);
	int totalHt = 1 + leftHt + rightHt;
	
	return totalHt;
}*/
/*------------------------------HEIGHT------------------------*/
void BST::height()
{
	treeHeight = getHeight(root);
	cout << treeHeight << endl;
}

int BST::getHeight(Node* node)
{
	if(node == NULL) return 0;
	
	return 1 + max(getHeight(node->left), getHeight(node->right));
}
/*----------------------------------------------------------*/
/* 	Node* printPtr = new Node;
	printPtr = root;
	
	Node* prev;
	
	if(root == NULL) return;
	
	curr = root;
	while(curr != NULL)
	{
		if(curr->left == NULL) cout << curr->data << "-";
		else
		{
			prev = curr->left;
			while(prev->right != NULL && prev->right != curr) prev = prev->right;
			
			if(prev->right == NULL)
			{
				prev->right = curr;
				curr = curr->left;
			}
			
			else
			{
				prev->right = NULL;
				cout << curr->data << "-";
			}
		}
	}
}
		 */
	