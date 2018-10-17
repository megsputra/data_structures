/**

 * Mega Putra

 * CIS 22C, Lab 9

 */
#include "Graph.h"
#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
	Graph G(5);
	G.addEdge(3,2);
	G.addEdge(1,4);
	G.addEdge(1,3);
	G.addEdge(1,2);
	cout << "Should print that there are 4 edges: " << G.getNumEdges() << endl;
	cout << "Should print that there are 5 vertices: " << G.getNumVertices() << endl;
	cout << "Should print the graph is not empty: ";
	if(G.isEmpty())
		cout <<"The graph is empty"<< endl;
	else
		cout <<"The graph is not empty"<< endl;

	G.printGraph(cout);
	cout <<"\nAdding an edge between 4 and 2, now it should be printed 2: 3 1 5 and 5: 2" << endl;
	G.addEdge(5,2);
	G.printGraph(cout);
	cout << "Should print that there are 5 edges: " << G.getNumEdges() << endl;

	cout << "\nRemoving 1 and 2, graph is now:" << endl;
	G.removeEdge(1,2);
	G.printGraph(cout);
	cout << "Should print that there are 4 edges: " << G.getNumEdges() << endl;

	cout << "\n***Following functions will trigger assertion, comment out after testing"<<endl;
	G.addEdge(5,7);
	G.removeEdge(10,8);

	cout << "Should print that there are STILL 5 vertices: " << G.getNumVertices() << endl;

	return 0;
}
