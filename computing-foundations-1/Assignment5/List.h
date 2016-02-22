//Michael Launius
//Assignment 5
//List.h
//Schneider

#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <stdlib.h>
using namespace std;

class List{ //LIST CLASS
	
	public:
		List(){} //default constructor
		
		Node* curr; //Current pointer to element in list
		Node* n; //node to store data
		
		void addLeft(int numLeft); //inserts num to the left of current pointer
		
		void addRight(int numRight); //inserts num to the right of current pointer
		
		void left(); //moves current pointer left and prints out what it is now pointing to.
		
		void right(); //moves current pointer right and prints out what it is now pointing to.
		
		bool search(int numSearch); //Searches list for given number, prints 'true' if found, 'false' if not
		
		void print(); //prints nodes from left to right, separated by hyphens
		
		void quit(){exit(0);} //exits program
	
	private:
		static Node *head;
		static Node *tail;
		int nsize;
		
}; //END LIST CLASS

#endif //END HEADER
		
		