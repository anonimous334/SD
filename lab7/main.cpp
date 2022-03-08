#include <iostream>
#include "graf.h"
using namespace std;

int main(){

	int n, m;
	int str, stp;
	int vizitat[100]={0};
	int* tempDFS;
	cin >> n >> m;
	Graph myGraph(n);
	for ( int i = 0; i < m; i++ ) {
		cin >> str >> stp;
		myGraph.add_edge(str,stp);
	}

	int nrCompConexe = 0;
	for ( int i = 0; i < n; i ++ ) {
		if( vizitat[i] == 0 ) {
			int tempRez = myGraph.cc(i);
			if(tempRez > 0)
				nrCompConexe += tempRez;
		}
	}
	cout << "Exista " << nrCompConexe + 1<< " componente conexe" << endl;
	return 0;
}
