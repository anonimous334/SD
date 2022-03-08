#include <iostream>
#include "graf.h"
using namespace std;

int main(){

	int nrEdges, nrNodes;
	int src, dst;
	cin >> nrEdges >> nrNodes;
	Graph myGraph(nrEdges);

	for(int i = 0; i < nrEdges; i++){

		cin >> src >> dst;
		myGraph.add_edge(src, dst);
	}

	myGraph.DFS(0);

	return 0;
}
