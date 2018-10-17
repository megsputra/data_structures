/**

 * Mega Putra

 * CIS 22C, Lab 9

 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <cstdlib>
#include "List.h"
#include <vector>
using namespace std;

class Graph {
public:

/**Constructors and Destructors*/

 Graph(int n);
    //initializes an empty graph to have n vertices and no edges

/*** Access Functions ***/

int getNumEdges();
//returns the number of edges in the graph

int getNumVertices();
//returns the number of vertices in the graph

bool isEmpty();
//returns whether the graph is empty

/*** Manipulation Procedures ***/

void addEdge(int u, int v);
//Pre: u <= getNumVertices() && v <=getNumVertices()
//inserts vertex v into the adjacency list of vertex u (i.e. inserts v into the list at index u)
//and inserts u into v.

void removeEdge(int u, int v);
//Pre: u <= getNumVertices() && v <=getNumVertices()
//removes vertex v from the adjacency list of vertex u
//and removes u from v.
/*** Additional Operations ***/

void printGraph(ostream& output);
//Prints the adjacency list of each vertex in the graph,
//vertex: <space separated list of adjacent vertices>
//Prints to the console or to an output file given the ostream parameter

private:
	int vertices, edges; //number of edges and vertices
	vector<List<int> > adj;

};




#endif /* GRAPH_H_ */
