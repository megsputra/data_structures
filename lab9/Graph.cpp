/**

 * Mega Putra

 * CIS 22C, Lab 9

 */
#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <assert.h>

using namespace std;

Graph::Graph(int n)
{
	adj.resize(n + 1); //since adj[0] is left deliberately empty
	vertices = n;
	edges = 0;
}

int Graph::getNumEdges()
{
	int sum = 0;
	for(int i = 0; i <= adj.size(); ++i){
		sum += adj[i].getLength();
	}
	return sum / 2;
}

int Graph::getNumVertices()
{
	return vertices;
}

bool Graph::isEmpty()
{
	return getNumVertices() == 0;
}

void Graph::addEdge(int u, int v)
{
	assert(u <= getNumVertices() && v <= getNumVertices());
	adj[u].insertEnd(v);
	adj[v].insertEnd(u);
}

void Graph::removeEdge(int u, int v)
{
	assert(u <= getNumVertices() && v <= getNumVertices());

	int index = 0;
	index = adj[u].linearSearch(v);
	if (index != -1)
	{
		adj[u].advanceToIndex(index);
		adj[u].deleteIterator();
	}
	else
		cerr<<"value to be removed is not found!"<<endl;

	index = adj[v].linearSearch(u);
	if (index != -1)
	{
		adj[v].advanceToIndex(index);
		adj[v].deleteIterator();
	}
	else
		cerr<<"value to be removed is not found!"<<endl;
}

void Graph::printGraph(ostream& output)
{
	for(int i = 1; i < adj.size(); i++)
	{
		 if(!adj[i].empty())
		 {
			 adj[i].beginIterator();
			 output << i << ": ";
			 adj[i].print(output);
		 }
		 else
			 output << i << ": ";
	}
}
