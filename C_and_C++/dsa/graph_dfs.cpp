#include <utility>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;

const int N = 1e5+10;

vector<int> graph[N]; // N vectors
bool visited[N];


void dfs(int vertex){
	// Take Action on vertex after entering the vertex
	std::cout << vertex << std::endl;
	visited[vertex] = true;
	for (int child : graph[vertex]) {
		// Take Action on child before entering the child node
		std::cout << "parent " << vertex << ", child " << child << std::endl;
		if(visited[child]) continue;
		dfs(child);
		// Take Action on child after exiting the child node
	}
	// Take Action on vertex before exiting the vertex
}

int32_t main(){

	// Adjency Matrix
	int n = 6, m = 9;
	int vexEd[9][9] = { {1,3, 4} , {1,5, 3} , {3,5, 2}, {3,4, 7}, {3,6, 8}, {3,2, 9}, {2,6, 1}, {4,6, 2}, {5,6, 3} };

	for (int i = 0; i < m; i++) {
		int v1 = vexEd[i][0];
		int v2 = vexEd[i][1];
		int wgt =vexEd[i][2];

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
		// O(V+E) - space complexity
	}

	dfs(1);

	return 0;
}

