//Michael Launius
//Assignment 5
//List.cpp
//Schneider

#include <iostream>
#include <string>
#include <sstream>
#include "List.h"

using namespace std;

const bool DEBUG = false;

Node* List::head;
Node* List::tail; 
int data = 0;

void List::addLeft(int numLeft)
{
	//if(DEBUG) cout << "in addleft, before if, head = " << head->data << endl;
	if(head == NULL){
		if(DEBUG) cout << "in addleft, if head == NULL" << endl;
		curr = new Node;
		curr->data = numLeft;
		curr->next = NULL;
		curr->prev = NULL;
		head = curr;
		tail = curr;
		nsize++;
		// if(DEBUG){
			// cout << "in addleft, if head == NULL:" << endl;
			// //cout << "next = " << curr->next->data << endl;
			// //cout << "prev = " << curr->prev->data << endl;
			// cout << "curr data = " << curr->data << endl;
			// cout << "nsize = " << nsize << endl;
		// }
		
		return;
	}
	
	if (head != NULL){
		n = new Node;
		n->data = numLeft;
		
		if(curr->prev == NULL) head = n;
		
		n->next = curr;
		n->prev = curr->prev;
		if(curr->prev != NULL) curr->prev->next = n;
		curr->prev = n;
		
		nsize++;
		// if(DEBUG){
			// cout << "in addleft, if head == NULL:" << endl;
			// //cout << "next = " << curr->next << endl;
			// //cout << "prev = " << curr->prev << endl;
			// cout << "curr data = " << curr->data << endl;
			// cout << "nsize = " << nsize << endl;
		// }
		return;
	}
}

void List::addRight(int numRight)
{
	if(head == NULL){
		if(DEBUG) cout << "in addright, if head == NULL" << endl;
		curr = new Node;
		curr->data = numRight;
		curr->next = NULL;
		curr->prev = NULL;
		head = curr;
		tail = curr;
		nsize++;
		return;
	}
	
	else if (head != NULL){
		if(DEBUG) cout << "in addright, if head != NULL" << endl;
		n = new Node;
		n->data = numRight;
		
		if(curr->next == NULL) tail = n;
		
		n->prev = curr;
		n->next = curr->next;
		if(curr->next != NULL) curr->next->prev = n;
		curr->next = n;

		nsize++;
		return;
	}
}

void List::left()
{
	if(head == NULL || curr->prev == NULL){
		cout << "Error! At end of list" << endl;
	}
	
	else{
		if(DEBUG) cout << "left, in else statement (curr->prev != NULL)" << endl;
		curr = curr->prev;
		
		cout << curr->data << endl;
		if(DEBUG) cout << "curr = " << curr->data << endl;
	}
}

void List::right()
{
	if(head == NULL || curr->next == NULL){
		cout << "Error! At end of list" << endl;
	}
	
	else{
		if(DEBUG) cout << "right, in else statement (curr->next != NULL)" << endl;
		curr = curr->next;
		cout << curr->data << endl;
		if(DEBUG) cout << "curr = " << curr->data << endl;
	}
}

bool List::search(int numSearch)
{
	Node* searchPtr = new Node;
	searchPtr = head;
	bool found = false;
	
	while (searchPtr->next != NULL)
	{
		if(DEBUG) cout << "in search, in WHILE loop" << endl;
		if(searchPtr->data != numSearch && searchPtr->next != NULL)
		{
			if(DEBUG) cout << "in search, hasnt been found" << endl;
			searchPtr = searchPtr->next;
			if(DEBUG) cout << "in search, searchPtr = " << searchPtr->data << endl;
		}
		
		if(searchPtr->data == numSearch)
		{
			if(DEBUG) cout << "in search, FOUND IT" << endl;
			found = true;
			return found;
		}
	}
	return false;
}

void List::print()
{
	Node *printPtr = new Node;
	printPtr = head;
	
	while(printPtr != NULL)
	{
		cout << printPtr->data;
		if(printPtr->next != NULL) cout << "-";
		printPtr = printPtr->next;
	}
	cout << endl;
}
