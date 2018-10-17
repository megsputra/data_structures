/**

 * Mega Putra

 * CIS 22C, Lab 9

 */

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void writeToFile(Graph &);

int main()
{
	ifstream fin;
	cout << "Welcome to WriteGraph!" << endl << endl;
	string fileName = "", buffer ="";
	cout << "Enter the name of the file containing the graph information: ";
	cin >> fileName;
	fin.open(fileName.c_str());
	while (!fin.is_open())
	{
		cout << "Invalid file name!\n";
		cout << "\nPlease enter the name of your file: ";
		cin >> fileName;
		fin.open(fileName.c_str());
	}
	cout << "\n***Reading from "<< fileName <<"***" << endl;
	int a, b = 0;
	fin>>a;
	Graph G(a);

	while(!fin.eof())
	{
		fin >> a >> b;
		G.addEdge(a, b);
	}
	fin.close();
		writeToFile(G);
}


void writeToFile(Graph& G)
{
	string fileName;

	cout << "\nPlease enter the name of the output file:";
	cin >> fileName;
	ofstream outFile(fileName.c_str());

	if (!outFile) cerr << "Error opening the output file!" << endl;

	G.printGraph(outFile);
	outFile << "\nTotal vertices: " << G.getNumVertices() << endl;
	outFile << "Total edges: " << G.getNumEdges();

	cout << "\nThank you! Your Graph is now written to " << fileName;
	outFile.close();
}

