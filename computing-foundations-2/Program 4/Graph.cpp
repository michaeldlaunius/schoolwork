/* Michael Launius
* Schneider
* Program 4 - Shortest Paths
* Graph.cpp | Graph implementation
*/

#include <string>
#include <iostream>
#include "Graph.h"

using namespace std;

const bool DEBUG = false;
#define LRG_VAL 999999999
//////////////////////////////////////
void Graph::setGraph()
{
	if(DEBUG) cout << "IN Graph::setGraph()" << endl;
	
	cin >> size;
	
	for(int i = 0; i < size; i++) //Make sure diagonals are 0'd
	{
		for(int j = 0; j < size; j++)
		{
			cin >> graph[i][j];
			if(i == j && graph[i][j] != 0) 
			{
				cout << "Error! " << "graph[" << i << "][" << j << "] ";
				cout << "does not equal 0, setting it to 0" << endl;
				graph[i][j] = 0; //graph should now be valid
			}
		}
	}
	
	//Replace -1's with arbitrarily large values
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(graph[i][j] == -1)
			{
				graph[i][j] = LRG_VAL;
			}
		}
	}

	if(DEBUG)
	{
		cout << "Before floyd... " << endl;
	 	getGraph();
	 }
	floyd();
}
///////////////////////////////////////
void Graph::getGraph()
{
	if(DEBUG) cout << "IN Graph::getGraph()" << endl;
	
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			cout << graph[i][j];
			if(i != size && j != size)
			{
				cout << " ";
			}
		}
	}
	cout << endl;
}
////////////////////////////////////////
void Graph::floyd()
{
	if(DEBUG) cout << "IN Graph::floyd()" << endl;
	
	for(int k = 0; k < size; k++)
	{
		//if(DEBUG) cout << "k = " << k << endl;
		for(int i = 0; i < size; i++)
		{
			//if(DEBUG) cout << "i = " << i << endl;
			for(int j = 0; j < size; j++)
			{
				//if(DEBUG) cout << "j = " << j << endl;
				if(i != j)
				{
					if(DEBUG)
					{
						cout << "graph[" << i << "][" << j << "] = ";
						cout << graph[i][j] << endl;
						cout << "graph[" << i << "][" << k << "] + ";
						cout << "graph[" << k << "][" << j << "] = ";
						cout << graph[i][k]+graph[k][j] << endl;
						if(DEBUG) cout << "GRAPH: ";
						if(DEBUG) getGraph();
					}
					if((graph[i][j] > graph[i][k] + graph[k][j]) && graph[i][j] != 0)
					{
						if(DEBUG) cout << "Replacing... " << endl;
						graph[i][j] = graph[i][k] + graph[k][j];
					}
					else
					{
						graph[i][j] = graph[i][j];
					}
				}
			}
		}
	}

	//Replace remaining infinities with -1
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(graph[i][j] == LRG_VAL)
			{
				graph[i][j] = LRG_VAL;
			}
		}
	}

	getGraph(); //print graph
} //End floyd
		
