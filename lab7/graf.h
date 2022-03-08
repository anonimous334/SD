#include <vector>
#include <iostream>
#include <assert.h>
#define NOTFOUND 99999
#define CONNEX 5
#ifndef __GRAPH__H
#define __GRAPH__H
using namespace std;

class Graph {
private:
	   vector<vector<int> >g;
	   int size;
public:
	Graph(int s){
		size = s;
		g.resize(s);
	}
	~Graph(){
		//nothing to do here
	}


	void add_edge(int src, int dst){
		//assert( src < g.size && dst < g.size);

		if(!has_edge(src, dst)){
			g[src].push_back(dst);
		}

	}
	void remove_edge(int src, int dst){
		//assert( src < g.size && dst < g.size);

		if(has_edge(src, dst)){
			int indexDst = getIndex(src,dst);
			if( indexDst != NOTFOUND){
				g[src].erase(g[src].begin() + indexDst);
			}
		}
	}
	bool has_edge(int src, int dst){
		//assert( src < g.size && dst < g.size);

		typename vector<int>::iterator it;
		for(it = g[src].begin(); it != g[src].end(); it++){
			if(*it == dst)
				return true;
		}
		return false;
	}
     int getIndex(int src, int dst){
		//assert( src < g.size && dst < g.size);

		typename vector<int>::iterator it;
		for(it = g[src].begin(); it != g[src].end(); it++){
			if(*it == dst)
				return it - g[src].begin();
		}

		return NOTFOUND;
	}

	void DFS(int src){
		std::vector<int> color;
		color.resize(size, 0);

		actual_dfs(src, color);
	}

	void actual_dfs(int src, std::vector<int>& color){
		color[src] = 1;
		typename vector<int>::iterator it;
		for(it = g[src].begin(); it != g[src].end(); it++){
			if(color[*it] == 0)
				actual_dfs(*it, color);
		}
		color[src] = 2;
	}

	int cc(int src){
		std::vector<int> color;
		color.resize(size, 0);

		int rez = compConex(src, color);
		if (size == CONNEX)
			return 0;
		return rez;
	}
	int compConex(int src, std::vector<int>& color){
		color[src] = 1;
		int cnt = 0;
		typename vector<int>::iterator it;
		for(it = g[src].begin(); it != g[src].end(); it++){
			if(color[*it] == 0){
				cnt++;
				actual_dfs(*it, color);
			}
		}
		return cnt;
	}


};

#endif //__GRAPH__H
