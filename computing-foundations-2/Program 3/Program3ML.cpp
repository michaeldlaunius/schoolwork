/* Michael Launius
* Schneider
* Program 3 - Graphs | Program3ML.cpp
* Main Function Implementation
*/

#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

const bool DEBUG = false;
int main()
{
	string function; //function called by user
	int numBuckets; //number of buckets in graph
	bool graphExists = false; //does a graph already exist?
	Graph *graph; //placeholder graph object
		
	cout << "graph> "; cin >> function;
	
	while (function != "quit")
	{
		if (DEBUG) cout << "function: " << function << endl;
		if (function == "create") //calls Graph(int N) constructor to create new graph
		{
			if (DEBUG) cout << "in: main: create" << endl;
			if(graphExists) //If a graph already exists, delete it
			{
				if (DEBUG) cout << "a graph already exists, deleting graph... ";
				delete graph;
				if(DEBUG) cout << "DONE!" << endl;
			}
			cin >> numBuckets;
			graph = new Graph(numBuckets); //creates graph
			graphExists = true;
		}
		
		else if (function == "insert")
		{
			if (DEBUG) cout << "in: main: insert" << endl;
			if (graphExists) graph->insert();
			else 
			{
				cout << "Error! No graph exists" << endl;
				cin.clear();
			}
		}
		
		else if (function == "remove")
		{
			if (DEBUG) cout << "in: main: remove" << endl;
			graph->remove();
		}
		
		else if(function == "print")
		{
			if (DEBUG) cout << "in: main: print" << endl;
			graph->print();
		}
		
		else cout << "Error! Invalid function" << endl;

		cout << "graph> "; cin >> function;
	}
	return 0;
}