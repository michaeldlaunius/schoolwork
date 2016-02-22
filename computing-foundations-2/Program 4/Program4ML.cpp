/* Michael Launius
* Schneider
* Program 4 - Shortest Paths
* Program4ML.cpp | Main implementation
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Graph.h"

using namespace std;

const bool DEBUG = false;

int main()
{
	string command = "default";
	Graph *graph = new Graph;
	
	while (command != "quit")
	{
		cout << "floyd> ";
		cin >> command;
		if(DEBUG) cout << "command: " << command << endl;
		
		if(command == "floyd")
		{
			if(DEBUG) cout << "IN main: command = floyd" << endl;
			graph->setGraph();
		}
		
		else if (command != "quit")
		{
			cout << "Error! Invalid command" << endl;
		}
	}
}
