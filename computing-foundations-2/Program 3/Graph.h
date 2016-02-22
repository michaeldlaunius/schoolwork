/* Michael Launius
* Schneider
* Program 3 - Graphs | Graph.h
* Graph Prototype
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "List.h"

class Graph
{
	public:
		Graph(int); 
		Graph();
		
		void create(); //create new graph
		void insert(); //given source, destination, and weight, inserts node into graph
		void remove(); //given source and destination, removes node from graph
		void print(); //prints graph: (node1,node2,weight)(...)(...)...
		
	private:
		List **arr;
		int numBuckets;
		
};
#endif