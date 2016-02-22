/* Michael Launius
* Schneider
* Program 3 - Graphs | Graph.cpp
* Graph Implementation
*/

#include <string>
#include <iostream>
#include "Graph.h"
//#include "List.h"

using namespace std;

const bool DEBUG = false;

//////////////////////////////////////////////
Graph::Graph(int N)
{
	arr = new List*[N];
	numBuckets = N;
	
	if(DEBUG) cout << "in: Graph.cpp: Graph(int N)" << endl;
	if(DEBUG) cout << "creating graph of size " << N << endl;
	for(int i = 0; i < N; i++)
	{
		arr[i] = new List;
		arr[i]->head = NULL;
		if(DEBUG) cout << "arr[" << i << "]->head is now NULL" << endl;
		arr[i]->curr = arr[i]->head;
	}
} 

//////////////////////////////////////////////
void Graph::insert()
{
	int source, dest, weight;
	bool oneNode = 1;
	cin >> source;
	cin >> dest;
	cin >> weight;
	
	if(source > numBuckets-1 || source < 0)
	{
		cout << "Error! Invalid source node" << endl;
		return;
	}
	
	else if (dest > numBuckets-1 || dest < 0)
	{
		cout << "Error! Invalid destination node" << endl;
		return;
	}
	
	if(DEBUG)
	{
		cout << "in: Graph.cpp: insert()" << endl;
		cout << "source: " << source << endl;
		cout << "destination: " << dest << endl;
		cout << "weight: " << weight << endl;
	}
	if(arr[source]->head == NULL) //if the head is NULL, AKA the list is empty
	{
		if(DEBUG) cout << "-> if head == NULL" << endl;
		arr[source]->curr = new Node;
		arr[source]->curr->next = NULL;
		arr[source]->head = arr[source]->curr;
		arr[source]->tail = arr[source]->curr;
		
		arr[source]->curr->nodeID = dest;
		arr[source]->curr->weight = weight;
		
		if(DEBUG) cout << "check nodeID: " << arr[source]->curr->nodeID << endl;
		if(DEBUG) cout << "check weight: " << arr[source]->curr->weight << endl;
		
		return;
	}
	
	if(arr[source]->head != NULL) //if the head is not NULL, AKA the list is not empty
	{
		if(DEBUG) cout << "-> if head != NULL" << endl;
		
		Node *temp1 = new Node;
		temp1 = arr[source]->head;
		if(oneNode == true)
		{
			if(temp1->nodeID == dest)
			{
				if(DEBUG) cout << "--> nodeID = dest" << endl;
				temp1->weight = weight;
				return;
			}
			oneNode = false;
		}
		while(temp1->next != NULL)
		{
			if(DEBUG) cout << "temp1->nodeID = " << temp1->nodeID << endl;
			if(temp1->nodeID == dest)
			{
				if(DEBUG) cout << "--> nodeID = dest" << endl;
				temp1->weight = weight;
				return;
			}
			
			temp1 = temp1->next;
		}
			
		Node *temp = new Node;
		temp->nodeID = dest;
		temp->weight = weight;
		temp->next = NULL;
		temp1->next = temp;
		arr[source]->tail = temp;
		
		return;
		
		
// 		arr[source]->n = new Node;
// 		arr[source]->n->nodeID = dest;
// 		arr[source]->n->weight = weight;
// 		arr[source]->n = NULL;
// 		
// 		arr[source]->tail = arr[source]->head;
// 		
// 		while(arr[source]->tail->next != NULL || oneNode == 1) //find the end of the list
// 		{
// 			oneNode = 0;
// 			if(DEBUG) cout << "in while loop... " << endl;
// 			if(arr[source]->tail->nodeID == dest)
// 			{
// 				if(DEBUG) cout << "--> replacing weight... ";
// 				arr[source]->tail->weight = weight;
// 				if(DEBUG) cout << " DONE!" << endl;
// 				return;
// 			}
// 			if(DEBUG) cout << "after if edge already exists" << endl;
// 			arr[source]->tail = arr[source]->tail->next;
// 			
// 		}
// 		arr[source]->tail->next = arr[source]->n;
			
// 		if(arr[source]->curr->nodeID == dest) //if a node with the given id already exists
// 		{
// 			if(DEBUG) cout << "--> replacing weight... " << endl;
// 			arr[source]->curr->weight = weight; //change its weight
// 			return;
// 		}
		//arr[source]->curr->nodeID = dest;
		//arr[source]->curr->weight = weight;
	}
}
//////////////////////////////////////////////
void Graph::remove()
{
	int source, dest;
	
	cin >> source;
	cin >> dest;
	
	if(DEBUG) cout << "in: Graph.cpp: remove()" << endl;
	
	if(source > numBuckets || source < 0)
	{
		cout << "Error! Invalid source node" << endl;
		return;
	}
	
	else if (dest > numBuckets || dest < 0)
	{
		cout << "Error! Invalid destination node" << endl;
		return;
	}
	else if (arr[source]->head == NULL)
	{
		cout << "Error! Edge does not exist" << endl;
		return;
	}
	
	Node *removePtr = NULL;
	Node *prevPtr = NULL;
	if(DEBUG) cout << "before if statement" << endl;
	if(arr[source]->head->nodeID == dest) //check to see if head matches
	{
		if(DEBUG) cout << "in if head == dest" << endl;
		removePtr = arr[source]->head; //point to node to be removed
		arr[source]->head = removePtr->next; //update pointers
		delete removePtr; // delete
		return;
	}
	if(DEBUG) cout << "after if statement" << endl;
	prevPtr = arr[source]->head;
	removePtr = arr[source]->head->next;
	
	if(DEBUG) cout << "before while loop" << endl;
	while (removePtr != NULL) //traverse the rest of the list
	{
		if(DEBUG) cout << "traversing list... " << endl;
		if (removePtr->nodeID == dest)
		{
			if(DEBUG) cout << "Found a match, returning... " << endl;
			prevPtr->next = removePtr->next;
			
			if(removePtr == arr[source]->tail)
			{
				arr[source]->tail = prevPtr;
			}
			
			delete removePtr;
			return;
		}
		prevPtr = removePtr;
		removePtr = removePtr->next;
	}
		
	cout << "Error! Edge does not exist" << endl;
	
}
/////////////////////////////////////////////
void Graph::print() //print out graph
{
	if(DEBUG) cout << "in: Graph.cpp: print()" << endl;
	
	Node *printPtr = new Node;
	
	for(int i = 0; i < numBuckets; i++)
	{
		printPtr = arr[i]->head;
		
		while(printPtr != NULL)
		{
			cout << "(" << i << "," << printPtr->nodeID;
			cout << "," << printPtr->weight << ")";
			printPtr = printPtr->next;
		}
	}
	cout << endl;
	}
		