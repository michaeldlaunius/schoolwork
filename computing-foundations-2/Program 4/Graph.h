/* Michael Launius
* Schneider
* Program 4 - Shortest Paths
* Graph.h | Graph prototype
*/

#ifndef GRAPH_H
#define GRAPH_H

#define MAX 50
class Graph
{
	public:
		Graph(){}; //default constructor
		void setGraph();
		void getGraph();
		void floyd();
	
	private:
		int graph[MAX][MAX]; //hold graph up to MAX x MAX
		int size;
	
};

#endif
